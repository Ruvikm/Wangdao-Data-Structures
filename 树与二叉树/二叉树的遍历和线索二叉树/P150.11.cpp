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

//P150.11
//已知二叉树以二叉链表存储, 编写算法完成:对于树中每个元素值为x的结点, 删去以
//它为根的子树, 并释放相应的空间

queue<Node*> q;
stack<Node*> s;

void DeleteNode(BiTree &T) {
    if (T) {
        DeleteNode(T->lchild);
        DeleteNode(T->rchild);
        delete T;
    }
}

void DeleteX(BiTree& T, ElemType X) {
    q.push(T);
    while (!q.empty()) {
        BiTree p = q.front();
        q.pop();
        if (p->lchild) {
            if (p->lchild->val == X) {
                DeleteNode(p->lchild);
                p->lchild = NULL;
            }
            else
                q.push(p->lchild);
        }
        if (p->rchild) {
            if (p->rchild->val == X) {
                DeleteNode(p->rchild);
                p->rchild = NULL;
            }
            else
                q.push(p->rchild);
        }

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
    char X = 'D';
    cout << "删除" << X << "后中序遍历为" << endl;
    DeleteX(T, X);
    InOrder(T);
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