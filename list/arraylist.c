#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList *createArrayList(int maxElementCount)
{
    ArrayList *pList;
    if (maxElementCount > 0)
    {
        if (!(pList = (ArrayList *)malloc(sizeof(ArrayList))))
            return (NULL);
        pList->maxElementCount = maxElementCount;
        pList->currentElementCount = 0;
        if (!(pList->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount)))
        {
            free(pList);
            return (NULL);
        }
        pList->pElement = NULL;
        return (pList);
    }
    return (NULL);
}

void deleteArrayList(ArrayList *pList)
{
    if (pList == NULL)
        printf("null");
    else
    {
        free(pList->pElement);
        free(pList);
    }
}

int isArrayListFull(ArrayList *pList)
{
    if (pList->currentElementCount >= pList->maxElementCount)
    {
        printf("Full");
        return (TRUE);
    }
    printf("spare");
    return (FALSE);
}

int addALElement(ArrayList *pList, int position, ArrayListNode element)
{
    if (isArrayListFull(pList))
        return (FALSE);
    else if (position > pList->currentElementCount || position < 0)
    {
        printf("not valid position");
        return (FALSE);
    }
    else
    {
        for (int i = pList->currentElementCount; i > position; i--)
            pList->pElement[i + 1] = pList->pElement[i];
        pList->pElement[position] = element;
        pList->currentElementCount++;
        return (TRUE);
    }
}

int removeALElement(ArrayList *pList, int position)
{
    if (position > pList->currentElementCount || position < 0)
    {
        printf("not valid position");
        return (FALSE);
    }
    else
    {
        for (int i = position; i < pList->currentElementCount; i++)
            pList->pElement[i] = pList->pElement[i + 1];
        pList->currentElementCount--;
        return (TRUE);
    }
}

ArrayListNode *getALElement(ArrayList *pList, int position)
{
    ArrayListNode *Element;
    if (position < 0 || position > pList->currentElementCount)
    {
        printf("not valid postion");
        return (NULL);
    }
    Element = (ArrayListNode *)malloc(sizeof(ArrayListNode));
    if (!Element)
        return (NULL);
    Element = &(pList->pElement[position]);
    return (Element);
}

void displayArrayList(ArrayList *pList)
{
    if (pList == NULL)
        printf("null");
    else
    {
        printf("The length of arraylist: %d,\nthe max length of arraylist: %d ", pList->currentElementCount, pList->maxElementCount);
        for (int i = 0; i < pList->currentElementCount; i++)
            printf("{%d: %d}", i, getALElement(pList, i)->data);
    }
}

void clearArrayList(ArrayList *pList)
{
    if (pList == NULL)
        printf("null");
    else
        pList->currentElementCount = 0;

}

int getArrayListLength(ArrayList *pList)
{
    if (pList == NULL)
    {
        printf("null");
        return (FALSE);
    }
    else
        return (pList->currentElementCount);
}


