#include "arrayheap.h"
#include <stdlib.h>

ArrayHeap *createArrayHeap(int maxElementCount);
void insertHeapNode(ArrayHeap *pArrayHeap, HeapNode element)
{
    int nextpos;
    if (isFullArrayHeap(pArrayHeap))
    {
        printf("This heap is full");
        return;
    }
    nextpos = ++(pArrayHeap->currentElementCount); // 마지막 노드 다음 자리에 새로 넣을 element 위치 임시 저장
    while (nextpos != 1 && element.key < pArrayHeap->pElement[nextpos / 2].key)
    {
        pArrayHeap->pElement[nextpos] = pArrayHeap->pElement[nextpos / 2];
        nextpos /= 2;
    }
    pArrayHeap->pElement[nextpos] = element;
}
void deleteArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return;
    if (pArrayHeap->pElement)
        free(pArrayHeap->pElement);
    free(pArrayHeap);
}

int isFullArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (FALSE);
    if (pArrayHeap->currentElementCount == pArrayHeap->maxElementCount)
        return (TRUE);
    return (FALSE);
}
int isEmptyArrayHeap(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (FALSE);
    if (pArrayHeap->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}
HeapNode *deleteHeapNode(ArrayHeap *pArrayHeap)
{
    if (!pArrayHeap)
        return (NULL);
    if (isEmptyArrayHeap(pArrayHeap))
        return (NULL);
    int temp;
    int parent = 1;
    int child = 2;
    HeapNode *delNode;
    HeapNode *tempNode;

    if (!(delNode = (HeapNode *)malloc(sizeof(HeapNode))))
        return (NULL);
    *delNode = pArrayHeap->pElement[1];

    temp = pArrayHeap->currentElementCount--;
    tempNode = &(pArrayHeap->pElement[temp]);

    while (child <= pArrayHeap->currentElementCount)
    {
        if (child < pArrayHeap->currentElementCount && pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key)
            child++;
        if (tempNode->key >= pArrayHeap->pElement[child].key)
            break;
        pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pArrayHeap->pElement[parent] = *tempNode;
    return (delNode);
}