#include "binsearchtree.h"
#include <stdlib.h>

BinSearchTree *createBinSearchTree()
{
    BinSearchTree *pBinSearchTree;

    if (!(pBinSearchTree = (BinSearchTree *)malloc(sizeof(BinSearchTree))))
        return (NULL);
    pBinSearchTree->pRootNode = NULL;

    return (pBinSearchTree);
}
int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
    if (!pBinSearchTree)
        return (FALSE);

    BinSearchTreeNode *parentNode;
    BinSearchTreeNode *addNode;

    if (!(addNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode))))
        return (FALSE);
    *addNode = element;
    addNode->pRightChild = NULL;
    addNode->pLeftChild = NULL;

    parentNode = pBinSearchTree->pRootNode;

    if (!parentNode) // RootNode가 없으면 RootNode에 삽입
        pBinSearchTree->pRootNode = addNode;

    while (parentNode)
    {                                       // addNode 를 넣을 위치 찾기
        if (parentNode->key == element.key) // key 중복시 FALSE 반환
            return (FALSE);

        if (parentNode->key < element.key) // parentNode 의 key가 찾을 key보다 작을 때
        {
            if (!parentNode->pRightChild) // parentNode의 key 값보다 큰 key를 가진 노드가 없을 때 while문 종료
                break;
            else
                parentNode = parentNode->pRightChild;
        }
        else // parentNode 의 key가 찾을 key보다 클 때
        {
            if (!parentNode->pLeftChild) // parentNode의 key 값보다 작은 key를 가진 노드가 없을 때 while문 종료
                break;
            else
                parentNode = parentNode->pLeftChild;
        }
    }

    if (parentNode->key < element.key)
        parentNode->pRightChild = addNode;
    else
        parentNode->pLeftChild = addNode;

    return (TRUE);
}
int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *delNode;
    BinSearchTreeNode *parentNode;
    BinSearchTreeNode *childNode;
    if (!pBinSearchTree)
        return (FALSE);
    while (delNode != NULL)
    {
        if (delNode->key == key)
            break;
        parentNode = delNode;
        if (delNode->key < key)
            delNode = delNode->pRightChild;
        else
            delNode = delNode->pLeftChild;
    }
    if (!delNode)
        return (FALSE);

    if (!delNode->pLeftChild && !delNode->pRightChild) // 자식노드가 없을 때
    {
        if (parentNode)
        {
            if (parentNode->pLeftChild == delNode)
                parentNode->pLeftChild = NULL;
            else
                parentNode->pRightChild = NULL;
        }
        else
            pBinSearchTree->pRootNode = NULL;
    }
    else if ((!delNode->pLeftChild && delNode->pRightChild) ||
             (delNode->pLeftChild && !delNode->pRightChild)) // 자식노드가 하나만 있을때
    {
        if (delNode->pLeftChild) // delNode 가 가진 자식 노드 childNode에 저장
            childNode = delNode->pLeftChild;
        else
            childNode = delNode->pRightChild;
        if (parentNode) // parentNode의 자식으로 childNode을 설정
        {
            if (parentNode->pLeftChild == delNode)
                parentNode->pLeftChild = childNode;
            else
                parentNode->pRightChild = childNode;
        }
        else // parentNode가 없는경우는  delNode가 RootNode인 경우
            pBinSearchTree->pRootNode = childNode;
    }
    else // 자식노드가 2개일때
    {
        //왼쪽에서 가장 큰 노드로 교체하거나 오른쪽에서 가장 작은 노드로 교체
    }
    free(delNode);
    return (TRUE);
}
BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key)
{
    if (!pBinSearchTree)
        return (NULL);
    return (searchInternalRecursiveBST(pBinSearchTree->pRootNode, key));
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key)
{
    if (!pTreeNode)
        return NULL;
    if (pTreeNode->key == key) // key 를 찾았을때
        return (pTreeNode);
    else if (pTreeNode->key < key)
        return (searchInternalRecursiveBST(pTreeNode->pRightChild, key)); // temp의 key가 인자로 받은 key보다 작으면 오른쪽 영역을 탐색한다.
    else
        return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key)); // temp의 key가 인자로 받은 key보다 크면 왼쪽 영역을 탐색한다.
}
BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
    if (!pBinSearchTree)
        return NULL;
    BinSearchTreeNode *temp;

    temp = pBinSearchTree->pRootNode;
    while (temp)
    {
        if (temp->key == key) // key 를 찾았을때
            break;
        if (temp->key < key) // temp의 key가 인자로 받은 key보다 작으면 오른쪽 영역을 탐색한다.
            temp = temp->pRightChild;
        else // temp의 key가 인자로 받은 key보다 크면 왼쪽 영역을 탐색한다.
            temp = temp->pLeftChild;
    }
    return temp;
}
void deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
}
void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode)
{
}