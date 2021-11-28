#include "linkedstack.h"
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
        StackNode *topNode;
        topNode = pStack->pTopElement;
        pStack->pTopElement = topNode->pLink;
        topNode = NULL;
        pStack->currentElementCount--;
        return (pStack->pTopElement);
    }
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
}