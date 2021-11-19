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
int deleteArrayList(ArrayList *pList)
{

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

int addALElement(ArrayList *pList, int position, ArrayListNode element);
{
    if (isArrayListFull(pList))
        return (FALSE);
    else if (position > pList->currentElementCount)
    {
        printf("not valid position");
        return (FALSE);
    }
    else 
    for (int i = position; i < pList->currentElementCount)
}

int removeALElement(ArrayList *pList, int position);
ArrayListNode *getALElement(ArrayList *pList, int position);
void displayArrayList(ArrayList *pList);
void clearArrayList(ArrayList *pList);
int getArrayListLength(ArrayList *pList);
