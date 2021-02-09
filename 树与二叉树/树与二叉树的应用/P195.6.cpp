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
        FindX(T->lchild, X, r);
        if (T->val == X)
            r = T;
        FindX(T->rchild, X, r);
    }
}

#pragma endregion


//P195.6
//试编写一个算法, 判断给定的二叉树是否是二叉排序树

ElemType pre = INT_MIN;
bool IsBST(BST_Tree T) {
    if (!T) {
        return true;
    }
    else {
        if (!IsBST(T->lchild) || pre > T->val) {
            return false;
        }
        pre = T->val;
        return IsBST(T->rchild);
    }
}

int main()
{
    BST_Tree T;
    vector<int> input{ 50,38,30,45,40,48,70,60,75,80 };
    //CreateBST_Tree(T, input);
    CreateBiTree(T);//创建普通的树
    //  input(普通的树): 1 2 4 8 -1 -1 9 -1 -1 5 -1 10 -1 -1 3 6 -1 11 -1 -1 7 -1 -1
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    if (IsBST(T))
        cout << "是二叉搜索树" << endl;
    else
        cout << "不是二叉搜索树" << endl;
    return 0;
}

/*

二叉搜索树：

                                            50
                                    38              70
                                30      45      60      75
                                      40  48              80

*/