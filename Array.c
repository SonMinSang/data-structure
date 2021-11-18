#include "Array.h"

ArrayList *createArrayList(int maxElementCount)
{
    ArrayList *al;
    if (maxElementCount > 0)
    {
        if (!(al = (ArrayList *)malloc(sizeof(ArrayList))))
            return (NULL);
        al->maxElementCount = maxElementCount;
        al->currentElementCount = 0;
        if (!(al->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount)))
        {
            free(al);
            return (NULL);
        }
        al->pElement = NULL;
        return (al);
    }
    return (NULL);
}
int deleteArrayList(ArrayList al, int index)
{
    if (al->currentElementCount > index)
    {
    }
}

int isArrayListFull(ArrayList al);
int removeAlElement(ArrayList al);
int displayArrayList(ArrayList al, int index);
clearArrayList(ArrayList al);
getArrayListLength(ArrayList al);
