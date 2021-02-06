#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的二叉树

#define MaxSize 100
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType  weight;
    node* left;
    node* right;
}Node, * BiTree;

void CreateBiTree(BiTree& T)//要改变指针，C++可以把指针的引用传进来
{
    ElemType ch;

    cin >> ch;

    if (ch == -1)
        T = NULL;
    else
    {
        T = new Node;
        T-> weight = ch;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}


void visit(Node* BiNode) {
    cout << BiNode-> weight << " ";
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->left);
        visit(T);
        InOrder(T->right);
    }
}

#pragma endregion

//P151.19
//〖2014统考真题】二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长
//度之和。给定一棵二叉树T, 采用二又链表存储, 结点结构为
//left
//weight
//right
//其中叶结点的weight域保存该结点的非负权值。设root为指向T的根结点的指针,
//请设计求T的WPL的算法, 要求
//1)给出算法的基本设计思想
//2)使用C或C++语言, 给出二叉树结点的数据类型定义。
//3)根据设计思想, 采用C或C + 语言描述算法, 关键之处给出注释

queue<Node*> q;
stack<Node*> s;

int GetWPL(BiTree root, int deep) {
    static int WPL = 0;
    if (!root->left && !root->right)
        WPL += (root->weight) * deep;
    if (root->left)
        GetWPL(root->left, deep + 1);
    if (root->right)
        GetWPL(root->right, deep + 1);
    return WPL;
}

int main()
{
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'-1'表示没有结点:" << endl;
//  input: 1 2 4 8 -1 -1 9 -1 -1 5 -1 10 -1 -1 3 6 -1 11 -1 -1 7 -1 -1
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    cout << "这棵树的WPL为：" << GetWPL(T, 0) << endl;
//  人算过程：(8 + 9 + 10 + 11) * 3 + 7 * 2 = 128
    return 0;
}



/*

                                            1
                            2                               3
                     4             5                 6             7
               8           9 Ø           10    Ø           11 Ø          Ø
              Ø Ø        Ø Ø           Ø Ø              Ø Ø


 树的图片链接：https://s3.ax1x.com/2021/02/03/yKIbiq.png
*/