#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

LinkedDeque *createLinkedDeque()
{
    LinkedDeque *pDeque;

    if (!(pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque))))
        return (NULL);
    pDeque->currentElementCount = 0;
    pDeque->pFrontNode = 0;
    pDeque->pRearNode = 0;
    return (pDeque);
}

int insertFrontLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return (FALSE);
    DequeNode *addNode;
    if (!(addNode = (DequeNode *)malloc(sizeof(DequeNode))))
        return (FALSE);
    *addNode = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = addNode;
        pDeque->pRearNode = addNode;
    }
    else
    {
        pDeque->pFrontNode->pLLink = addNode;
        addNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = addNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return (FALSE);
    DequeNode *addNode;
    if (!(addNode = (DequeNode *)malloc(sizeof(DequeNode))))
        return (FALSE);
    *addNode = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = addNode;
        pDeque->pRearNode = addNode;
    }
    else
    {
        pDeque->pRearNode->pRLink = addNode;
        addNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = addNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}
DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *delNode;

    delNode = pDeque->pFrontNode;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    delNode->pRLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pRearNode = NULL;
    }
    else
    {
        pDeque->pFrontNode->pLLink = NULL;
    }
    return (delNode);
}
DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    DequeNode *delNode;

    delNode = pDeque->pRearNode;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    delNode->pLLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = NULL;
    }
    else
    {
        pDeque->pRearNode->pRLink = NULL;
    }
    return (delNode);
}
DequeNode *peekFrontLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pFrontNode);
}
DequeNode *peekRearLD(LinkedDeque *pDeque)
{
    if (!pDeque || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pRearNode);
}
void deleteLinkedDeque(LinkedDeque *pDeque)
{
    if (!pDeque)
        return;
    DequeNode *tempNode;
    DequeNode *delNode;

    tempNode = pDeque->pFrontNode;
    while (tempNode)
    {
        delNode = tempNode;
        tempNode = tempNode->pRLink;
        free(delNode);
    }
    free(pDeque);
}

int isLinkedDequeFull(LinkedDeque *pDeque)
{
    return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque *pDeque)
{
    if (!pDeque)
        return (FALSE);
    if (pDeque->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

void displayDeque(LinkedDeque *pDeque)
{
    if (!pDeque)
        return;
    DequeNode *temp;
    int i = 0;

    temp = pDeque->pFrontNode;
    printf("pDeque size : %d\n", pDeque->currentElementCount);
    while (temp != NULL)
    {
        printf("{index: %d, data: %c}\n", i, temp->data);
        i++;
        temp = temp->pRLink;
    }
    return;
}

int main()
{
    LinkedDeque *pDeque;

    DequeNode *del;
    DequeNode node0 = {'a'};

    int number;
    pDeque = createLinkedDeque();
    while (1)
    {
        printf("1 : InsertFront\n2 : DeleteFront\n3 : Peek\n4 : Display\n5 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            insertFrontLD(pDeque, node0);
            displayDeque(pDeque);

            break;
        case 2:
            del = deleteFrontLD(pDeque);
            printf("%c has del!\n", del->data);
            free(del);
            displayDeque(pDeque);
            break;
        case 3:
            del = peekFrontLD(pDeque);
            printf("tada %c!\n", del->data);
            break;
        case 4:
            displayDeque(pDeque);
            break;
        case 5:
            deleteLinkedDeque(pDeque);
            break;
        default:
            break;
        }
    }
    return (0);
}