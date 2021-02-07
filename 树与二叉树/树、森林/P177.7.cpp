#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#pragma region 构造链式存储的树（孩子兄弟表示法）

#define MaxSize 100
#define ElemType int 
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct CSNode { //树的结点
    ElemType val;
    CSNode* firstchild;
    CSNode* nextsibling;
}CSNode, * CSTree;

void CreateCSTree(CSTree& T)//要改变指针，C++可以把指针的引用传进来
{
    ElemType ch;

    cin >> ch;

    if (ch == '#')
        T = NULL;
    else
    {
        T = new CSNode;
        T->val = ch;
        CreateCSTree(T->firstchild);
        CreateCSTree(T->nextsibling);
    }
}


void visit(CSNode* BiCSNode) {
    cout << BiCSNode->val << " ";
}

void InOrder(CSTree T) {
    if (T) {
        InOrder(T->firstchild);
        visit(T);
        InOrder(T->nextsibling);
    }
}

void PostOrder(CSTree T) {
    if (T) {
        PostOrder(T->firstchild);
        PostOrder(T->nextsibling);
        visit(T);
    }
}

void PreOrder(CSTree T) {
    if (T) {
        visit(T);
        PreOrder(T->firstchild);
        PreOrder(T->nextsibling);
    }
}

void LevelOrders(CSTree T) {
    queue<CSNode*> q;
    q.push(T);
    while (!q.empty()) {
        CSNode* node = q.front();
        visit(node);
        if (node->firstchild)
            q.push(node->firstchild);
        if (node->nextsibling)
            q.push(node->nextsibling);
        q.pop();
    }
}

void FindX(CSTree T, ElemType X, CSNode*& r) {
    if (T) {
        FindX(T->firstchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->nextsibling, X, r);
    }
}

#pragma endregion

//P177.7
//已知一棵树的层次序列及每个结点的度, 编写算法构造此树的孩子 - 兄弟链表

#define MaxNode 15

void CreateCSTree_Degree(CSTree& T, int levelOrder[], int degree[], int length) {

    CSNode* pointer = new CSNode[length];
    _for(i, 0, length) {
        pointer[i].val = levelOrder[i];
        pointer[i].firstchild = pointer[i].nextsibling = NULL;
    }
    int NodeID = 0;
    _for(i, 0, length) {
        int d = degree[i];
        if (d) {
            NodeID++;
            pointer[i].firstchild = &pointer[NodeID];
            for (int j = 2; j <= d; j++) {
                NodeID++;
                pointer[NodeID - 1].nextsibling = &pointer[NodeID];
            }
        }
    }
    T = &pointer[0];
}


int main()
{
    CSTree T;
    int length = 9;
    int levelOrder[9] = { 3, 2, 1, 5, 4, 6, 8, 7, 9 };
    int degree[9] = { 3, 2, 0, 1, 1, 0, 1, 0, 0 };
    CreateCSTree_Degree(T, levelOrder, degree, length);
    cout << "先序遍历：" << endl;
    PreOrder(T);
    return 0;
}

/*

                                            3
                                        2   1   5
                                      4  6        8
                                    7               9


参考了大佬的文章：https://blog.csdn.net/qinglingls/article/details/110786988
*/