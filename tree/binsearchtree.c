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

    if (!parentNode) // RootNode�� ������ RootNode�� ����
        pBinSearchTree->pRootNode = addNode;

    while (parentNode)
    {                                       // addNode �� ���� ��ġ ã��
        if (parentNode->key == element.key) // key �ߺ��� FALSE ��ȯ
            return (FALSE);

        if (parentNode->key < element.key) // parentNode �� key�� ã�� key���� ���� ��
        {
            if (!parentNode->pRightChild) // parentNode�� key ������ ū key�� ���� ��尡 ���� �� while�� ����
                break;
            else
                parentNode = parentNode->pRightChild;
        }
        else // parentNode �� key�� ã�� key���� Ŭ ��
        {
            if (!parentNode->pLeftChild) // parentNode�� key ������ ���� key�� ���� ��尡 ���� �� while�� ����
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

    if (!delNode->pLeftChild && !delNode->pRightChild) // �ڽĳ�尡 ���� ��
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
             (delNode->pLeftChild && !delNode->pRightChild)) // �ڽĳ�尡 �ϳ��� ������
    {
        if (delNode->pLeftChild) // delNode �� ���� �ڽ� ��� childNode�� ����
            childNode = delNode->pLeftChild;
        else
            childNode = delNode->pRightChild;
        if (parentNode) // parentNode�� �ڽ����� childNode�� ����
        {
            if (parentNode->pLeftChild == delNode)
                parentNode->pLeftChild = childNode;
            else
                parentNode->pRightChild = childNode;
        }
        else // parentNode�� ���°���  delNode�� RootNode�� ���
            pBinSearchTree->pRootNode = childNode;
    }
    else // �ڽĳ�尡 2���϶�
    {
        //���ʿ��� ���� ū ���� ��ü�ϰų� �����ʿ��� ���� ���� ���� ��ü
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
    if (pTreeNode->key == key) // key �� ã������
        return (pTreeNode);
    else if (pTreeNode->key < key)
        return (searchInternalRecursiveBST(pTreeNode->pRightChild, key)); // temp�� key�� ���ڷ� ���� key���� ������ ������ ������ Ž���Ѵ�.
    else
        return (searchInternalRecursiveBST(pTreeNode->pLeftChild, key)); // temp�� key�� ���ڷ� ���� key���� ũ�� ���� ������ Ž���Ѵ�.
}
BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
    if (!pBinSearchTree)
        return NULL;
    BinSearchTreeNode *temp;

    temp = pBinSearchTree->pRootNode;
    while (temp)
    {
        if (temp->key == key) // key �� ã������
            break;
        if (temp->key < key) // temp�� key�� ���ڷ� ���� key���� ������ ������ ������ Ž���Ѵ�.
            temp = temp->pRightChild;
        else // temp�� key�� ���ڷ� ���� key���� ũ�� ���� ������ Ž���Ѵ�.
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