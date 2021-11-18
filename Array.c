#include "Array.h"

ArrayList *createArrayList(int maxElementCount)
{
    ArrayList *al;
    if (maxElementCount > 0)
    {
        if (!(al = (ArrayList *)malloc(sizeof(ArrayList) * (maxElementCount + 1))))
            return (NULL);
        al->maxElementCount = maxElementCount;
        al->currentElementCount = 0;
        al->pElement = (ArrayListNode *)malloc);
    }
}
