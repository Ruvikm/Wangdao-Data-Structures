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

void FindX(BiTree T,ElemType X,Node* &r) {
    if (T) {
        FindX(T->lchild,X,r);
        if (T->val == X)
            r = T;
        FindX(T->rchild,X,r);
    }
}

#pragma endregion

//P150.13
//设一棵二叉树的结点结构为(LLINK, INFO, RLINK), ROOT为指向该二叉树根结点的
//指针, p和q分别为指向该二叉树中任意两个结点的指针, 试编写算法
//ANCESTOR(ROOT, p, q, r), 找到p和q的最近公共祖先结点r。

queue<Node*> q1, q2;
stack<Node*> s1, s2;

bool FindAncestors(BiTree T, Node* X, queue<Node*> &q) {
    if (!T)
        return false;
    if (T == X)
        return true;
    if (FindAncestors(T->lchild, X, q) || FindAncestors(T->rchild, X, q)) {
        q.push(T);
        return true;
    }
    return false;
}

void ANCESTOR(BiTree ROOT, Node* p, Node* q, Node* &r) {
    FindAncestors(ROOT, p, q1);
    FindAncestors(ROOT, q, q2);
    while (!q1.empty() && !q2.empty() && q1.front() != q2.front()) {
        q1.pop();
    }
    r = q1.front();
    return;
}



int main()
{
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
    //  input: A B D H # # I # # E # J # # C F # K # # G # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    Node* p = NULL, * q = NULL;
    FindX(T, 'K', p);
    FindX(T, 'G', q);
    Node* r = NULL;
    ANCESTOR(T, p, q, r);
    cout << p->val << "和" << q->val << "的最近公共祖先结点为：" << r->val << endl;
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