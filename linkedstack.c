#include "linkedstack.h"
#include <stdlib.h>
#include <stdio.h>

LinkedStack *createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (!stack)
        return (NULL);
    stack->currentElementCount = 0;
    stack->pTopElement = NULL;
    return (stack);
}
int pushLS(LinkedStack *pStack, StackNode element)
{
    if (!pStack)
        return (FALSE);
    StackNode *topNode;

    topNode = (StackNode *)malloc(sizeof(StackNode));
    if (!topNode)
        return (FALSE);
    *topNode = element;
    topNode->pLink = pStack->pTopElement;
    pStack->pTopElement = topNode;
    pStack->currentElementCount++;
    return (TRUE);
}

StackNode *popLS(LinkedStack *pStack)
{
    if (!pStack)
        return (FALSE);
    if (!isLinkedStackEmpty(pStack))
    {
        //반환할 pop 노드의 주소를 담을 그릇 생성
        StackNode *pop_Node;

        //pop_Node에 현재 top노드의 주소 할당
        pop_Node = pStack->pTopElement;

        //pStack->pTop = NULL;

        //기존 두번째 노드와 헤드 연결 -> top 교체
        pStack->pTopElement = pop_Node->pLink;
        pStack->currentElementCount--;

        return (pop_Node);
    }
    else
        return (NULL);
}

StackNode *peekLS(LinkedStack *pStack)
{
    if (!pStack)
        return (FALSE);
    if (!isLinkedStackEmpty(pStack))
        return (pStack->pTopElement);
    return (NULL);
}
void deleteLinkedStack(LinkedStack *pStack)
{
    if (!pStack)
        return;
    while (!isLinkedStackEmpty)
        popLS(pStack);
    free(pStack);
    return;
}

int isLinkedStackFull(LinkedStack *pStack)
{
    //??
}
int isLinkedStackEmpty(LinkedStack *pStack)
{
    if (pStack == NULL)
        return (FALSE);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayLinkedStack(LinkedStack *pStack)
{
    //현재 사이즈와 인덱스에 따른 데이터값 출력하는 함수

    //예외 처리
    if (!pStack)
        return;
    StackNode *curr; //순회용 포인터 생성
    int idx = pStack->currentElementCount - 1;

    curr = pStack->pTopElement;
    printf("stack size : %d\n", pStack->currentElementCount);
    while (curr)
    {
        printf("{index: %d, data: %c}\n", idx, curr->data);
        curr = curr->pLink;
        idx--;
    }
}

int main()
{
    LinkedStack *pStack = NULL;

    StackNode *temp = NULL;
    StackNode *ppopp = NULL;

    pStack = createLinkedStack();
    if (pStack != 0)
    {
        StackNode node1 = {'a', 0};
        StackNode node2 = {'b', 0};
        StackNode node3 = {'c', 0};

        pushLS(pStack, node1);
        pushLS(pStack, node2);
        pushLS(pStack, node3);

        printf("currentsize : %d", pStack->currentElementCount);

        ppopp = popLS(pStack);
        temp = peekLS(pStack);

        displayLinkedStack(pStack);

        printf("returned peek data : %c\n", temp->data);
        printf("returned pop data : %c\n", ppopp->data);

        deleteLinkedStack(pStack);
        printf("%d\n", isLinkedStackEmpty(pStack));

        printf("after deleteLSfunc");
        return (0);
    }
}