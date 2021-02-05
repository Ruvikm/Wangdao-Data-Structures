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

#pragma endregion

//P150.12
//在二又树中查找值为x的结点, 试编写算法(用C语言)打印值为x的结点的所有祖
//先, 假设值为x的结点不多于一个。

queue<Node*> q;
stack<Node*> s;

bool FindAncestors(BiTree T,ElemType X) {
    if (!T)
        return false;
    if (T->val == X)
        return true;
    if (FindAncestors(T->lchild, X) || FindAncestors(T->rchild, X)) {
        s.push(T);
        return true;
    }
    return false;
}

void print() {
    while (!s.empty()) {
        cout << s.top()->val << " ";
        s.pop();
    }
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
    char X = 'I';
    FindAncestors(T, X);
    cout << X << "的祖先结点为：" << endl;
    print();
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