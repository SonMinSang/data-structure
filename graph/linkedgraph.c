#include "linkedgraph.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// 그래프 생성
LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
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
    pGraph->currentEdgeCount = 0;
    pGraph->currentVertexCount = 0;
    return (pGraph);
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *pGraph;

    if (maxVertexCount <= 0)
        return (NULL);
    if (!(pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph))))
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
    pGraph->currentEdgeCount = 0;
    pGraph->currentVertexCount = 0;
    return (pGraph);
}
// 그래프 삭제
void deleteLinkedGraph(LinkedGraph *pGraph)
{
    if (!pGraph)
        return;
    for (int i = 0; i < pGraph->maxVertexCount; i++)
        deleteLinkedList(pGraph->ppAdjEdge[i]);
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    if (pGraph->currentVertexCount == 0)
        return (TRUE);
    return (FALSE);
}

// 노드 추가
int addVertexLG(LinkedGraph *pGraph, int vertexID)
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
// 간선 추가
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED));
}

int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    ListNode addNode;
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    addNode.vertexID = toVertexID;
    addNode.weight = weight;
    addLLElement(pGraph->ppAdjEdge[fromVertexID], 0, addNode);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
    {
        addNode.vertexID = fromVertexID;
        addLLElement(pGraph->ppAdjEdge[toVertexID], 0, addNode);
    }
    return (SUCCESS);
}
// 노드의 유효성 점검.
int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
        return (FALSE);
    return (TRUE);
}
// 노드 제거
int removeVertexLG(LinkedGraph *pGraph, int vertexID)
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

// 간선 제거
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    if (!pGraph)
        return (FAIL);
    if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
        return (FAIL);
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    return (SUCCESS);
}
void deleteGraphNode(LinkedList *pList, int delVertexID)
{
    if (!pList)
        return;
    int position;

    position = findGraphNodePosition(pList, delVertexID);
    if (position >= 0)
        removeLLElement(pList, position);
}
int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    if (!pList)
        return (-1);
    ListNode *temp;
    int position = 0;

    temp = pList->headerNode.pLink;
    while (temp)
    {
        if (temp->vertexID == vertexID)
            return (position);
        position++;
        temp = temp->pLink;
    }
    return (-1);
}
// 간선 개수 반환
int getEdgeCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->currentEdgeCount);
}
// 노드 개수 반환
int getVertexCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->currentVertexCount);
}

// 최대 노드 개수 반환
int getMaxVertexCountLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->maxVertexCount);
}

