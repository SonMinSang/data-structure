#include "arrayqueue.c"
#include <stdlib.h>

ArrayQueue* createArrayQueue(int maxElementCount)
{
    if (maxElementCount <= 0)
        return (NULL);
    ArrayQueue *pQueue;

    if (!(pQueue = (ArrayQueue*)malloc(sizeof(ArrayQueue)))
        return (NULL);
    pQueue->maxElementCount = maxElementCount;
    pQueue->currentElementCount = 0;
    pQueue->front = -1;
    pQueue->rear = -1;
    if (!(pQueue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount))
    {
        free(pQueue);
        return (NULL);
    }
    pQueue = 0;
    return (pQueue);
}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (!pQueue || isArrayQueueFull(pQueue))
        return (FALSE);
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    ArrayQueueNode *dequeue;

    if (!(dequeue = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode))
        return (NULL); 
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    *dequeue = pQueue->pElement[pQueue->front];
    pQueue->currentElementCount--;
    return (dequeue);
}
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    return (&(pQueue->pElement[ pQueue->front + 1]));
}
void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (!pQueue)
        return;
    if (!pQueue->pElement)
        free(pQueue->pElement);
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
    if (!pQueue)
        return (FALSE);
    if (pQueue->currentElementCount == pQueue->maxElementCount || pQueue->rear == maxElement - 1)
        return (TRUE);
    return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (!pQueue)
        return (FALSE);
    if (pQueue->currentElementCount == 0)
        return (TRUE);
}