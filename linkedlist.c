#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList *createLinkedList()
{
    LinkedList *pList;

    pList = (LinkedList *)malloc(sizeof(LinkedList));
    if (!pList)
        return NULL;
    return pList;
}

int addLLElement(LinkedList *pList, int position, ListNode element)
{
}

int removeLLElement(LinkedList *pList, int position)
{
}

ListNode *getLLElement(LinkedList *pList, int position)
{
}

void clearLinkedList(LinkedList *pList)
{
}

int getLinkedListLength(LinkedList *pList)
{
}

void deleteLinkedList(LinkedList *pList)
{
}
