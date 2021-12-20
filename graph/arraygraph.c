#include "arraygraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// �׷��� ����
ArrayGraph *createArrayGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount)))
        {
            for (int j = 0; j < i - 1; j++)
            {
                free(pGraph->ppAdjEdge[j]);
            }
            free(pGraph->pVertex);
            free(pGraph);
            return (NULL);
        }
    }
    pGraph->graphType = GRAPH_UNDIRECTED;
    pGraph->maxVertexCount = maxVertexCount;
    memset(pGraph->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    return (pGraph);
}
ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph))))
        return (NULL);
    if (!(pGraph->pVertex = (int *)malloc(sizeof(int) * maxVertexCount)))
    {
        free(pGraph);
        return (NULL);
    }
    if (!(pGraph->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount)))
    {
        free(pGraph);
        free(pGraph->pVertex);
        return (NULL);
    }
    for (int i = 0; i < maxVertexCount; i++)
    {
        if (!(pGraph->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount)))
        {
            for (int j = 0; j < i - 1; j++)
            {
                free(pGraph->ppAdjEdge[j]);
            }
            free(pGraph->pVertex);
            free(pGraph);
            return (NULL);
        }
    }
    pGraph->graphType = GRAPH_DIRECTED;
    pGraph->maxVertexCount = maxVertexCount;

    memset(pGraph->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (int i = 0; i < maxVertexCount; i++)
        memset(pGraph->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    return (pGraph);
}
// �׷��� ����
void deleteArrayGraph(ArrayGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        free(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

// ���� �׷��� ���� �Ǵ�
int isEmptyAG(ArrayGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    if (pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}

// ��� �߰�
int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (!pGraph)
        return (FAIL);
    if (vertexID >= pGraph->maxVertexCount)
        return (FAIL);
    if (pGraph->pVertex[vertexID] == USED)
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return (SUCCESS);
}
// ���� �߰�
int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED));
}
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (SUCCESS);
}

// ����� ��ȿ�� ����.
int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    return (TRUE);
}

// ��� ����
int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, vertexID))
        return (FAIL);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return (SUCCESS);
}

// ���� ����
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return (SUCCESS);
}

// �׷��� ���� ���
void displayArrayGraph(ArrayGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        for (int j = 0; j < pGraph->maxVertexCount; j++)
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        printf("\n");
    }
}

void dfs(ArrayGraph *ag, int vertex)
{
    bool *visit;
    LinkedStack *s;
    StackNode ele;

    if (ag->maxVertexCount <= vertex)
        return;
    ele.data = vertex;
    if (!(visit = (bool *)calloc(ag->maxVertexCount, sizeof(bool))))
        return;
    s = createLinkedStack();
    pushLS(s, ele);
    visit[vertex] = true;
    while (!isLinkedStackEmpty(s))
    {
        StackNode *tmp = popLS(s);
        printf("%d\n", tmp->data);
        for (int i = 0; i < ag->maxVertexCount; i++)
        {
            if (i == tmp->data)
                continue;
            if (ag->ppAdjEdge[tmp->data][i] && !visit[i])
            {
                ele.data = i;
                visit[i] = true;
                pushLS(s, ele);
            }
        }
    }
}

void bfs(ArrayGraph *ag, int vertex)
{
    bool *visit;
    LinkedDeque *q;
    DequeNode ele;

    if (ag->maxVertexCount <= vertex)
        return;
    ele.data = vertex;
    if (!(visit = (bool *)calloc(ag->maxVertexCount, sizeof(bool))))
        return;
    q = createLinkedDeque();
    insertRearLD(q, ele);
    visit[vertex] = true;
    while (!isLinkedDequeEmpty(q))
    {
        DequeNode *tmp = deleteFrontLD(q);
        printf("%d\n", tmp->data);
        for (int i = 0; i < ag->maxVertexCount; i++)
        {
            if (i == tmp->data)
                continue;
            if (ag->ppAdjEdge[tmp->data][i] && !visit[i])
            {
                ele.data = i;
                visit[i] = true;
                insertRearLD(q, ele);
            }
        }
    }
}

