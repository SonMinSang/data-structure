#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

DoublyList *createDoublyList()
{
    DoublyList *pList;

    pList = (DoublyList *)malloc(sizeof(DoublyList));
    if (!pList)
        return NULL;
    pList->currentElementCount = 0;
    pList->headerNode.pLLink = &(pList->headerNode);
    pList->headerNode.pRLink = &(pList->headerNode);
    return pList;
}

void deleteDoublyList(DoublyList *pList)
{
    if (!pList)
        return;
    clearDoublyList(pList);
    free(pList);
}
int addCLElement(DoublyList *pList, int position, DoublyListNode element)
{
    DoublyListNode *preNode;
    DoublyListNode *newNode;

    newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    if (pList = NULL)
    {
        printf("null");
        return (FALSE);
    }
    if (position < 0 || position > pList->currentElementCount)
    {
        printf("not valid postion");
        return (FALSE);
    }
    if (!newNode)
        return (FALSE);
    *newNode = element;
    preNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        preNode = preNode->pRLink;
    newNode->pLLink = preNode;
    newNode->pRLink = preNode->pRLink;
    preNode->pRLink = newNode;
    newNode->pRLink->pLLink = newNode;
    pList->currentElementCount++;
    return (TRUE);
}

int removeDLElement(DoublyList *pList, int position)
{
    DoublyListNode *preNode;
    DoublyListNode *delNode;
    if (pList = NULL)
    {
        printf("null");
        return (FALSE);
    }
    if (position < 0 || position >= pList->currentElementCount)
    {
        printf("not valid postion");
        return (FALSE);
    }
    preNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        preNode = preNode->pRLink;
    delNode = preNode->pRLink;
    preNode->pRLink = delNode->pRLink;
    delNode->pRLink->pLLink = preNode;
    free(delNode);
    pList->currentElementCount--;
    return (TRUE);
}

void clearDoublyList(DoublyList *pList)
{
    if (pList)
    {
        while (pList->currentElementCount != 0)
            removeDLElement(pList, 0);
    }
}
int getDoublyListLength(DoublyList *pList)
{
    if (!pList)
    {
        printf("null");
        return (FALSE);
    }
    return (pList->currentElementCount);
}
DoublyListNode *getDLElement(DoublyList *pList, int position)
{
    DoublyListNode *currentNode;
    if (pList = NULL)
    {
        printf("null");
        return (NULL);
    }
    if (position < 0 || position >= pList->currentElementCount)
    {
        printf("not valid postion");
        return (NULL);
    }

    currentNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        currentNode = currentNode->pRLink;
    return (currentNode);
}
void displayDoublyList(DoublyList *pList)
{
    DoublyListNode *currentNode;
    int length;

    length = pList->currentElementCount;
    if (pList = NULL || length == 0)
    {
        printf("null");
        return;
    }
    printf("currentElementCount : %d", pList->currentElementCount);
    currentNode = &(pList->headerNode);
    for (int i = 0; i < length; i++)
    {
        currentNode = currentNode->pRLink;
        printf("{%d, %d}", i, currentNode->data);
    }
}