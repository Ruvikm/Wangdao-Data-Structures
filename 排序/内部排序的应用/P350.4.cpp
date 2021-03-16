#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ElemType int

//P350.4
//设有一个数组中存放了一个无序的关键序列K1, K2, …, Kn。现要求将Kn放在将元素排序
//后的正确位置上, 试编写实现该功能的算法, 要求比较关键字的次数不超过n。

//快排
int Partition(vector<ElemType> &A,int low,int high) {
    int pivot = A[high];
    while (low < high) {
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
    }
    A[high] = pivot;
    return low;
}

void QuickSort(vector<ElemType>& A, int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

void Print(vector<ElemType> A) {
    for (int i = 1; i <= A.size() - 1; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<ElemType> A = { 61,2,5,21,24,64,12,15,34,32,47,9 };
    cout << "排序前：" << endl;
    Print(A);
    QuickSort(A, 0, A.size() - 1);
    cout << "排序后：" << endl;
    Print(A);
    return 0;
}