// 그래프 종류 반환.
int getGraphTypeLG(LinkedGraph *pGraph)
{
    if (!pGraph)
        return (FALSE);
    return (pGraph->graphType);
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph *pGraph)
{
    if (!pGraph)
        return;
    ListNode *temp;
    int position;

    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        for (int j = 0; j < pGraph->maxVertexCount; j++)
        {
            position = findGraphNodePosition(pGraph->ppAdjEdge[i], i);
            if (position >= 0)
            {
                temp = getLLElement(pGraph->ppAdjEdge[i], position);
                printf("%d ", temp->weight);
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}

void dfs(LinkedGraph *lg, int vertex)
{
    bool *visit;
    LinkedStack *s;
    StackNode ele;

    if (lg->maxVertexCount <= vertex)
        return;
    ele.data = vertex;
    if (!(visit = (bool *)calloc(lg->maxVertexCount, sizeof(bool))))
        return;
    s = createLinkedStack();
    pushLS(s, ele);
    visit[vertex] = true;
    while (!isLinkedStackEmpty(s))
    {
        StackNode *tmp = popLS(s);
        printf("%d\n", tmp->data);
        for (int i = 0; i < lg->maxVertexCount; i++)
        {
            if (i == tmp->data)
                continue;
            if (findGraphNodePosition(lg->ppAdjEdge[tmp->data], i) >= 0 && !visit[i])
            {
                ele.data = i;
                visit[i] = true;
                pushLS(s, ele);
            }
        }
    }
}

void bfs(LinkedGraph *lg, int vertex)
{
    bool *visit;
    LinkedDeque *q;
    DequeNode ele;

    if (lg->maxVertexCount <= vertex)
        return;
    ele.data = vertex;
    if (!(visit = (bool *)calloc(lg->maxVertexCount, sizeof(bool))))
        return;
    q = createLinkedDeque();
    insertRearLD(q, ele);
    visit[vertex] = true;
    while (!isLinkedDequeEmpty(q))
    {
        DequeNode *tmp = deleteFrontLD(q);
        printf("%d\n", tmp->data);
        for (int i = 0; i < lg->maxVertexCount; i++)
        {
            if (i == tmp->data)
                continue;
            if (findGraphNodePosition(lg->ppAdjEdge[tmp->data], i) >= 0 && !visit[i])
            {
                ele.data = i;
                visit[i] = true;
                insertRearLD(q, ele);
            }
        }
    }
}

void undir_lg_test()
{
    LinkedGraph *lg;
    int max_count;

    printf("graph의 크기 : ");
    scanf("%d", &max_count);
    lg = createLinkedGraph(max_count);

    while (1)
    {
        int n;
        int to;
        int from;

        printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
        printf("작업할 내용을 선택해주세요 : ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("추가할 Vertex : ");
            scanf(" %d", &n);
            addVertexLG(lg, n);
            break;
        case 2:
            printf("연결할 Vertex를 입력해주세요(from, to) : ");
            scanf("%d %d", &from, &to);
            if (addEdgeLG(lg, from, to) == FAIL)
                fprintf(stderr, "연결에 실패했습니다.\n");
            break;
        case 3:
            printf("연결할 Vertex를 입력해주세요(from, to) : ");
            scanf(" %d %d", &from, &to);
            printf("가중치를 입력해주세요 : ");
            scanf(" %d", &n);
            if (addEdgewithWeightLG(lg, from, to, n))
                fprintf(stderr, "연결에 실패했습니다.\n");
            break;
        case 4:
            printf("삭제할 Vertex를 입력해주세요 : ");
            scanf(" %d", &n);
            if (removeVertexLG(lg, n) == FAIL)
                fprintf(stderr, "vertex 삭제에 실패했습니다.\n");
            break;
        case 5:
            printf("삭제할 edge를 입력해주세요(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (removeEdgeLG(lg, from, to) == FAIL)
                fprintf(stderr, "edge 삭제에 실패했습니다.\n");
            break;
        case 6:
            printf("%s\n", isEmptyLG(lg) ? "TRUE" : "FALSE");
            break;
        case 7:
            displayLinkedGraph(lg);
            break;
        case 8:
            deleteLinkedGraph(lg);
            break;
        case 9:
            printf("탐색 시작점을 입력해주세요 : ");
            scanf(" %d", &n);
            dfs(lg, n);
            break;
        case 10:
            printf("탐색 시작점을 입력해주세요 : ");
            scanf(" %d", &n);
            bfs(lg, n);
            break;
        default:
            break;
        }
        if (n == 8)
            break;
    }
}

void dir_lg_test()
{
    LinkedGraph *lg;
    int max_count;

    printf("graph의 크기 : ");
    scanf("%d", &max_count);
    lg = createLinkedDirectedGraph(max_count);
    while (1)
    {
        int n;
        int to;
        int from;

        printf("1.vertex insert\n2.edge insert(no weight)\n3.edge insert(weight)\n4.remove vertex\n5.remove edge\n6.empty\n7.display\n8.delete\n9.dfs\n10.bfs\n");
        printf("작업할 내용을 선택해주세요 : ");
        scanf(" %d", &n);
        switch (n)
        {
        case 1:
            printf("추가할 Vertex : ");
            scanf(" %d", &n);
            addVertexLG(lg, n);
            break;
        case 2:
            printf("연결할 Vertex를 입력해주세요(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (addEdgeLG(lg, from, to) == FAIL)
                fprintf(stderr, "연결에 실패했습니다.\n");
            break;
        case 3:
            printf("연결할 Vertex를 입력해주세요(from, to) : ");
            scanf(" %d %d", &from, &to);
            printf("가중치를 입력해주세요 : ");
            scanf(" %d", &n);
            if (addEdgewithWeightLG(lg, from, to, n))
                fprintf(stderr, "연결에 실패했습니다.\n");
            break;
        case 4:
            printf("삭제할 Vertex를 입력해주세요 : ");
            scanf(" %d", &n);
            if (removeVertexLG(lg, n) == FAIL)
                fprintf(stderr, "vertex 삭제에 실패했습니다.\n");
            break;
        case 5:
            printf("삭제할 edge를 입력해주세요(from, to) : ");
            scanf(" %d %d", &from, &to);
            if (removeEdgeLG(lg, from, to) == FAIL)
                fprintf(stderr, "edge 삭제에 실패했습니다.\n");
            break;
        case 6:
            printf("%s\n", isEmptyLG(lg) ? "TRUE" : "FALSE");
            break;
        case 7:
            displayLinkedGraph(lg);
            break;
        case 8:
            deleteLinkedGraph(lg);
            break;
        case 9:
            printf("탐색 시작점을 입력해주세요 : ");
            scanf(" %d", &n);
            dfs(lg, n);
            break;
        case 10:
            printf("탐색 시작점을 입력해주세요 : ");
            scanf(" %d", &n);
            bfs(lg, n);
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
        undir_lg_test();
        break;
    case 2:
        dir_lg_test();
        break;
    default:
        break;
    }
}