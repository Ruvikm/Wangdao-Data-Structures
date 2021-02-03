#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;

#pragma region 构造链式存储的完全二叉树

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

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

#pragma endregion

//P150.7
//二又树按二叉链表形式存储, 写一个判别给定二叉树是否是完全二叉树的算法

queue<Node*> q;
stack<Node*> s;

bool Judge_Comtrees(BiTree T) {
    q.push(T);
    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
        if (t) {
            q.push(t->lchild);
            q.push(t->rchild);
        }
        else {
            while (!q.empty()) {
                Node* x = q.front();
                q.pop();
                if (x)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    BiTree T;
    cout << "请输入先序遍历顺序下各个结点的值,'#'表示没有结点:" << endl;
//  input(完全二叉树): A B D H # # I # # E G # # K # # C F L # # M # # G N # # #
//  input(普通二叉树): A B D H # # I # # E # J # # C F # K # # G # #
    CreateBiTree(T);
    cout << "中序遍历：" << endl;
    InOrder(T);
    cout << endl;
    if (Judge_Comtrees(T))
        cout << "是完全二叉树" << endl;
    else
        cout << "不是完全二叉树" << endl;
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