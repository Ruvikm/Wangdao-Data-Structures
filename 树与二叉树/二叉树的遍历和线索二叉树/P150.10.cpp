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

#pragma endregion

//P150.10
//假设二叉树采用二叉链存储结构存储, 设计一个算法, 求先序遍历序列中第k(1≤k≤
//二叉树中结点个数)个结点的值

queue<Node*> q;
stack<Node*> s;

int Count = 1;
void Visit(BiTree& T,int K) {
    if (Count == K)
        cout << T->val;
    Count++;
}

void GetNumK(BiTree& T,int K) {
    if (T) {
        Visit(T,K);
        GetNumK(T->lchild,K);
        GetNumK(T->rchild,K);
    }
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
    int k = 4;
    cout << "先序遍历序列中第" << k << "个结点的值为" << endl;
    GetNumK(T,k);
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