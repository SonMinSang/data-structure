#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree *makeBinTree(BinTreeNode rootNode)
{
    BinTree *pBinTree;

    if (!(pBinTree = (BinTree *)malloc(sizeof(BinTree))))
        return (NULL);
    if (!(pBinTree->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
    {
        free(pBinTree);
        return (NULL);
    }
    *(pBinTree->pRootNode) = rootNode;
    pBinTree->pRootNode->pLeftChild = 0;
    pBinTree->pRootNode->pRightChild = 0;
    return (pBinTree);
}
BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
    if (!pBinTree)
        return (NULL);
    return (pBinTree->pRootNode);
}
BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
    if (!pParentNode)
        return (NULL);
    BinTreeNode *pLNode;
    if (!(pLNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
        return (NULL);
    *pLNode = element;
    pLNode->pLeftChild = NULL;
    pLNode->pRightChild = NULL;
    pParentNode->pLeftChild = pLNode;
    return (pLNode);
}
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
    if (!pParentNode)
        return (NULL);
    BinTreeNode *pRNode;
    if (!(pRNode = (BinTreeNode *)malloc(sizeof(BinTreeNode))))
        return (NULL);
    *pRNode = element;
    pRNode->pLeftChild = NULL;
    pRNode->pRightChild = NULL;
    pParentNode->pRightChild = pRNode;
    return (pRNode);
}
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode)
{
    if (!pNode)
        return (NULL);
    return (pNode->pLeftChild);
}
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode)
{
    if (!pNode)
        return (NULL);
    return (pNode->pRightChild);
}
void deleteBinTree(BinTree *pBinTree)
{
    if (!pBinTree)
        return;
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}
void deleteBinTreeNode(BinTreeNode *pNode)
{
    if (!pNode)
        return;
    deleteBinTreeNode(pNode->pLeftChild);
    deleteBinTreeNode(pNode->pRightChild);
}

void main()
{
    BinTree *pBinTree;

    BinTreeNode *pNode;
    BinTreeNode node0;

    int number;
    while (1)
    {
        printf("1 : MakeTree\n2 : GetRoot\n3 : InsertLeft\n4 : InsertRight\n5 : GetLeft\n6 : GetRight\n7 : DeleteNode\n8 : DeleteTree\n");
        scanf(" %d", &number);
        switch (number)
        {
        case 1:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            pBinTree = makeBinTree(node0);
            pNode = getRootNodeBT(pBinTree);
            printf("Root Node : %c\n", pNode->data);
            break;
        case 2:
            pNode = getRootNodeBT(pBinTree);
            printf("Root Node : %c\n", pNode->data);
            break;
        case 3:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            pNode = insertLeftChildNodeBT(pNode, node0);
            printf("currentNode : %c\n", pNode->data);
            break;
        case 4:
            printf("data : \n");
            getchar();
            scanf("%c", &node0.data);
            pNode = insertRightChildNodeBT(pNode, node0);
            printf("currentNode : %c\n", pNode->data);
            break;
        case 5:
            pNode = getLeftChildNodeBT(pNode);
            printf("currentNode : %c\n", pNode->data);
            break;
        case 6:
            pNode = getRightChildNodeBT(pNode);
            printf("currentNode : %c\n", pNode->data);
            break;
        case 7:
            deleteBinTreeNode(pNode);
            pNode = getRootNodeBT(pBinTree);
            break;
        case 8:
            deleteBinTree(pBinTree);
            return;
        default:
            break;
        }
    }
    return;
}