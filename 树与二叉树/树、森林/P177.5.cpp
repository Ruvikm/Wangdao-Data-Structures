#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的树（孩子兄弟表示法）

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct Node { //树的结点
    ElemType val;
    Node* firstchild;
    Node* nextsibling;
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

void FindX(CSTree T, ElemType X, CSNode*& r) {
    if (T) {
        FindX(T->firstchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->nextsibling, X, r);
    }
}

#pragma endregion

//P177.5
//编程求以孩子兄弟表示法存储的森林的叶子结点数

queue<CSNode*> q;
stack<CSNode*> s;

int GetLeaves(CSTree T) {
    if (!T)
        return 0;
    if (!T->firstchild)
        return 1 + GetLeaves(T->nextsibling);
    else
        return GetLeaves(T->firstchild) + GetLeaves(T->nextsibling);
}

int main()
{
    CSTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点(T1):" << endl;
    //  input(左孩子右兄弟): A B # C # D # # E F # # G H # # I # #
    CreateCSTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    cout << "森林的叶子结点数为：" << GetLeaves(T) << endl;
    return 0;
}

/*

二叉树的孩子兄弟表示：

                                                A
                                        B               E
                                            C       F       G
                                              D            H
                                                            I

                                                            
                                                            
之前的森林为：
                    A                   E                   G
                B   C   D               F                H     I

*/