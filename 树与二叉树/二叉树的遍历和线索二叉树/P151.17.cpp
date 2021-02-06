#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的二叉树

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType val;
    node* lchild;
    node* rchild;
}Node, * BiTree;

void CreateBiTree(BiTree& T)//要改变指针，C++可以把指针的引用传进来
{
    ElemType ch;

    cin >> ch;

    if (ch == '#')
        T = NULL;
    else
    {
        T = new Node;
        T->val = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}


void visit(Node* BiNode) {
    cout << BiNode->val << " ";
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void FindX(BiTree T, ElemType X, Node*& r) {
    if (T) {
        FindX(T->lchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->rchild, X, r);
    }
}

#pragma endregion


//P151.17
//试设计判断两棵二叉树是否相似的算法。所谓二叉树T1和T2相似, 指的是T1和T2都是
//空的二叉树或都只有一个根结点; 或T1的左子树和T2的左子树是相似的, 且T1的右子
//树和T2的右子树是相似的

queue<Node*> q;
stack<Node*> s;

bool IsSame(BiTree T1, BiTree T2) {
    if (!T1 && !T2)
        return true;
    else if (!T1 && T2 || T1 && !T2)
        return false;
    else if (!T1->lchild && !T1->rchild && !T2->lchild && !T2->rchild)
        return true;
    else if (IsSame(T1->lchild, T2->lchild) && IsSame(T2->rchild, T2->rchild))
        return true;
    return false;
}



int main()
{
    BiTree T1, T2;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点(T1):" << endl;
//  input(完全二叉树(T1)): A B D H # # I # # E G # # K # # C F L # # M # # G N # # #
    CreateBiTree(T1);
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点(T2):" << endl;
//  input(完全二叉树(T2)): a b d h # # i # # e g # # K # # c f l # # m # # g n # # #
    CreateBiTree(T2);
    cout << "中序遍历T1：" << endl;
    InOrder(T1);
    cout << endl;
    cout << "中序遍历T2：" << endl;
    InOrder(T2);
    cout << endl;
    if (IsSame(T1, T2))
        cout << "相似" << endl;
    else
        cout << "不相似" << endl;
    return 0;
}

/*

完全二叉树：

                                            A
                            B                               C
                     D             E                 F             G
               H           I G           K     L           M N           Ø

*/