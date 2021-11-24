#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList *createLinkedList()
{
    LinkedList *pList;

    pList = (LinkedList *)malloc(sizeof(LinkedList));
    if (!pList)
        return NULL;
    pList->currentElementCount = 0;
    // pList->headerNode = NULL;
    return pList;
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
    ListNode *currentNode;
    ListNode *addNode;
    if (!pList)
    {
        printf("null");
        return (FALSE);
    }
    if (position < 0 || position > pList->currentElementCount)
    {
        printf("not valid position");
        return (FALSE);
    }
    if (!(addNode = (ListNode *)malloc(sizeof(ListNode))))
        return (FALSE);
    *addNode = element;
    currentNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        currentNode = currentNode->pLink;
    addNode->pLink = currentNode->pLink;
    currentNode->pLink = addNode;
    pList->currentElementCount++;
    return (TRUE);
}

int removeLLElement(LinkedList *pList, int position)
{
    ListNode *currentNode;
    ListNode *deleteNode;
    if (!pList)
    {
        printf("null");
        return (FALSE);
    }
    if (position < 0 || position > pList->currentElementCount)
    {

        printf("not valid position");
        return (FALSE);
    }
    currentNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        currentNode = currentNode->pLink;
    deleteNode = currentNode->pLink;
    currentNode->pLink = deleteNode->pLink;
    free(deleteNode);
    pList->currentElementCount--;
    return (TRUE);
}

ListNode *getLLElement(LinkedList *pList, int position)
{
    ListNode *currentNode;
    if (!pList)
    {
        printf("null");
        return (NULL);
    }
    if (position < 0 || position > pList->currentElementCount)
    {

        printf("not valid position");
        return (NULL);
    }
    currentNode = &(pList->headerNode);
    for (int i = 0; i < position; i++)
        currentNode = currentNode->pLink;
    return (currentNode);
}

void clearLinkedList(LinkedList *pList)
{
    if (pList != NULL)
    {
        while (pList->currentElementCount > 0)
            removeLLElement(pList, 0);
    }
}

int getLinkedListLength(LinkedList *pList)
{
    if (!pList)
    {
        printf("null");
        return (FALSE);
    }
    return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList *pList)
{
    if (!pList)
    {
        printf("null");
        return;
    }
    if (pList->currentElementCount > 0)
    {
        return;
    }
    ListNode *currentNode;
    ListNode *deleteNode;
    int deletetimes = pList->currentElementCount;
    currentNode = &(pList->headerNode);
    for (int i = 0; i < deletetimes; i++)
    {
        deleteNode = currentNode->pLink;
        currentNode->pLink = deleteNode->pLink;
        if (!deleteNode)
            free(deleteNode);
        pList->currentElementCount--;
        if (currentNode != NULL)
            free(currentNode);
    }
    return;
}

int main(void)
{
    LinkedList *pList = NULL;
    ListNode node = {node.data = 0, node.pLink = NULL};

    // Dynamic Memory allocation
    pList = createLinkedList();
    if (pList == NULL)
        return -1;

    node.data = 1;
    addLLElement(pList, 0, node);
    node.data = 3;
    addLLElement(pList, 1, node);
    node.data = 5;
    addLLElement(pList, 2, node);
    return 0;
}