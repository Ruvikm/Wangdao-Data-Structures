#include <iostream>
#include <vector>

using namespace std;

#pragma region 构造顺序存储的二叉树

#define MaxSize 100
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

typedef struct
{
    ElemType value;
    bool isEmpty;
}TreeNode;

void InitTree(TreeNode t[MaxSize]) {
    _for(i, 0, MaxSize) {
        t[i].isEmpty = true;
    }
    return;
}

void CreatTree(TreeNode t[MaxSize], vector<int> input) {
    _for(i, 1, input.size()) {
        t[i].value = input[i];
        if (input[i] != -1) {
            t[i].isEmpty = false;
        }
    }
    return;
}


void PreOrder(TreeNode t[MaxSize], int i) {
    if (!t[i].isEmpty)
        cout << t[i].value << " ";
    if (!t[2 * i].isEmpty)
        PreOrder(t, 2 * i);
    if (!t[2 * i + 1].isEmpty)
        PreOrder(t, 2 * i + 1);
    return;
}

#pragma endregion

//P134.5
//已知一棵二叉树按顺序存储结构进行存储, 设计一个算法, 求编号分别为i和j的两个结
//的最近的公共祖先结点的值

int FindCom_Ancestor(TreeNode t[MaxSize], int i, int j) {

    if (!t[i].isEmpty && !t[j].isEmpty) {
        while (i != j) {
            if (i > j)
                i /= 2;
            else
                j /= 2;
        }
    }
    return t[i].value;
}

int main()
{
    TreeNode t[MaxSize];
    vector<int> input{ -1,1,2,3,4,5,6,7,8,9,10,-1,12,-1,-1,15 };
    InitTree(t);
    CreatTree(t, input);
    PreOrder(t,1);
    cout << endl;
    cout << "公共祖先为：" << FindCom_Ancestor(t, 10, 4) << endl;
    return 0;
}
/* 

生成的二叉树:

              1
        2           3
    4      5    6       7
  8   9 10    12         15

*/