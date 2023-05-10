#include "graph.h"

MGraph CreateGraph(int VertexNum)
{
    Vertex V, W;
    MGraph G;
    G = (MGraph)malloc(sizeof(struct GNode));
    G->Nv = VertexNum;
    G->Ne = 0;
    for (V = 0; V < VertexNum; V++)
        for (W = 0; W < VertexNum; W++)
            G->Matrix[V][W] = INFINITY;
    return G;
}

void InsertEdge(MGraph G, Edge E)
{
    G->Matrix[E->V1][E->V2] = E->Weight;
    G->Matrix[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
    MGraph G;
    Edge E;
    int Nv, i;

    //读入顶点个数
    scanf("%d", &Nv);
    //创建没有边的图
    G = CreateGraph(Nv);
    //读入图边的数目
    scanf("%d", &(G->Ne));
    if (G->Ne != 0) {
        E = (Edge)malloc(sizeof(struct ENode));
        for (i = 0; i < G->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            E->V1--;E->V2--;
            InsertEdge(G, E);
        }
    }
    return G;
}

void Floyd(MGraph G, WeightType D[][MaxVertexNum])
{
    Vertex k, i, j;
    for (i = 0; i < G->Nv; i++)
        for (j = 0; j < G->Nv; j++)
            D[i][j] = G->Matrix[i][j];

    for (k = 0; k < G->Nv; k++)
        for (i = 0; i < G->Nv; i++)
            for (j = 0; j < G->Nv; j++) {
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
            }
}

WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex V, int Nv)
{
    WeightType MaxDist;
    Vertex j;

    MaxDist = 0;
    for (j = 0; j < Nv; j++)
        if (V!=j && D[V][j] > MaxDist) { //除去顶点到自身的距离
            MaxDist = D[V][j];
        }

    return MaxDist;
}

void FindAnimal(MGraph G)
{
    WeightType D[MaxVertexNum][MaxVertexNum];
    // 一个顶点到其他顶点的最大距离，所有顶点的最大距离中的最小值
    WeightType MaxDist, MinDist;
    // 源顶点，满足要求的顶点
    WeightType S, Animal;

    MinDist = INFINITY;
    Floyd(G, D);

    for (S = 0; S < G->Nv; S++) {
        MaxDist = FindMaxDist(D, S, G->Nv);
        if (MaxDist < MinDist) {
            MinDist = MaxDist;
            Animal = S + 1;
        }
        if (MaxDist == INFINITY) { //不是连通图
            printf("0\n");
            return;
        }
    }
    printf("%d %d\n", Animal, MinDist);
}