#include <iostream>

using namespace std;

#pragma region 创建邻接表存储的无向图

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
        cout << "输入第" << k + 1 << "条边的顶点：" << endl;
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

        e = new ArcNode;
        if (!e) {
            cout << "内存申请失败！" << endl;
            exit(0);
        }
        e->adjvex = vi;
        e->next = G.vertices[vj].first;
        G.vertices[vj].first = e;
    }
}

bool visited[MaxVertexNum];

void DFS(ALGraph G, int i) {         //邻接表的深度优先递归

    ArcNode* p;
    visited[i] = true;         		//访问过了该顶点，标记为TRUE 
    cout << G.vertices[i].data << " ";
    p = G.vertices[i].first;        //让p指向边表第一个结点 
    while (p) {                     //在边表内遍历 
        if (!visited[p->adjvex])    //对未访问的邻接顶点递归调用 
            DFS(G, p->adjvex);
        p = p->next;
    }
}

void DFSTraverse(ALGraph G) {        //邻接表的深度遍历操作
    _for(i, 0, G.vexnum)
        visited[i] = false;         //初始设置为未访问 
    _for(i, 0, G.vexnum)
        if (!visited[i])
            DFS(G, i);	            //对未访问的顶点调用DFS，若是连通图只会执行一次 			
}

#pragma endregion

//P232.2
//试设计一个算法, 判断一个无向图G是否为一棵树。若是一棵树, 则算法返回true
//否则返回false

bool visit[MaxVertexNum];
int Enum = 0, Vnum = 0;

void DFS_2(ALGraph G, int i) {         //邻接表的深度优先递归

    ArcNode* p;
    visit[i] = true;         		//访问过了该顶点，标记为TRUE 
    Vnum++;
    p = G.vertices[i].first;        //让p指向边表第一个结点 
    while (p) {                     //在边表内遍历 
        Enum++;
        if (!visit[p->adjvex])    //对未访问的邻接顶点递归调用 
            DFS_2(G, p->adjvex);
        p = p->next;
    }
}

bool isTree(ALGraph G) {

    memset(visit, false, sizeof(visit));
    DFS_2(G, 1);
    if (G.vexnum == Vnum && Enum == 2 * (G.vexnum - 1))
        return true;
    else 
        return false;
}

int main()
{
    ALGraph G;
    CreateALGraph(G);
    cout << endl;
    cout << "DFS:" << endl;
    DFSTraverse(G);
    cout << endl;
    if (isTree(G))
        cout << "图G是一棵树" << endl;
    else
        cout << "图G不是一棵树" << endl;
    return 0;
}

/*
input:

5 7
a b c d e
a b
a e
b c
b d
b e
c d
d e


生成图的链接：https://s3.ax1x.com/2021/02/18/yW59vF.png

普通的树：

7 6
a b c d e f g
a b
a c
a d
b e
b f
d g


                                            a
                                        b   c   d
                                       e f        g

*/