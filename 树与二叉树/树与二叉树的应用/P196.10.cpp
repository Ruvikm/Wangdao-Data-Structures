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


//P196.10
//设计一个算法,从大到小输出二叉排序树中所有值不小于k的关键字

void NotLessThan_K(BST_Tree T, int k) {

    if (T) {
        NotLessThan_K(T->rchild, k);
        if (T->val >= k)
            cout << T->val<<" ";
        NotLessThan_K(T->lchild, k);
    }
}


int main()
{
    BST_Tree T;
    vector<int> input{ 50,38,30,45,40,48,70,60,75,80 };
    CreateBST_Tree(T, input);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    cout << "不小于56的值有:" << endl;
    NotLessThan_K(T, 56);
    return 0;
}

/*

二叉搜索树：

                                            50
                                    38              70
                                30      45      60      75
                                      40  48              80

*/