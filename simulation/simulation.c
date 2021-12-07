#include "simdef.h"
#include "simutil.h"
#include "linkedqueue.h"
#include <stdlib.h>
#include <stdio.h>

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue)
{
    if (!pQueue)
        return;
    QueueNode node = {arrival, arrivalTime, processTime, 0, 0};
    enqueueLQ(pQueue, node);
}

void processArrival(int currentTime, LinkedQueue *arrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode *temp;

    while (!isLinkedQueueEmpty(arrivalQueue))
    {
        temp = peekLQ(arrivalQueue);
        if (temp->data.arrivalTime == currentTime)
        {
            enqueueLQ(pWaitQueue, *temp);
            printSimCustomer(currentTime, temp->data);
            temp = dequeueLQ(arrivalQueue);
            free(temp);
        }
        else
            return;
    }
}

// 서비스 시작 처리.
QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    if (!pWaitQueue || isLinkedQueueEmpty(pWaitQueue))
        return (NULL);
    QueueNode *temp;

    temp = dequeueLQ(pWaitQueue);
    temp->data.status = start;
    temp->data.startTime = currentTime;
    printSimCustomer(currentTime, temp->data);
    return (temp);
}

// 서비스 종료 처리.
QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    if (!pServiceNode || !pServiceUserCount || !pTotalWaitTime)
        return (NULL);
    if (pServiceNode->data.startTime + pServiceNode->data.serviceTime <= currentTime)
    {
        (*pServiceUserCount)++;
        (*pTotalWaitTime) += (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);

        pServiceNode->data.status = end;
        pServiceNode->data.endTime = currentTime;
        printSimCustomer(currentTime, pServiceNode->data);

        free(pServiceNode);
        return (NULL);
    }
    return (pServiceNode);
}

// 대기 열의 상태를 출력.
void printWaitQueueStatus(int currentTime, LinkedQueue *waitQueue)
{
    printf("current %d, %d is waiting \n", currentTime, waitQueue->currentElementCount);
}

// 고객의 상태를 출력.
void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("----------------------------");
    printf("currentTime %d \n", currentTime);
    if (customer.status == arrival)
    {
        printf("arrival\n");
        printf("arrived at %d and waiting\n", customer.arrivalTime);
    }
    else if (customer.status == start)
    {
        printf("start\n");
        printf("arrvided at %d, start service at %d and waited for %d\n", customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime);
    }
    else if (customer.status == end)
    {
        printf("end\n");
        printf("arrvided at %d, start service at %d, waited for %d and get the service for %d\n", customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime, customer.endTime - customer.startTime);
    }
}

// 최종 시뮬레이션 결과(통계치) 출력.
void printReport(LinkedQueue *waitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("The number of customer : %d\n", serviceUserCount);
    if (serviceUserCount > 0)
        printf("average waiting time : %f \n", (double)totalWaitTime / (double)serviceUserCount);
}

int main()
{
    int serviceUserCount = 0;
    int totalWaitTime = 0;

    LinkedQueue *arrivalQueue = NULL, *waitQueue = NULL;
    QueueNode *serviceNode = NULL;

    arrivalQueue = createLinkedQueue();
    waitQueue = createLinkedQueue();
    insertCutomer(0, 2, arrivalQueue);
    insertCutomer(1, 2, arrivalQueue);
    insertCutomer(2, 1, arrivalQueue);
    insertCutomer(2, 2, arrivalQueue);
    insertCutomer(2, 3, arrivalQueue);
    insertCutomer(3, 1, arrivalQueue);
    insertCutomer(4, 5, arrivalQueue);
    insertCutomer(5, 1, arrivalQueue);
    insertCutomer(6, 3, arrivalQueue);
    insertCutomer(7, 2, arrivalQueue);

    for (int currentTime = 0; currentTime < 10; currentTime++)
    {
        processArrival(currentTime, arrivalQueue, waitQueue);
        if (serviceNode)
            serviceNode = processServiceNodeEnd(currentTime, serviceNode, &serviceUserCount, &totalWaitTime);
        if (!serviceNode)
            serviceNode = processServiceNodeStart(currentTime, waitQueue);
        printWaitQueueStatus(currentTime, waitQueue);
    }
    printReport(waitQueue, serviceUserCount, totalWaitTime);
    if (!serviceNode)
        free(serviceNode);
    deleteLinkedQueue(arrivalQueue);
    deleteLinkedQueue(waitQueue);
}