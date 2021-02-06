#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的中序线索化的二叉树

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType val;
    node* lchild, *rchild;
    bool ltag, rtag;
}Node, * ThreadTree;

void CreateBiTree(ThreadTree& T)//要改变指针，C++可以把指针的引用传进来
{
    ElemType ch;

    cin >> ch;

    if (ch == '#')
        T = NULL;
    else
    {
        T = new Node;
        T->val = ch;
        T->ltag = T->rtag = false;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void InThread(ThreadTree& p, ThreadTree& pre) {
    if (p) {
        InThread(p->lchild, pre);
        if (!p->lchild) {
            p->lchild = pre;
            p->ltag = true;
        }
        if (pre && !pre->rchild) {
            pre->rchild = p;
            pre->rtag = true;
        }
        pre = p;
        InThread(p->rchild, pre);
    }
}

void CreateInThread(ThreadTree T) {
    ThreadTree pre = NULL;
    if (T) {
        InThread(T, pre);
        pre->rchild = NULL;
        pre->rtag = true;
    }
}

void visit(Node* BiNode) {
    cout << BiNode->val << " ";
}

Node* FirstNode(Node* p) {
    while (!p->ltag)
        p = p->lchild;
    return p;
}

Node* NextNode(Node* p) {
    if (!p->rtag)
        return FirstNode(p->rchild);
    else
        return p->rchild;
}

void InOrder(ThreadTree T) {
    for (ThreadTree p = FirstNode(T); p != NULL; p = NextNode(p))
        visit(p);
}

void PostOrder(ThreadTree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void FindX(ThreadTree T, ElemType X, Node*& r) {
    for (ThreadTree p = FirstNode(T); p != NULL; p = NextNode(p))
        if (p->val == X) {
            r = p;
            break;
        }
    return;
}

#pragma endregion

//P151.18
//写出在中序线索二叉树里查找指定结点在后序的前驱结点的算法
//PS:好家伙这题居然没有视频讲解
queue<Node*> q;
stack<Node*> s;

void FindPre(ThreadTree P, ThreadTree& Pre) {

    if (!P)
        Pre = NULL;
    else if (!P->rtag)
        Pre = P->rchild;
    else if (P->rtag && !P->ltag)
        Pre = P->lchild;
    else {
        while (P && P->ltag)
            P = P->lchild;
        if (P)
            Pre = P->lchild;
        else
            Pre = NULL;
    }
    return;
}


int main()
{
    ThreadTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点(T1):" << endl;
    //  input: A B D H # # I # # E # J # # C F # K # # G # #
    CreateBiTree(T);
    CreateInThread(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    ThreadTree Pre;
    Node* r;
    char x = 'J';
    FindX(T, x, r);
    FindPre(r, Pre);
    if (Pre)
        cout << x << "的后序前驱为：" << Pre->val << endl;
    else
        cout << "没有找到" << x << "的后序前驱" << endl;
    return 0;
}

/*

                                            A
                            B                               C
                     D             E                 F             G
               H           I Ø           J    Ø           K Ø           Ø
              Ø Ø        Ø Ø           Ø Ø              Ø Ø


 树的图片链接：https://s3.ax1x.com/2021/02/03/yKIbiq.png
*/