#include <iostream>
#include <stack>

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

//P232.3
//写出图的深度优先搜索DFS算法的非递归算法(图采用邻接表形式)。
 
bool visit[MaxVertexNum];

void DFS_Non_RC(ALGraph& G, int v) {
    
    memset(visit, false, sizeof(visit));
    stack<int> s;
    s.push(v);
    visit[v] = true;
    while (!s.empty()) {
        ArcNode* p = G.vertices[s.top()].first;
        cout << G.vertices[s.top()].data << " ";
        s.pop();
        while (p) {                     
            if (!visit[p->adjvex]) {
                s.push(p->adjvex);
                visit[p->adjvex] = true;
            }
            p = p->next;
        }
    }
}

int main()
{
    ALGraph G;
    CreateALGraph(G);
    cout << endl;
    cout << "DFS:" << endl;
    DFSTraverse(G);
    cout << endl;
    DFS_Non_RC(G, 0);
    return 0;
}

/*

PS:
答案是对的，至于为什么两个DFS顺序不一样
是因为非递归DFS遍历用头插法插入的边表（逆置的）时
存入栈中正好把顺序给正过来了。

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

*/