#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

//P323.2
//编写双向冒泡排序算法, 在正反两个方向交替进行扫描, 即第一趟把关键字最大的元素
//放在序列的最后面, 第二趟把关键字最小的元素放在序列的最前面, 如此反复进行。

void BubbleSort(vector<ElemType> &A) {

    int low = 0, high = A.size() - 1;
    bool flag = true;
    while (low < high && flag) {

        flag = false;
        _for(i, low, high) {
            if (A[i] > A[i + 1]) {
                swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        high--;
        for (int i = high; i > low; i--) {
            if (A[i] < A[i - 1]) {
                swap(A[i], A[i - 1]);
                flag = true;
            }
        }
        low++;
    }
}

void Print(vector<ElemType> A) {
    _for(i, 0, A.size()) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<ElemType> A{ 2,5,21,54,64,12,65,34,12,37,21 };
    cout << "排序前：" << endl;
    Print(A);
    BubbleSort(A);
    cout << "排序后：" << endl;
    Print(A);
    return 0;
}

