#include <iostream>
#include <stack>
using namespace std;

#pragma region 构造链式存储的二叉树

#define MaxSize 100
#define ElemType char
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct node { //树的结点
    ElemType val;
    node* lchild;
    node* rchild;
}Node, *BiTree;

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

void InOrder(BiTree T){
    if (T != NULL) {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}

#pragma endregion

//P149.3
//编写后序遍历二叉树的非递归算法。

stack<Node*> s;

void PostOrder(BiTree T) {
    BiTree p = T, r = NULL;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->lchild;
        }
        else {
            p = s.top();
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
                s.push(p);
                p = p->lchild;
            }
            else {
                Node* q = s.top();
                s.pop();
                visit(q);
                r = q;
                p = NULL;
            }
        }
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
    cout << "非递归后序遍历：" << endl;
    PostOrder(T);
    cout << endl;
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