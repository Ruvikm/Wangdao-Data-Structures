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

//P177.6
//以孩子兄弟链表为存储结构,请设计递归算法求树的深度

queue<CSNode*> q;
stack<CSNode*> s;

int GetDepth(CSTree T)
{
    if (!T)
        return 0;
    else
        return max(1 + GetDepth(T->firstchild), GetDepth(T->nextsibling));
}


int main()
{
    CSTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点(T1):" << endl;
//  input(左孩子右兄弟): A B # C # D # # E F # # G H # # I # #
    CreateCSTree(T);
    cout << "树的深度为：" << GetDepth(T) << endl;
    return 0;
}

/*

二叉树的孩子兄弟表示：

                                                A
                                        B               E
                                            C       F       G
                                              D            H
                                                            I


所求的其实就是把二叉树转换成森林，森林中树的最大深度
之前的森林为：
                    A                   E                   G
                B   C   D               F                H     I

*/