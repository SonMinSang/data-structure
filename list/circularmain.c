#include "circularlist1.h"

CircularList*	createCircularList()		// Circularlist ����
{
	CircularList* circularlist;

	circularlist = (CircularList*)malloc(sizeof(CircularList));
	if (circularlist == NULL)
		return (NULL);
	circularlist->currentElementCount = 0;
	circularlist->headerNode.pLink = NULL;
	return (circularlist);
}


/**
 * 0 1 2 3 4 (curr: 5)
 * position (5)
 *
 */
int	addCLElement(CircularList* pList, int position, CircularNode element)		// ��� �߰�
{
	CircularNode	*curr;
	CircularNode	*addNode;
	CircularNode	*last;
	int				i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	addNode = (CircularNode *)malloc(sizeof(CircularNode));
	if (addNode == NULL)
		return (FALSE);
	addNode->data = element.data;
	if (position == 0)	// node�� ������ ù���� ��忡 �߰�
	{
		addNode->pLink = pList->headerNode.pLink;	// �߰��Ǵ� ��尡 ù��° ��带 ����Ű��
		pList->headerNode.pLink = addNode;			// �����尡 �߰��Ǵ� ��带 ����Ű��
		pList->currentElementCount++;
		last = getLastCLElement(pList);
		last->pLink = addNode;
	}
	else
	{
		curr = getCLElement(pList, position - 1);
		addNode->pLink = curr->pLink;
		curr->pLink = addNode;
		pList->currentElementCount++;
	}
	return (TRUE);
}

int	removeCLElement(CircularList* pList, int position)		// ��� ����
{
	CircularNode	*curr;
	CircularNode	*temp;
	CircularNode	*last;
	int				i;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	curr = pList->headerNode.pLink;
	if (position == 0)
	{
		temp = curr;
		if (pList->currentElementCount == 1)
			pList->headerNode.pLink = NULL;
		else
		{
			last = getLastCLElement(pList);
			last->pLink = curr->pLink;
			pList->headerNode.pLink = curr->pLink;
		}
	}
	else
	{
		curr = getCLElement(pList, position - 1);
		temp = curr->pLink;
		curr->pLink = curr->pLink->pLink;
	}
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);

}

CircularNode*	getCLElement(CircularList* pList, int position)		// ��� ��������
{
	int				i;
	CircularNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pLink;
	for (i = 0; i < position; i++)
		curr = curr->pLink;
	return (curr);
}

void	clearCircularList(CircularList* pList)		// Circularlist �ʱ�ȭ
{
	CircularNode	*curr;
	CircularNode	*next;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	while (pList->currentElementCount)
	{
		next = curr->pLink;
		free(curr);
		curr = next;
		pList->currentElementCount--;
	}
	pList->headerNode.pLink = NULL;

}

int	getCircularListLength(CircularList* pList)		// Circularlist ����� ���� Ȯ��
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteCircularList(CircularList* pList)		// Circularlist free
{
	if (pList == NULL)
		return ;
	clearCircularList(pList);
	free(pList);
	pList = NULL;
}


CircularNode*	getLastCLElement(CircularList* pList)
{
	return (getCLElement(pList, pList->currentElementCount - 1));
}

void	displayCircularList(CircularList *pList)
{
	CircularNode	*curr;
	int	i;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pLink;
	if (!curr)
		printf("empty list");
	else{
		for (i = 0; i < pList->currentElementCount; i++)
		{
			printf("%d: %c\n", i % pList->currentElementCount, curr->data);
			curr = curr->pLink;
		}
	}
	printf("\n");
}

int main()
{
    CircularList *pList;

    CircularNode *temp;
    CircularNode node0 = {'a'};

    int number, position;
    pList = createCircularList();
    while (1)
    {
        printf("1 : Add\n2 : Remove\n3 : Get\n4 : Clear\n5 : Display\n6 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("{data, position} : \n");
            getchar();
            scanf("%c %d", &node0.data, &position);
            addCLElement(pList, position, node0);
            displayCircularList(pList);

            break;
        case 2:
            printf("position : \n");
            scanf("%d", &position);
            removeCLElement(pList, position);
            displayCircularList(pList);
            break;
        case 3:
            printf("position : \n");
            scanf("%d", &position);
            temp = getCLElement(pList, position);;
            printf("%c!\n", temp->data);
            break;
        case 4:
            clearCircularList(pList);
            displayCircularList(pList);
            break;
        case 5:
            displayCircularList(pList);
            break;
        case 6:
            deleteCircularList(pList);
            break;
        default:
            break;
        }
    }
    return (0);
}