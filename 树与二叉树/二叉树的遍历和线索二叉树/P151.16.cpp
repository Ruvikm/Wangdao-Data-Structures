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


//P151.16
//设计一个算法将二叉树的叶结点按从左到右的顺序连成一个单链表, 表头指针为head
//二叉树按二叉链表方式存储, 链接时用叶结点的右指针域来存放单链表指针

queue<Node*> q;
stack<Node*> s;


BiTree Pre;
void PutInList(BiTree T,BiTree &head) {

    if (T) {
        if (!T->lchild && !T->rchild) {
            cout << "data:" << T->val << endl;
            if (!Pre) {
                head = T;
                Pre = head;
            }
            else {
                Pre->rchild = T;
                Pre = Pre->rchild;
            }
        }
        PutInList(T->lchild,head);
        PutInList(T->rchild,head);
    }
    return;
}


int main()
{
    BiTree head;
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
//  input(完全二叉树): A B D H # # I # # E G # # K # # C F L # # M # # G N # # #
//  input(完全二叉树): A B C # # D # # E F # # G # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    PutInList(T, head);
    return 0;
}

/*

完全二叉树：

                                            A
                            B                               C
                     D             E                 F             G
               H           I G           K     L           M N           Ø

*/