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


//P195.8
//利用二叉树遍历的思想编写一个判断二叉树是否是平衡二叉树的算法

void IsBBT(BST_Tree T,int &balance,int &h) {
    int bl, br, hl, hr;
    bl = br = hl = hr = 0;
    if (!T) {
        h = 0;
        balance = 1;
    }
    else if (!T->lchild && !T->rchild) {
        h = 1;
        balance = 1;
    }
    else {
        IsBBT(T->lchild, bl, hl);
        IsBBT(T->rchild, br, hr);
        h = (hl > hr ? hl : hr) + 1;
        if (abs(hl - hr) < 2) {
            balance = bl && br;
        }
        else {
            balance = 0;
        }
    }
}

bool Judge_AVL(BST_Tree T) {
    int balance = 0, h = 0;
    IsBBT(T, balance, h);
    if (balance) {
        cout << "是二叉平衡树" << endl;
        return true;
    }
    else {
        cout << "不是二叉平衡树" << endl;
        return false;
    }

}



int main()
{
    BST_Tree T;
    /*vector<int> input{ 50,38,53};*/
    vector<int> input{ 50,38,30,20 };
    /*vector<int> input{ 50,38,30,45,40,48,70,60,75,80 };*/
    CreateBST_Tree(T, input);
    /* CreateBiTree(T);*/
     //  input(普通的树): 1 2 4 8 -1 -1 9 -1 -1 5 -1 10 -1 -1 3 6 -1 11 -1 -1 7 -1 -1
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    Judge_AVL(T);
    return 0;
}

/*

二叉搜索树：

                                            50
                                    38              70
                                30      45      60      75
                                      40  48              80

*/