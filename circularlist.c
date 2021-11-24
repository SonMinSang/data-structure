#include "circularlist.h"
#include <stdlib.h>
#include <stdio.h>

CircularList *createCircularList()
{
    CircularList *pList;

    pList = (CircularList *)malloc(sizeof(CircularList));
    if (!pList)
        return NULL;
    pList->currentElementCount = 0;
    pList->pLink = NULL;
    return pList;
}

void deleteCircularList(CircularList *pList);
int addCLElement(CircularList *pList, int position, CircularListNode element)
{
    CircularListNode *preNode;
    CircularListNode *newNode;
    CircularListNode *lastNode;

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
    *newNode = element;
    if (position == 0)
    {
        if (pList->currentElementCount == 0)
        {
            pList->pLink = newNode;
            newNode->pLink = newNode;
        }
        else
        {
            lastNode = pList->pLink;
            while (lastNode->pLink != pList->pLink)
                lastNode = lastNode->pLink;
            newNode->pLink = pList->pLink;
            newNode = pList->pLink;
            lastNode->pLink = newNode;
        }
    }
    else
    {
        preNode = pList->pLink;
        for (int i = 0; i < position - 1; i++)
            preNode = preNode->pLink;
        newNode->pLink = preNode->pLink;
        preNode->pLink = newNode;
    }
    pList->currentElementCount++;
    return (TRUE);
}

int removeCLElement(CircularList *pList, int position)
{
    CircularListNode *preNode;
    CircularListNode *delNode;
    CircularListNode *lastNode;

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
    if (position == 0)
    {
        if (pList->currentElementCount == 1)
        {
            pList->pLink = delNode;
            free(delNode);
            pList->pLink = NULL;
        }
        else
        {
            lastNode = pList->pLink;
            while (lastNode->pLink != pList->pLink)
                lastNode = lastNode->pLink;
            delNode = pList->pLink;
            lastNode->pLink = delNode->pLink;
            free(delNode);
        }
    }
    else
    {
        preNode = pList->pLink;
        for (int i = 0; i < position - 1; i++)
            preNode = preNode->pLink;
        delNode = preNode->pLink;
        preNode->pLink = delNode->pLink;
        free(delNode);
    }
    pList->currentElementCount--;
    return (TRUE);
}

void clearCircularList(CircularList *pList)
{
    if (pList)
    {
        while (pList->currentElementCount != 0)
            removeCLElement(pList, 0);
    }
}
int getCircularListLength(CircularList *pList)
{
    if (!pList)
    {
        printf("null");
        return (FALSE);
    }
    return (pList->currentElementCount);
}
CircularListNode *getCLElement(CircularList *pList, int position)
{
    CircularListNode *currentNode;
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

    currentNode = pList->pLink;
    for (int i = 0; i < position; i++)
        currentNode = currentNode->pLink;
    return (currentNode);
}
void displayCircularList(CircularList *pList)
{
    CircularListNode *currentNode;
    int length;

    length = pList->currentElementCount;
    if (pList = NULL || length == 0)
    {
        printf("null");
        return;
    }
    printf("currentElementCount : %d", pList->currentElementCount);
    currentNode = pList->pLink;
    for (int i = 0; i < length; i++)
    {
        printf("{%d, %d}", i, currentNode->data);
        currentNode = currentNode->pLink;
    }
}