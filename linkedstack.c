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
        StackNode *topNode;
        topNode = pStack->pTopElement;
        pStack->pTopElement = topNode->pLink;
        free(topNode);
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
void displayLinkedStack(LinkedStack *pStack)
{
    StackNode *currentNode;
    int length;

    length = pStack->currentElementCount;
    if (pStack = NULL || length == 0)
    {
        printf("null");
        return;
    }
    printf("currentElementCount : %d", pStack->currentElementCount);
    currentNode = pStack->pTopElement;
    for (int i = 0; i < length; i++)
    {
        printf("{%d, %d}", length - i, currentNode->data);
        currentNode = currentNode->pLink;
    }
}

int main (void)
{
    
}