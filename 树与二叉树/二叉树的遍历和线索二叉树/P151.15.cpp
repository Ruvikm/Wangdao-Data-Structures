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

//P150.15
//设有一棵满二叉树(所有结点值均不同), 已知其先序序列为pre, 设计一个算法求其后
//序序列post

queue<Node*> q;
stack<Node*> s;

void GetPost(string pre, int l1, int h1, string &post, int l2, int h2) {
    int half;
    if (h1 >= l1) {
        post[h2] = pre[l1];
        half = (h1 - l1) / 2;
        GetPost(pre, l1 + 1, l1 + half, post, l2, l2 + half - 1);
        GetPost(pre, l1 + half + 1, h1, post, l2 + half, h2 - 1);
    }
}



int main()
{
    BiTree T;
    string pre = "ABCDEFG";
    string post = "zzzzzzz";
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
//  input(完全二叉树): A B D H # # I # # E G # # K # # C F L # # M # # G N # # #
//  input(完全二叉树): A B C # # D # # E F # # G # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    GetPost(pre, 0, 6, post, 0, 6);
    cout << "二叉树的后序序列为:" << post << endl;
    PostOrder(T);
    return 0;
}

/*

完全二叉树：

                                            A
                            B                               C
                     D             E                 F             G
               H           I G           K     L           M N           Ø

*/