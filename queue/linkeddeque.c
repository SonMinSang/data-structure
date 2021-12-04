#include "arrayqueue.c"
#include <stdlib.h>

LinkedDeque *createLinkedDeque()
{
    LinkeDeque *pDeque;

    if (!(pDeque = (LinkedQueue)malloc(sizeof(LinkedQueue))))
        return (NULL);
    pDeque->currentElementCount = 0;
    pDeque->pFrontNode = 0;
    pDeque->pRearNode = 0;
    return (pDeque);
}
int insertFrontLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return (FALSE);
    DequeNode *addNode;
    if (!(addNode = (DequeNode *)malloc(sizeof(DequeNode))))
        return (FALSE);
    *addNode = pDeque;
    if (isLinkedDequeEmpty(addNode))
    {
        pDeque->pFrontNode = addNode;
        pDeque->pRearNode = addNode;
    }
    else
    {
        pDeque->pFrontNode->pLLink = addNode;
        addNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = addNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return (FALSE);
    DequeNode *addNode;
    if (!(addNode = (DequeNode *)malloc(sizeof(DequeNode))))
        return (FALSE);
    *addNode = pDeque;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = addNode;
        pDeque->pRearNode = addNode;
    }
    else
    {
        pDeque->pRearNode->pRLink = addNode;
        addNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = addNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *delNode;

    delNode = pDeque->pFrontNode;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    delNode->pRLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pRearNode = NULL;
    }
    else
    {
        pDeque->pFrontNode->pLLink = NULL;
    }
    return (delNode);
}
DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *delNode;

    delNode = pDeque->pRearNode;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    delNode->pLLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = NULL;
    }
    else
    {
        pDeque->pRearNode->pRLink = NULL;
    }
    return (delNode);
}
DequeNode *peekFrontLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pFrontNode);
}
DequeNode *peekRearLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pRearNode);
}
void deleteLinkedDeque(LinkedDeque *pDeque)
{
    if (!pDeque)
        return;
    DequeNode *tempNode;
    DequeNode *delNode;

    tempNode = pDeque->pFrontNode;
    while (tempNode)
    {
        delNode = tempNode;
        tempNode = tempNode->pRLink;
        free(delNode);
    }
    free(pDeque);
}

int isLinkedDequeFull(LinkedDeque *pDeque)
{
    return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque *pDeque)
{
    if (!pDeque)
        return (FALSE);
    if (pDeque->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}