#include "arraystack.h"
#include <stdlib.h>

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
    if (!isArrayStackEmpty(pStack))
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
    free(pStack);
    return;
}

int isArrayStackFull(ArrayStack *pStack)
{
    if (pStack == NULL)
        return (FALSE);
    if (pStack->currentElementCount == pStack->maxElementCount)
        return (TRUE);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
    if (pStack == NULL)
        return (FALSE);
    if (pStack->currentElementCount == 0)
        return (TRUE);
}