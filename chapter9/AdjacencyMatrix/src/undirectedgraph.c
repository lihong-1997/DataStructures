#include "undirectedgraph.h"

struct MGraph
{
    VertexType vexs[MAXVEX];
    EdgeType AdMatrix[MAXVEX][MAXVEX];
    int numNodes;
    int numEdges;
};

Graph Intialize(void)
{
    Graph G;
    G = malloc(sizeof(struct MGraph));
    if (G == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    G->numEdges = 0;
    G->numNodes = 0;
    return G;
}

void CreateGraphFromTxt(Graph G, char txt[])
{
    int i, j, r, c, w;
    FILE* fp;
    char line[100];
    fp = fopen(txt, "r");

    fgets(line, 100, fp);
    G->numNodes = line[0] - '0';
    G->numEdges = line[2] - '0';

    fgets(line, 100, fp);
    for (i = 0; i < G->numNodes; i++) {
        G->vexs[i] = line[2 * i]; 
    }

    for (i = 0; i < G->numNodes; i++)
        for (j = 0; j < G->numNodes; j++)
            G->AdMatrix[i][j] = 0;

    for (i = 0; i < G->numEdges; i++) {
        fgets(line, 100, fp);
        r = line[0] - '0';
        c = line[2] - '0';
        w = line[4] - '0';
        G->AdMatrix[r][c] = w;
        G->AdMatrix[c][r] = w;
    }
}

void CreateGraph(Graph G)
{
    int i, j, k, w;
    printf("input vertex num and edge num\n");
    scanf("%d,%d", &G->numNodes, &G->numEdges);
    for (i = 0; i < G->numNodes; i++) {
        scanf("%c", &G->vexs[i]);
        getchar();
    }
    for (i = 0; i < G->numNodes; i++)
        for (j = 0; j < G->numNodes; j++)
            G->AdMatrix[i][j] = 0;
    for (k = 0; k < G->numEdges; k++) {
        printf("input (vi,vj) and w\n");
        scanf("%d,%d,%d", &i, &j, &w);
        G->AdMatrix[i][j] = w;
        G->AdMatrix[j][i] = w;
    }
}

static int visited[MAXVEX];

void DFS(Graph G, int V)
{
    int j;
    visited[V] = 1;
    printf("%c\n", G->vexs[V]);
    for (j = 0; j < G->numNodes; j++) { //ÿ����V���ڽӽڵ㶼Ҫѭ��
        if (G->AdMatrix[V][j] == 1 && !visited[j]) {
            DFS(G, j);
        }
    }
}

void DFSTraverse(Graph G)
{
    int i;
    for (i = 0; i < G->numNodes; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < G->numNodes; i++) {
        if (!visited[i])
            DFS(G, i);
    }
}