#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
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
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

#pragma endregion

//P149.6
//设一棵二又树中各结点的值互不相同,其先序遍历序列和中序遍历序列分别存于两个
//维数组A[1…n]和B[1…n]中, 试编写算法建立该二叉树的二叉链表

queue<Node*> q;
stack<Node*> s;

BiTree BuildTree(string A, string B, int l1, int h1, int l2, int h2) {

    //  A = "ABDHIEJCFKG", B = "HDIBEJAFKCG";
    BiTree root = new Node;
    root->val = A[l1];
    int i;
    for (i = l2; B[i] != root->val; i++);
    int llen = i - l2;
    int rlen = h2 - i;
    if (llen)
        root->lchild = BuildTree(A, B, l1 + 1, l1 + llen, l2, l2 + llen - 1);
    else
        root->lchild = NULL;
    if (rlen)
        root->rchild = BuildTree(A, B, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
    else
        root->rchild = NULL;
    return root;
}

int main()
{
    BiTree T;
//  cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
    string Pre = "ABDHIEJCFKG", In = "HDIBEJAFKCG";
//  input: A B D H # # I # # E # J # # C F # K # # G # #
//  CreateBiTree(T);
    T = BuildTree(Pre, In, 0, Pre.size() - 1, 0, In.size() - 1);
    cout << "后序遍历验证：" << endl;
    PostOrder(T);
    cout << endl;
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