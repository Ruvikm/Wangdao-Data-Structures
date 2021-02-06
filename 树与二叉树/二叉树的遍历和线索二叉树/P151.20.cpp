#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的表达式二叉树

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType  data[10];
    node* left;
    node* right;
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
        T->data[0] = ch;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}


void visit(Node* BiNode) {
    cout << BiNode->data[0] << " ";
}

void InOrder(BiTree T) {
    if (T) {
        InOrder(T->left);
        visit(T);
        InOrder(T->right);
    }
}

#pragma endregion

//P151.20
//【2017统考真题】请设计一个算法, 将给定的表达式树(二叉树)转换为等价的中缀表
//达式(通过括号反映操作符的计算次序)并输出。例如, 当下列两棵表达式树作为算法
//的输入时输出的等价中缀表达式分别为(a+b)*(c*(-d))和(a*b)+(-(c-α))
//二叉树结点定义如下：
//typedef struct node {
//      char data[10];   //存储操作数或操作符
//      struct node* left,*right;
//}BTree
//要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++语言描述算法, 关键之处给出注释。


queue<Node*> q;
stack<Node*> s;

void MedEx(BiTree T,int deep) {
    
    if (!T)
        return;
    else if (!T->left && !T->right)
        cout << T->data[0];
    else {
        if (deep > 1)
            cout << "(";
        MedEx(T->left, deep + 1);
        cout << T->data[0];
        MedEx(T->right, deep + 1);
        if (deep > 1)
            cout << ")";
    }
}

void ToMedEx(BiTree T) {
    MedEx(T, 1);
}

int main()
{
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
//  input(1): * + a # # b # # * c # # - # d # #
//  input(2): + * a # # b # # - # - c # # d # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    ToMedEx(T);
    return 0;
}



/*
(1)

                                        *
                                     +     *
                                    a b   c -
                                             d
(2)
                                        +
                                    *       _
                                  a   b        -
                                             c   d
                                         


*/