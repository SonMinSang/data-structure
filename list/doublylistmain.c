#include "doublylist1.h"

DoublyList*	createDoublyList()		// list 생성
{
	DoublyList* list;

	list = (DoublyList *)malloc(sizeof(DoublyList));
	if (list == NULL)
		return (NULL);
	list->currentElementCount = 0;
	list->headerNode.pLLink = &list->headerNode;
	list->headerNode.pRLink = &list->headerNode;
	return (list);
}

int	addDLElement(DoublyList* pList, int position, DoublyListNode element)		// 노드 추가
{
	DoublyListNode	*new;
	DoublyListNode	*prev;
	int	i;

	if (pList == NULL || position < 0 || position > pList->currentElementCount)
		return (FALSE);
	new = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (new == NULL)
		return (FALSE);
	new->data = element.data;
	prev = &pList->headerNode;
	for (i = 0; i < position; i++)
		prev = prev->pRLink;
	new->pLLink = prev;
	new->pRLink = prev->pRLink;
	prev->pRLink = new;
	new->pRLink->pLLink = new;
	pList->currentElementCount++;
	return (TRUE);
}

int	removeDLElement(DoublyList* pList, int position)		// 노드 제거
{
	DoublyListNode	*prev;
	DoublyListNode	*temp;
	int	i;

	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	prev = &pList->headerNode;
	for (i = 0; i < position; i++)
		prev = prev->pRLink;
	temp = prev->pRLink;
	prev->pRLink = temp->pRLink;
	temp->pRLink->pLLink = prev;
	free(temp);
	temp = NULL;
	pList->currentElementCount--;
	return (TRUE);
}

DoublyListNode*	getDLElement(DoublyList* pList, int position) 		// 노드 가져오기
{
	int	i;
	DoublyListNode	*curr;

	if (pList == NULL || position < 0 || position >= pList->currentElementCount)
		return (NULL);
	curr = pList->headerNode.pRLink;
	for (i = 0; i < position; i++)
		curr = curr->pRLink;
	return (curr);
}

void	displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*curr;
	int	i;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pRLink;
	if (curr == &pList->headerNode)
		printf("empty list");
	else{
		for (i = 0; i < getDoublyListLength(pList); i++)
			printf("%d ", getDLElement(pList, i)->data);
	}
	printf("\n");
}

void	clearDoublyList(DoublyList* pList) 		// list 초기화
{
	DoublyListNode	*curr;
	DoublyListNode	*next;

	if (pList == NULL)
		return ;
	curr = pList->headerNode.pRLink;
	while (pList->currentElementCount)
	{
		next = curr->pRLink;
		free(curr);
		curr = next;
		pList->currentElementCount--;
	}
	pList->headerNode.pLLink = &pList->headerNode;
	pList->headerNode.pRLink = &pList->headerNode;
}

int	getDoublyListLength(DoublyList* pList) 		// list 노드의 개수 확인
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void	deleteDoublyList(DoublyList* pList) 	// list free
{
	if (pList == NULL)
		return ;
	clearDoublyList(pList);
	free(pList);
	pList = NULL;
}

int main()
{
    DoublyList *pList;

    DoublyListNode *temp;
    DoublyListNode node0;

    int number, position;
    pList = createDoublyList();
    while (1)
    {
        printf("1 : Add\n2 : Remove\n3 : Get\n4 : Clear\n5 : Display\n6 : Delete\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("{data, position} : \n");
            getchar();
            scanf("%d %d", &node0.data, &position);
            addDLElement(pList, position, node0);
            displayDoublyList(pList);

            break;
        case 2:
            printf("position : \n");
            scanf("%d", &position);
            removeDLElement(pList, position);
            displayDoublyList(pList);
            break;
        case 3:
            printf("position : \n");
            scanf("%d", &position);
            temp = getDLElement(pList, position);;
            printf("%d!\n", temp->data);
            break;
        case 4:
            clearDoublyList(pList);
            displayDoublyList(pList);
            break;
        case 5:
            displayDoublyList(pList);
            break;
        case 6:
            deleteDoublyList(pList);
            break;
        default:
            break;
        }
    }
    return (0);
}