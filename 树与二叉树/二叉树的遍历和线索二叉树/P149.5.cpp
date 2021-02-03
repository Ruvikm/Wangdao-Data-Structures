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
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

#pragma endregion

//P149.5
//假设二叉树采用二叉链表存储结构,设计一个非递归算法求二叉树的高度

queue<Node*> q;
stack<Node*> s;
//非递归
int GetHeight(BiTree T) {
    if (!T)
        return 0;
    int level = 0;
    Node* front, * last;
    last = front = T;
    q.push(T);
    while (!q.empty()) {
        front = q.front();
        if (front->lchild)
            q.push(front->lchild);
        if (front->rchild)
            q.push(front->rchild);
        if (front == last) {
            level++;
            last = q.back();
        }
        q.pop();
    }
    return level;
}

//递归
int GetH(BiTree T) {
    if (T == NULL)
        return 0;
    int Lh = GetH(T->lchild);
    int Lr = GetH(T->rchild);
    return Lh > Lr ? (Lh + 1) : (Lr + 1);
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
    //cout << "树的高度为：" << GetH(T) << endl;
    cout << "树的高度为：" << GetHeight(T) << endl;
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