void undir_ag_test()
{
    ArrayGraph *ag;
    int max_count;

    printf("graph�� ũ�� : ");
    scanf("%d", &max_count);
    ag = createArrayGraph(max_count);

    while (1)
    {
        int n;
        int to;
        int from;

        printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
        printf("�۾��� ������ �������ּ��� : ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("�߰��� Vertex : ");
            scanf(" %d", &n);
            addVertexAG(ag, n);
            break;
        case 2:
            printf("������ Vertex�� �Է����ּ���(from, to) : ");
            scanf("%d %d", &from, &to);
            if (addEdgeAG(ag, from, to) == FAIL)
                fprintf(stderr, "���ῡ �����߽��ϴ�.\n");
            break;
        case 3:
            printf("������ Vertex�� �Է����ּ���(from, to) : ");
            scanf(" %d %d", &from, &to);
            printf("����ġ�� �Է����ּ��� : ");
            scanf(" %d", &n);
            if (addEdgewithWeightAG(ag, from, to, n))
                fprintf(stderr, "���ῡ �����߽��ϴ�.\n");
            break;
        case 4:
            printf("������ Vertex�� �Է����ּ��� : ");
            scanf(" %d", &n);
            if (removeVertexAG(ag, n) == FAIL)
                fprintf(stderr, "vertex ������ �����߽��ϴ�.\n");
            break;
        case 5:
            printf("������ edge�� �Է����ּ���(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (removeEdgeAG(ag, from, to) == FAIL)
                fprintf(stderr, "edge ������ �����߽��ϴ�.\n");
            break;
        case 6:
            printf("%s\n", isEmptyAG(ag) ? "TRUE" : "FALSE");
            break;
        case 7:
            displayArrayGraph(ag);
            break;
        case 8:
            deleteArrayGraph(ag);
            break;
        case 9:
            printf("Ž�� �������� �Է����ּ��� : ");
            scanf(" %d", &n);
            dfs(ag, n);
            break;
        case 10:
            printf("Ž�� �������� �Է����ּ��� : ");
            scanf(" %d", &n);
            bfs(ag, n);
            break;
        default:
            break;
        }
        if (n == 8)
            break;
    }
}

void dir_ag_test()
{
    ArrayGraph *ag;
    int max_count;

    printf("graph�� ũ�� : ");
    scanf("%d", &max_count);
    ag = createArrayDirectedGraph(max_count);
    while (1)
    {
        int n;
        int to;
        int from;

        printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
        printf("�۾��� ������ �������ּ��� : ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("�߰��� Vertex : ");
            scanf(" %d", &n);
            addVertexAG(ag, n);
            break;
        case 2:
            printf("������ Vertex�� �Է����ּ���(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (addEdgeAG(ag, from, to) == FAIL)
                fprintf(stderr, "���ῡ �����߽��ϴ�.\n");
            break;
        case 3:
            printf("������ Vertex�� �Է����ּ���(from, to) : ");
            scanf(" %d %d", &from, &to);
            printf("����ġ�� �Է����ּ��� : ");
            scanf(" %d", &n);
            if (addEdgewithWeightAG(ag, from, to, n))
                fprintf(stderr, "���ῡ �����߽��ϴ�.\n");
            break;
        case 4:
            printf("������ Vertex�� �Է����ּ��� : ");
            scanf(" %d", &n);
            if (removeVertexAG(ag, n) == FAIL)
                fprintf(stderr, "vertex ������ �����߽��ϴ�.\n");
            break;
        case 5:
            printf("������ edge�� �Է����ּ���(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (removeEdgeAG(ag, from, to) == FAIL)
                fprintf(stderr, "edge ������ �����߽��ϴ�.\n");
            break;
        case 6:
            printf("%s\n", isEmptyAG(ag) ? "TRUE" : "FALSE");
            break;
        case 7:
            displayArrayGraph(ag);
            break;
        case 8:
            deleteArrayGraph(ag);
            break;
        case 9:
            printf("Ž�� �������� �Է����ּ��� : ");
            scanf(" %d", &n);
            dfs(ag, n);
            break;
        case 10:
            printf("Ž�� �������� �Է����ּ��� : ");
            scanf(" %d", &n);
            bfs(ag, n);
            break;
        default:
            break;
        }
        if (n == 8)
            break;
    }
}

int main()
{
    int n;

    printf("1. undirected graph\n2. directed graph\n");
    scanf(" %d", &n);
    switch (n)
    {
    case 1:
        undir_ag_test();
        break;
    case 2:
        dir_ag_test();
        break;
    default:
        break;
    }
}