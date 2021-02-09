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
    int count = 0;
    node* lchild;
    node* rchild;
}Node, * BST_Tree;

int NodeNum(BST_Tree T) {
    if (!T) {
        return 0;
    }
    return 1 + NodeNum(T->lchild) + NodeNum(T->rchild);
}

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
    BiNode->count = NodeNum(BiNode);
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


//P196.12
//编写一个递归算法,在一棵有n个结点的、随机建立起来的二叉排序树上查找第k(1≤
//≤n)小的元素, 并返回指向该结点的指针。要求算法的平均时间复杂度为O(log2n)
//二叉排序树的每个结点中除data, lchild, child等数据成员外, 增加一个 count
//成员, 保存以该结点为根的子树上的结点个数

Node* Find_KthMin(BST_Tree T, int k) {
    if (k < 1 || k > T->count)
        return NULL;
    if (!T->lchild) {
        if (k == 1)
            return T;
        else
            return Find_KthMin(T->rchild, k - 1);
    }
    else {
        if (T->lchild->count == k - 1)
            return T;
        if (T->lchild->count > k - 1)
            return Find_KthMin(T->lchild, k);
        if (T->lchild->count < k - 1)
            return Find_KthMin(T->rchild, k - (T->lchild->count + 1));
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
    cout << "5th min is :" << " " << Find_KthMin(T, 5)->val << endl;
    return 0;
}

/*

二叉搜索树：

                                            50
                                    38              70
                                30      45      60      75
                                      40  48              80

*/