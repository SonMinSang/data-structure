#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
	int vertexID;
	int weight;
	struct ListNodeType *pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount; // ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿? ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	ListNode headerNode;	 // ï¿½ï¿½ï¿? ï¿½ï¿½ï¿?(Header Node)
} LinkedList;

LinkedList *createLinkedList();
int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);

void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif