#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#pragma region 构造链式存储的二叉搜索树

#define MaxSize 100
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType val;
    node* lchild;
    node* rchild;
}Node, * BST_Tree;

void CreateBiTree(BST_Tree& T)//要改变指针，C++可以把指针的引用传进来
{
    ElemType ch;

    cin >> ch;

    if (ch == -1)
        T = NULL;
    else
    {
        T = new Node;
        T->val = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

bool BST_Insert(BST_Tree& T, ElemType X) {
    if (!T) {
        T = new Node;
        T->val = X;
        T->lchild = T->rchild = NULL;
        return true;
    }
    else if (T->val == X)
        return false;
    else if (T->val > X) {
        return BST_Insert(T->lchild, X);
    }
    else
        return BST_Insert(T->rchild, X);
}

void CreateBST_Tree(BST_Tree& T, vector<int> input) {

    T = NULL;
    _for(i, 0, input.size())
        BST_Insert(T, input[i]);
}


void visit(Node* BiNode) {
    cout << BiNode->val << " ";
}

void InOrder(BST_Tree T) {
    if (T) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BST_Tree T) {
    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

void FindX(BST_Tree T, ElemType X, Node*& r) {
    if (T) {
        while (T->val != X) {
            if (X < T->val)
                T = T->lchild;
            else
                T = T->rchild;
        }
        r = T;
    }
}

#pragma endregion


//P196.9
//设计一个算法,求出给定二叉排序树中最小和最大的关键字

void BestValue(BST_Tree T,int &min,int &max) {
    BST_Tree p = T, q = T;
    while (p->lchild) {
        p = p->lchild;
    }
    while (q->rchild) {
        q = q->rchild;
    }
    min = p->val;
    max = q->val;
}


int main()
{
    BST_Tree T;
    vector<int> input{ 50,38,30,45,40,48,70,60,75,80 };
    CreateBST_Tree(T, input);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    int min = 0, max = 0;
    BestValue(T, min, max);
    cout << "MIN:" << min << endl;
    cout << "MAX:" << max << endl;
    return 0;
}

/*

二叉搜索树：

                                            50
                                    38              70
                                30      45      60      75
                                      40  48              80

*/