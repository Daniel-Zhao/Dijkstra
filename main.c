#include <stdio.h>
#include <stdlib.h>
#define MAXVEW 100//��󶥵���
#define INFINITY 65536//������

typedef struct
{
    char vexs[MAXVEW];//�����
    int arc[MAXVEW][MAXVEW];//�ڽӾ���
    int numVertexes;//������
    int numEdges;//����
}MGraph;

//����������ͼ���ڽӾ����ʾ
void CreatMGraph(MGraph *G)
{
    int i,j,k,w;//wΪȨֵ
    printf("���붥�����ͱ���:\n");
    scanf("%d %d",&G->numVertexes,&G->numEdges);//���붥�����ͱ���
    fflush(stdin);
    for(i = 0; i < G->numVertexes; i++)//���붥����Ϣ
    {
        scanf("%c",&G->vexs[i]);
        getchar();
    }
    for(i = 0;i < G->numVertexes;i++)
        for(j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;//�ڽӾ����ʼ��
    for(k = 0; k < G->numEdges; k++)//����numEdges���ߣ������ڽӾ���
    {
        printf("�����(vi,vj)�±�i,�±�j��Ȩw:\n");
        scanf("%d %d %d",&i,&j,&w);
        fflush(stdin);
        G->arc[i-1][j-1] = w;
        G->arc[j-1][i-1] = w;//����ͼ
    }
}
void print_graph(MGraph G)
{
    int i,j;
    printf("�ڽӾ�������:\n");
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
    int dis[G.numVertexes];//��С·��
    int mark[G.numVertexes];//����ǵ�
    for(i = 0; i < G.numVertexes; i++)
    {
        mark[i] = 0;
        dis[i] = G.arc[x][i];
    }
    mark[x] = 1;//���Դ��
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
        printf("���·��Ϊ%d\n",dis[y]);
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
        printf("����Դ����յ�:\n");
        scanf("%d %d",&x,&y);
        Dijkstra(*pG,x-1,y-1);
    //}
    return 0;
}
