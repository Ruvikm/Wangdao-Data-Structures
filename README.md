2021王道数据结构课后大题代码，使用Visual Studio 2019编程。 记录一下自己重学数据结构的历程，也当做一个回忆啦~  
 代码仅供个人研究，及交流学习使用，版权归原作者所有，如果有侵犯到您的权利，请及时联系删除。  

可不可以点个star呢~

已完结的章节：  
第二章 线性表  
第三章 栈和队列  
第五章 树与二叉树  
第六章 图  
第七章 查找  
第八章 排序  
  
全书更新完毕~  
好耶~   

PS:
第一章绪论与第四章串课后没有需要代码实现的题 

历时3个多月，把21版王道数据结构的课后代码题全部实现了一遍，一共96道题

![题目总数](https://img-blog.csdnimg.cn/2021031610114889.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3J1dmlrbQ==,size_16,color_FFFFFF,t_70#pic_center)

![3个月](https://img-blog.csdnimg.cn/20210316101716209.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3J1dmlrbQ==,size_16,color_FFFFFF,t_70#pic_center)

 - 编程环境：Visual Studio 2019
 - 编程语言：C/C++

其中，每道题都是一个独立的cpp文件，可以独立运行。在树和图的章节，会有输入样例和对应的示例图。

cpp文件结构

 1. 建立要求的数据结构
 2. 题目说明
 3. 题目要求的代码
 4. 运行示例

以树章节的题目示例：

```cpp
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
```


emm也是记录一下考研期间重新学习数据结构的过程，留个回忆~
一定要一战成硕啊！

顺便点个star呗~

