#include "floyd.h"
#include <stdlib.h>

struct GNode
{
    char vexs[MAXVEX];
    int Matrix[MAXVEX][MAXVEX];
    int numVertex, numEdge;
};

MGraph Intialize(void)
{
    MGraph G;
    G = malloc(sizeof(struct GNode));
    if (G == NULL) {
        fprintf(stderr, "out of space");
        exit(1);
    }
    G->numEdge = 0;
    G->numVertex = 0;
    return G;
}

void CreateGraphFromTxt(MGraph G, char txt[])
{
    int i, j, r, c, w;
    FILE* fp;
    char* delim = " ";
    char* tmp;
    char line[100];
    fp = fopen(txt, "r");

    fgets(line, 100, fp);
    tmp = strtok(line, delim);
    G->numVertex = atoi(tmp);
    tmp = strtok(NULL, delim);
    G->numEdge = atoi(tmp);

    fgets(line, 100, fp);
    for (i = 0; i < G->numVertex; i++) {
        G->vexs[i] = line[2 * i]; 
    }

    for (i = 0; i < G->numVertex; i++)
        for (j = 0; j < G->numVertex; j++) {
            if (i == j)
                G->Matrix[i][j] = 0;
            else
                G->Matrix[i][j] = INFINITY;
        }
            
    for (i = 0; i < G->numEdge; i++) {
        fgets(line, 100, fp);
        tmp = strtok(line, delim);
        r = atoi(tmp);
        tmp = strtok(NULL, delim);
        c = atoi(tmp);
        tmp = strtok(NULL, delim);
        w = atoi(tmp);
        G->Matrix[r][c] = w;
        G->Matrix[c][r] = w;
    }
}

void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G->numVertex; v++) {
        for (w = 0; w < G->numVertex; w++) {
            (*D)[v][w] = G->Matrix[v][w];
            (*P)[v][w] = w;
        }
    }
    
    for (k = 0; k < G->numVertex; k++) {
        for (v = 0; v < G->numVertex; v++) {
            for (w = 0; w < G->numVertex; w++) {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}

void PrintShortestPath(MGraph G, Patharc P, ShortPathTable D)
{
    printf("各顶点间最短路径如下:\n");
    int v, w, k;
    for (v = 0; v < G->numVertex; v++) {
        for (w = v + 1; w < G->numVertex; w++) {
            printf("v%d-v%d weight: %d", v, w, D[v][w]);
            k = P[v][w];
            printf(" path: %d", v);
            while (k != w) {
                printf(" -> %d", k);
                k = P[k][w];
            }
            printf(" -> %d\n", w);
        }
        printf("\n");
    }
}