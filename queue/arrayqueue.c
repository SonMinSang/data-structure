#include "arrayqueue.h"
#include <stdlib.h>
#include <stdio.h>

ArrayQueue *createArrayQueue(int maxElementCount)
{
    if (maxElementCount <= 0)
        return (NULL);
    ArrayQueue *pQueue;

    if (!(pQueue = (ArrayQueue *)malloc(sizeof(ArrayQueue))))
        return (NULL);
    pQueue->maxElementCount = maxElementCount;
    pQueue->currentElementCount = 0;
    pQueue->front = -1;
    pQueue->rear = -1;
    if (!(pQueue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount)))
    {
        free(pQueue);
        return (NULL);
    }
    return (pQueue);
}
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
    if (!pQueue || isArrayQueueFull(pQueue))
        return (FALSE);

    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue)
{
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    ArrayQueueNode *dequeue;

    if (!(dequeue = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode))))
        return (NULL);
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    *dequeue = pQueue->pElement[pQueue->front];
    pQueue->currentElementCount--;
    return (dequeue);
}
ArrayQueueNode *peekAQ(ArrayQueue *pQueue)
{
    if (!pQueue || isArrayQueueEmpty(pQueue))
        return (NULL);
    return (&(pQueue->pElement[pQueue->front + 1]));
}
void deleteArrayQueue(ArrayQueue *pQueue)
{
    if (!pQueue)
        return;
    if (!pQueue->pElement)
        free(pQueue->pElement);
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue *pQueue)
{
    if (!pQueue)
        return (FALSE);
    if (pQueue->currentElementCount == pQueue->maxElementCount)
        return (TRUE);
    return (FALSE);
}

int isArrayQueueEmpty(ArrayQueue *pQueue)
{
    if (!pQueue)
        return (FALSE);
    if (pQueue->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayArrayQueue(ArrayQueue *pQueue)
{

    if (!pQueue)
        return;

    printf("Queue max size : %d\n", pQueue->maxElementCount);
    printf("Queue size : %d\n", pQueue->currentElementCount);
    for (int i = pQueue->front; i < pQueue->front + pQueue->currentElementCount; i++)
    {
        printf("{index: %d, data: %c}\n", i - pQueue->front, pQueue->pElement[(i + 1) % pQueue->maxElementCount]);
    }
}

int main()
{
    ArrayQueue *pQueue;

    ArrayQueueNode *deQueue;
    ArrayQueueNode node0 = {'a'};

    int number;
    pQueue = createArrayQueue(3);
    while (1)
    {
        printf("1 : Enqueue\n2 : Dequeue\n3 : Peek\n4 : Display\n5 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            enqueueAQ(pQueue, node0);
            displayArrayQueue(pQueue);

            break;
        case 2:
            deQueue = dequeueAQ(pQueue);
            printf("%c has dequeue!\n", deQueue->data);
            free(deQueue);
            displayArrayQueue(pQueue);
            break;
        case 3:
            deQueue = peekAQ(pQueue);
            printf("tada %c!\n", deQueue->data);
            break;
        case 4:
            displayArrayQueue(pQueue);
            break;
        case 5:
            deleteArrayQueue(pQueue);
            break;
        default:
            break;
        }
    }
    return (0);
}

