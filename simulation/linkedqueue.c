#include "linkedqueue.h"
#include <stdlib.h>
#include <stdio.h>

LinkedQueue *createLinkedQueue()
{
    LinkedQueue *pQueue;

    if (!(pQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue))))
        return (NULL);
    pQueue->currentElementCount = 0;
    pQueue->pFrontNode = 0;
    pQueue->pRearNode = 0;

    return (pQueue);
}
int enqueueLQ(LinkedQueue *pQueue, QueueNode element)
{
    if (!pQueue)
        return (FALSE);

    QueueNode *addNode;

    if (!(addNode = (QueueNode *)malloc(sizeof(QueueNode))))
        return (FALSE);
    *addNode = element;
    addNode->pLink = NULL;
    if (isLinkedQueueEmpty(pQueue))
    {
        pQueue->pFrontNode = addNode;
        pQueue->pRearNode = addNode;
    }
    else
    {
        pQueue->pRearNode->pLink = addNode;
        pQueue->pRearNode = addNode;
    }
    pQueue->currentElementCount++;
    return (TRUE);
}
QueueNode *dequeueLQ(LinkedQueue *pQueue)
{
    if (!pQueue || isLinkedQueueEmpty(pQueue))
        return (NULL);
    QueueNode *node;

    node = pQueue->pFrontNode;
    pQueue->pFrontNode = pQueue->pFrontNode->pLink;
    node->pLink = NULL;
    pQueue->currentElementCount--;
    if (isLinkedQueueEmpty(pQueue))
        pQueue->pRearNode = NULL;
    return (node);
}

QueueNode *peekLQ(LinkedQueue *pQueue)
{
    if (!pQueue || isLinkedQueueEmpty(pQueue))
        return (NULL);
    return (pQueue->pFrontNode);
}
void deleteLinkedQueue(LinkedQueue *pQueue)
{
    if (!pQueue)
        return;
    QueueNode *temp;
    while (!isLinkedQueueEmpty(pQueue))
    {
        dequeueLQ(pQueue);
        temp = dequeueLQ(pQueue);
        free(temp);
    }
    free(pQueue);
}
int isLinkedQueueFull(LinkedQueue *pQueue)
{
    return (FALSE);
}
int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
    if (!pQueue)
        return (FALSE);
    if (pQueue->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}
void displayLinkedQueue(LinkedQueue *pQueue)
{
    if (!pQueue)
        return;
    QueueNode *temp;
    int i = 0;

    temp = pQueue->pFrontNode;
    printf("pQueue size : %d\n", pQueue->currentElementCount);
    while (temp != NULL)
    {
        printf("{index: %d, data: %c}\n", i, temp->data);
        i++;
        temp = temp->pLink;
    }
    return;
}

void execute()
{
    LinkedQueue *pQueue;

    QueueNode *del;
    QueueNode node0;

    int number;
    pQueue = createLinkedQueue();
    while (1)
    {
        printf("1 : EnQueue\n2 : Dequeue\n3 : Peek\n4 : Display\n5 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            enqueueLQ(pQueue, node0);
            displayLinkedQueue(pQueue);

            break;
        case 2:
            del = dequeueLQ(pQueue);
            printf("%c has del!\n", del->data);
            free(del);
            displayLinkedQueue(pQueue);
            break;
        case 3:
            del = peekLQ(pQueue);
            printf("tada %c!\n", del->data);
            break;
        case 4:
            displayLinkedQueue(pQueue);
            break;
        case 5:
            deleteLinkedQueue(pQueue);
            return;
        default:
            break;
        }
    }
    return;
}
int main(void)
{
    execute();
    system("leaks linkedqueue.exe");
}