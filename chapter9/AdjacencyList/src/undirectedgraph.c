#include "undirectedgraph.h"

struct EdgeNode
{
    int V; // 顶点index
    struct EdgeNode* next;
};

struct VertexNode
{
    VertexType data;
    struct EdgeNode* firstedge;
};

struct LGraph
{
    int numNodes;
    int numEdges;
    AdjList adjlist;
};

LGraph Intialize(void)
{
    LGraph G;
    G = malloc(sizeof(struct LGraph));
    if (G == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    G->numEdges = 0;
    G->numNodes = 0;
    G->adjlist = malloc(sizeof(struct VertexNode) * MAXVEX);
    if (G->adjlist == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    int i;
    for (i = 0; i < MAXVEX; i++) {
        G->adjlist[i].data = ' ';
        G->adjlist[i].firstedge = NULL;
    }
    return G;
}

void CreateLGraph(LGraph G)
{
    printf("input vertex num and edge num\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    int i, j, k;
    for (i = 0; i < G->numNodes; i++) {
        scanf(" %c", &G->adjlist[i].data);
    }
    struct EdgeNode* e;
    for (k = 0; k < G->numEdges; k++) {
        e = malloc(sizeof(struct EdgeNode));
        printf("input(vi,vj)\n");
        scanf("%d,%d", &i, &j);
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e;
        e->V = j;
        // 对称节点
        e = malloc(sizeof(struct EdgeNode));
        e->next = G->adjlist[j].firstedge;
        G->adjlist[j].firstedge = e;
        e->V = i;
    }
}

static int visited[MAXVEX];

void DFSTraverse(LGraph G)
{
    int i;
    for (i = 0; i < G->numNodes; i++)
        visited[i] = 0;
    for (i = 0; i < G->numNodes; i++) {
        if (!visited[i])
            DFS(G, i);
    }
}

void DFS(LGraph G, int V)
{
    printf("%c\n", G->adjlist[V].data);
    visited[V] = 1;
    struct EdgeNode* AdjNode;
    AdjNode = G->adjlist[V].firstedge;
    while (AdjNode != NULL) {
        if (!visited[AdjNode->V])
            DFS(G, AdjNode->V);
        AdjNode = AdjNode->next;
    }
}



