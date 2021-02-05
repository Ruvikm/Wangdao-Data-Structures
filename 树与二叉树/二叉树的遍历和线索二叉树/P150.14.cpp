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

void FindX(BiTree T, ElemType X, Node*& r) {
    if (T) {
        FindX(T->lchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->rchild, X, r);
    }
}

#pragma endregion

//P150.14
//假设二叉树采用二叉链表存储结构, 设计一个算法, 求非空二叉树b的宽度(即具有结
//点数最多的那一层的结点个数

queue<Node*> q;
stack<Node*> s;

int GetWidth(BiTree T) {
    int width = 0;
    int Nowidth = 1;
    BiTree front, last;
    front = last = T;
    q.push(T);
    while (!q.empty()) {
        front = q.front();
        if (front->lchild) {
            q.push(front->lchild);
            Nowidth++;
        }
        if (front->rchild) {
            q.push(front->rchild);
            Nowidth++;
        }
        if (front == last) {
            if (Nowidth > width)
                width = Nowidth;
            Nowidth = 0;
            last = q.back();
        }
        q.pop();
    }
    return width;
}



int main()
{
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
//  input(普通二叉树): A B D H # # I # # E # J # # C F # K # # G # #
//  input(完全二叉树): A B D H # # I # # E G # # K # # C F L # # M # # G N # # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    cout << "二叉树的宽度为:" << GetWidth(T) << endl;
    return 0;
}

/*

完全二叉树：

                                            A
                            B                               C
                     D             E                 F             G
               H           I G           K     L           M N           Ø


普通二叉树：


                                            A
                            B                               C
                     D             E                 F             G
               H           I Ø           J    Ø           K Ø           Ø
              Ø Ø        Ø Ø           Ø Ø              Ø Ø


 普通二叉树的图片链接：https://s3.ax1x.com/2021/02/03/yKIbiq.png

*/