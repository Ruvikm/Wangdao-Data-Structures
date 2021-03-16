#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

//P349.2
//设顺序表用数组A[]表示, 表中元素存储在数组下标1 --- (m + n)的范围内, 前m个元素
//递增有序, 后n个元素递增有序, 设计一个算法, 使得整个顺序表有序
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C/C++描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度与空间复杂度。

//归并排序
void MergeSort(vector<ElemType> &A, int m, int n) {

    vector<ElemType> B(m + n + 1);
    int i = 1, j = m + 1, k = 1;
    while (i <= m && j <= m + n) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        }   
        else {
            B[k++] = A[j++];
        }
    }
    while (i <= m) {
        B[k++] = A[i++];
    }
    while (j <= m + n) {
        B[k++] = A[j++];
    }
    A = B;
}

void Print(vector<ElemType> A) {
    for (int i = 1; i <= A.size() - 1; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<ElemType> A = { -999,2,5,21,54,64,12,25,34,62,87,91 };
    cout << "排序前：" << endl;
    Print(A);
    MergeSort(A, 5, 6);
    cout << "排序后：" << endl;
    Print(A);
    return 0;
}

