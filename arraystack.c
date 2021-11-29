#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack *createArrayStack(int maxElementCount)
{
    if (maxElementCount <= 0)
        return (NULL);
    ArrayStack *stack;

    stack = (ArrayStack *)malloc(sizeof(ArrayStack));
    if (stack == NULL)
        return (NULL);
    stack->maxElementCount = maxElementCount;
    stack->currentElementCount = 0;
    stack->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
    if (!(stack->pElement))
    {
        free(stack);
        return (NULL);
    }
    return (stack);
}

int pushAS(ArrayStack *pStack, ArrayStackNode element)
{
    if (!pStack)
        return (FALSE);
    if (!isArrayStackFull(pStack))
    {
        pStack->pElement[pStack->currentElementCount] = element;
        pStack->currentElementCount++;
        return (TRUE);
    }
    return (FALSE);
}

ArrayStackNode *popAS(ArrayStack *pStack)
{
    ArrayStackNode *topNode;

    if (!pStack)
        return (NULL);
    if (isArrayStackEmpty(pStack) == 0)
    {
        topNode = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
        if (!topNode)
            return (NULL);
        *topNode = pStack->pElement[pStack->currentElementCount - 1];
        pStack->currentElementCount--;
        return (topNode);
    }
    return (NULL);
}
ArrayStackNode *peekAS(ArrayStack *pStack)
{
    ArrayStackNode *topNode;

    if (!pStack)
        return (NULL);
    if (!isArrayStackEmpty(pStack))
    {
        topNode = &(pStack->pElement[pStack->currentElementCount - 1]);
        return (topNode);
    }
    return (NULL);
}

void deleteArrayStack(ArrayStack *pStack)
{
    if (!pStack)
        return;
    while (!isArrayStackEmpty(pStack))
        popAS(pStack);
    free(pStack->pElement);
    free(pStack);
    return;
}

int isArrayStackFull(ArrayStack *pStack)
{
    if (pStack == NULL)
        return (FALSE);
    if (pStack->currentElementCount == pStack->maxElementCount)
        return (TRUE);
    return (FALSE);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
    if (!pStack)
        return (FALSE);
    if (pStack->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayArrayStack(ArrayStack *pStack)
{
    if (!pStack)
        return;
    printf("The max size of stack : %d\n", pStack->maxElementCount);
    printf("The max size of stack : %d\n", pStack->currentElementCount);
    for (int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("{index: %d, data: %c}\n", i, pStack->pElement[i].data);
    }
}

// int main()
// {
//     ArrayStack *pStack = NULL;

//     ArrayStackNode *temp = NULL;
//     ArrayStackNode *ppopp = NULL;

//     pStack = createArrayStack(100);
//     if (pStack != 0)
//     {
//         ArrayStackNode node1 = {'A'};
//         ArrayStackNode node2 = {'B'};
//         ArrayStackNode node3 = {'C'};

//         pushAS(pStack, node1);
//         pushAS(pStack, node2);
//         pushAS(pStack, node3);

//         printf("currentsize : %d\n", pStack->currentElementCount);

//         ppopp = popAS(pStack);
//         temp = peekAS(pStack);

//         displayArrayStack(pStack);

//         printf("returned peek data : %c\n", temp->data);
//         printf("returned pop data : %c\n", ppopp->data);

//         deleteArrayStack(pStack);
//         printf("%d\n", isArrayStackEmpty(pStack));

//         printf("after deleteLSfunc");
//         displayArrayStack(pStack);

//         return (0);
//     }
// }

int main()
{
    ArrayStack *myStack;

    ArrayStackNode *temp;
    ArrayStackNode node0 = {'a'};

    int number;
    myStack = createArrayStack(100);
    while (1)
    {
        printf("1 : Push\n2 : Pop\n3 : Peek\n4 : Display\n5 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            pushAS(myStack, node0);
            displayArrayStack(myStack);

            break;
        case 2:
            temp = popAS(myStack);
            printf("%c has popped out!\n", temp->data);
            displayArrayStack(myStack);
            break;
        case 3:
            temp = peekAS(myStack);
            printf("tada %c!\n", temp->data);
            break;
        case 4:
            displayArrayStack(myStack);
            break;
        case 5:
            deleteArrayStack(myStack);
            if (isArrayStackEmpty(myStack) == 1)
            {
                printf("successfuly deleted\n");
                printf("====================\n");
            }
            else
                printf("fail");
            break;
        default:
            break;
        }
    }
    return (0);
}