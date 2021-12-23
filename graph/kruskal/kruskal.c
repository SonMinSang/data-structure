#include "linkedgraph.h"
#include "arrayheap.h"
#include <stdlib.h>
#include <stdbool.h>

int *createUnionFind(int m)
{
    int *vertex;

    vertex = (int *)malloc(m * sizeof(int));
    if (!vertex)
        return (NULL);
    for (int i = 0; i < m; i++)
    {
        vertex[i] = i;
    }
    return vertex;
}

// parent find
int getParent(int *parent, int child)
{
    if (parent[child] == child)
        return child;
    return parent[child] = getParent(parent, parent[child]);
}

// parent same is true, parent different is false
bool find(int *vertex, int to, int from)
{
    to = getParent(vertex, to);
    from = getParent(vertex, from);
    if (to == from)
        return true;
    return false;
}

// small value prarent init
void unionParent(int *parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

ArrayHeap *sortEdges(LinkedGraph *pGraph)
{
    ArrayHeap *heap;
    ListNode *tempNode;
    LinkedList *edgeList;
    if (!pGraph)
        return (NULL);
    heap = createArrayHeap(pGraph->currentEdgeCount);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        if (checkVertexValid(pGraph, i) == TRUE)
        {
            edgeList = pGraph->ppAdjEdge[i];
            tempNode = edgeList->headerNode.pLink;
            while (tempNode)
            {
                int vertexID = tempNode->vertexID;
                int weight = tempNode->weight;
                if (pGraph->graphType == GRAPH_DIRECTED || (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID))
                {
                    HeapNode heapNode;
                    heapNode.fromVertexID = i;
                    heapNode.toVertexID = vertexID;
                    heapNode.key = weight;
                    insertHeapNode(heap, heapNode);
                }
                tempNode = tempNode->pLink;
            }
        }
    }
    return heap;
}

LinkedGraph *Kruskal(LinkedGraph *pGraph)
{
    ArrayHeap *minHeap;
    HeapNode *temp;
    LinkedGraph *rGraph = NULL;
    int *vertex;

    if (!pGraph)
    {
        return (NULL);
    }
    vertex = createUnionFind(pGraph->maxVertexCount);
    if (!vertex)
        return (NULL);
    rGraph = createLinkedGraph(pGraph->maxVertexCount);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        addVertexLG(rGraph, i);
    }
    minHeap = sortEdges(pGraph);
    while (minHeap->currentElementCount != 0)
    {
        temp = deleteHeapNode(minHeap);
        printf("%d %d %d\n", temp->toVertexID, temp->fromVertexID, temp->key);
        if (!find(vertex, temp->toVertexID, temp->fromVertexID))
        {
            unionParent(vertex, temp->toVertexID, temp->fromVertexID);
            addEdgewithWeightLG(rGraph, temp->fromVertexID, temp->toVertexID, temp->key);
        }
        free(temp);
        temp = 0;
        if (rGraph->currentEdgeCount == rGraph->currentVertexCount - 1)
            break;
    }
    return (rGraph);
}

int main()
{

    LinkedGraph *pGraph;
    LinkedGraph *krus;
    pGraph = createLinkedGraph(6);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        addVertexLG(pGraph, i);
    }
    addEdgewithWeightLG(pGraph, 0, 1, 4);
    addEdgewithWeightLG(pGraph, 0, 2, 3);
    addEdgewithWeightLG(pGraph, 1, 2, 2);
    addEdgewithWeightLG(pGraph, 2, 3, 1);
    addEdgewithWeightLG(pGraph, 3, 4, 1);
    addEdgewithWeightLG(pGraph, 3, 5, 5);
    addEdgewithWeightLG(pGraph, 4, 5, 6);

    krus = Kruskal(pGraph);
    (void)krus;
    displayLinkedGraph(krus);
    // for (int i = 0; i < krus->maxVertexCount; i++)
    //	printf("%d\n", krus->pVertex[i]);
}