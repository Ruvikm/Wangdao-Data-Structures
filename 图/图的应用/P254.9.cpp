#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#pragma region 创建邻接表存储的有向图

#define MaxVertexNum 10   //图中顶点数目最大值
#define VertexType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct ArcNode {    //边表结点
    int adjvex;             //该弧所指向的顶点的位置
    ArcNode* next;          //指向下一条弧的指针
}ArcNode;

typedef struct VNode {      //顶点表结点
    VertexType data;        //顶点信息
    ArcNode* first;         //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct {
    AdjList vertices;       //领接表
    int vexnum, arcnum;     //图的顶点数和弧数
}ALGraph;                   //ALGraph是以邻接表存储的图类型


int LocateVex(ALGraph& G, VertexType x) {

    _for(i, 0, G.vexnum) {
        if (G.vertices[i].data == x)
            return i;
    }
    return -1;
}

void CreateALGraph(ALGraph& G) {

    cout << "输入顶点数和边数" << endl;
    cin >> G.vexnum >> G.arcnum;
    _for(i, 0, G.vexnum) {
        cout << "输入第" << i + 1 << "个顶点的信息" << endl;
        cin >> G.vertices[i].data;
        G.vertices[i].first = NULL;
    }
    _for(k, 0, G.arcnum) {
        VertexType e1, e2;
        cout << "输入第" << k + 1 << "条边（v1 -> v2）的顶点：" << endl;
        cin >> e1 >> e2;
        ArcNode* e = new ArcNode;
        if (!e) {
            cout << "内存申请失败！" << endl;
            exit(0);
        }

        int vi = LocateVex(G, e1);
        int vj = LocateVex(G, e2);

        e->adjvex = vj;									//这三步，类似于单链表的头插法
        e->next = G.vertices[vi].first;
        G.vertices[vi].first = e;
    }
}

#pragma endregion

//P254.9
//试说明利用DFS如何实现有向无环图拓扑排序

bool visited[MaxVertexNum];
int topo[MaxVertexNum];
int j = 0;

void DFS(ALGraph G, int i) {         

    ArcNode* p;
    visited[i] = true;         		
    p = G.vertices[i].first;       
    while (p) {                    
        if (!visited[p->adjvex])    
            DFS(G, p->adjvex);
        p = p->next;
    }
    topo[j++] = i;
}

void DFSTraverse(ALGraph G) {

    memset(visited, false, sizeof(visited));      
    _for(i, 0, G.vexnum)
        if (!visited[i])
            DFS(G, i);	            			
}

void Print_TopologicalSorting(ALGraph G) {
    for (int i = G.vexnum - 1; i >= 0; i--) {
        cout << G.vertices[topo[i]].data << " ";
    }
    cout << endl;
}


int main()
{
    ALGraph G;
    CreateALGraph(G);
    cout << "DFS求拓扑排序:" << endl;
    DFSTraverse(G);
    Print_TopologicalSorting(G);
    return 0;
}

/*
input:

6 7
a b c d e f
a b
a d
c e
c f
d b
e d
f f

有向图链接：https://s3.ax1x.com/2021/02/23/yLASpT.png

*/