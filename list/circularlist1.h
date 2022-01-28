#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct CircularNodeType
{
	int							data;
	struct CircularNodeType*	pLink;
} CircularNode;

typedef struct CircularListType
{
	int				currentElementCount;	// ���� ����� ������ ����
	CircularNode	headerNode;				// ��� ���(Header Node)
} CircularList;

CircularList*	createCircularList();													// Circularlist ����
int				addCLElement(CircularList* pList, int position, CircularNode element);	// ��� �߰�
int				removeCLElement(CircularList* pList, int position);						// ��� ����
CircularNode*	getCLElement(CircularList* pList, int position);						// ��� ��������
void			clearCircularList(CircularList* pList);									// Circularlist �ʱ�ȭ
int				getCircularListLength(CircularList* pList);								// Circularlist ����� ���� Ȯ��
void			deleteCircularList(CircularList* pList);								// Circularlist free

CircularNode*	getLastCLElement(CircularList* pList);
void			displayCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif