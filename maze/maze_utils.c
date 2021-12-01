#include "maze.h"
#include <stdlib.h>

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

        // pop_Node에 현재 top노드의 주소 할당
        pop_Node = pStack->pTopElement;

        // pStack->pTop = NULL;

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
