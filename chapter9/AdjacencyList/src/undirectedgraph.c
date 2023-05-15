#include "../include/undirectedgraph.h"
//#include "/root/DataStructures/chapter9/AdjacencyList/include/queue.h"


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
    for (i = 0; i < G->numNodes; i++)
        scanf(" %c", &G->adjlist[i].data);
    struct EdgeNode* e;
    for (k = 0; k < G->numEdges; k++) {
        e = malloc(sizeof(struct EdgeNode));
        printf("input(vi,vj)\n");
        scanf("%d,%d", &i, &j);
        e->next = G->adjlist[i].firstedge;
        G->adjlist[i].firstedge = e;
        e->V = j;
        // �Գƽڵ�
        e = malloc(sizeof(struct EdgeNode));
        e->next = G->adjlist[j].firstedge;
        G->adjlist[j].firstedge = e;
        e->V = i;
    }
}

void CreateLGraphFromTxt(LGraph G, char txt[])
{
    int i, r, c, w;
    FILE* fp;
    char* delim = " ";
    char* tmp;
    char line[100];
    fp = fopen(txt, "r");

    fgets(line, 100, fp);
    tmp = strtok(line, delim);
    G->numNodes = atoi(tmp);
    tmp = strtok(NULL, delim);
    G->numEdges = atoi(tmp);

    fgets(line, 100, fp);
    for (i = 0; i < G->numNodes; i++) {
        G->adjlist[i].data = line[2 * i];
        G->adjlist[i].firstedge = NULL;
    }
    struct EdgeNode* e;       
    for (i = 0; i < G->numEdges; i++) {
        fgets(line, 100, fp);
        tmp = strtok(line, delim);
        r = atoi(tmp);
        tmp = strtok(NULL, delim);
        c = atoi(tmp);
        tmp = strtok(NULL, delim);
        w = atoi(tmp);
        e = malloc(sizeof(struct EdgeNode));
        e->V = c;
        e->Weight = w;
        // 插入r的邻接表
        e->next = G->adjlist[r].firstedge;
        G->adjlist[r].firstedge = e;
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

void BFSTraverse(LGraph G)
{
    int i;
    for (i = 0; i < G->numNodes; i++)
        visited[i] = 0;
    for (i = 0; i < G->numNodes; i++) {
        if (!visited[i])
            BFS(G, i);
    }
}

void BFS(LGraph G, int V)
{
    visited[V] = 1;
    Queue q;
    struct EdgeNode* AdjNode;
    q = CreateQueue(10);
    Enqueue(V, q);
    while (!IsEmpty(q)) {
        V = Dequeue(q);
        printf("%c\n", G->adjlist[V].data);
        AdjNode = G->adjlist[V].firstedge;
        while (AdjNode != NULL) {
            if (!visited[AdjNode->V]) {
                visited[AdjNode->V] = 1;
                Enqueue(AdjNode->V, q);
            }
            AdjNode = AdjNode->next;
        }
    }
}
