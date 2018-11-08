#include <stdio.h>
#include <stdlib.h>
#define MAXVEW 100//最大顶点数
#define INFINITY 65536//正无穷

typedef struct
{
    char vexs[MAXVEW];//顶点表
    int arc[MAXVEW][MAXVEW];//邻接矩阵
    int numVertexes;//顶点数
    int numEdges;//边数
}MGraph;

//建立无向网图的邻接矩阵表示
void CreatMGraph(MGraph *G)
{
    int i,j,k,w;//w为权值
    printf("输入顶点数和边数:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);//输入顶点数和边数
    fflush(stdin);
    for(i = 0; i < G->numVertexes; i++)//读入顶点信息
    {
        scanf("%c",&G->vexs[i]);
        getchar();
    }
    for(i = 0;i < G->numVertexes;i++)
        for(j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;//邻接矩阵初始化
    for(k = 0; k < G->numEdges; k++)//读入numEdges条边，建立邻接矩阵
    {
        printf("输入边(vi,vj)下标i,下标j和权w:\n");
        scanf("%d %d %d",&i,&j,&w);
        fflush(stdin);
        G->arc[i-1][j-1] = w;
        G->arc[j-1][i-1] = w;//无向图
    }
}
void print_graph(MGraph G)
{
    int i,j;
    printf("邻接矩阵如下:\n");
    for(i = 0;i < G.numVertexes;i++)
    {
        for(j = 0;j < G.numVertexes; j++)
        {
            printf("%5d ",G.arc[i][j]);
        }
        printf("\n");
    }
}

void Dijkstra(MGraph G,int x,int y)
{
    int i,k;
    int min;
    int u;
    int dis[G.numVertexes];//最小路径
    int mark[G.numVertexes];//被标记的
    for(i = 0; i < G.numVertexes; i++)
    {
        mark[i] = 0;
        dis[i] = G.arc[x][i];
    }
    mark[x] = 1;//标记源点
    for(k = 0; k < G.numVertexes; k++)
    {
        min = INFINITY;
        for(i = 0; i < G.numVertexes; i++)
        {
            if(mark[i] == 0 && min > dis[i])
            {
                min = dis[i];
                u = i;
            }
        }

        mark[u] = 1;
        for(i = 0; i < G.numVertexes; i++)
        {
            if(!mark[i] && dis[u] + G.arc[u][i])
            {
                dis[i] = dis[u] + G.arc[u][i];
            }
        }
    }
    //for(y = 0; y < G.numVertexes; y++)
    //{
        printf("最短路径为%d\n",dis[y]);
    //}
}

int main()
{
    //int i = 0;
    int x = 0;
    int y = 0;
    MGraph G;
    MGraph *pG;
    pG = &G;
    CreatMGraph(pG);
    print_graph(G);
    //for(i = 0; i<20; i++)
    //{
        printf("输入源点和终点:\n");
        scanf("%d %d",&x,&y);
        Dijkstra(*pG,x-1,y-1);
    //}
    return 0;
}
