#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define ElemType int

//P349.3
//有一种简单的排序算法, 称为计数排序(count sorting)这种排序算法对一个待排序的表
//用数组表示)进行排序, 并将排序结果存放到另一个新的表中。必须注意的是, 表中所
//有待排序的关键码互不相同, 计数排序算法针对表中的每个记录, 扫描待排序的表一趟
//统计表中有多少个记录的关键码比该记录的关键码小, 假设针对某个记录统计出的计数
//值为c, 则这个记录在新有序表中的合适存放位置即为c
//1)设计实现计数排序的算法
//2)对于有n个记录的表, 关键码比较次数是多少 ?
//3)与简单选择排序相比较, 这种方法是否更好 ? 为什么

void CountSort(vector<ElemType> &A) {
    vector<ElemType> B(A.size());
    for (int i = 0; i < A.size(); i++) {
        int count = 0;
        for (int j = 0; j < A.size(); j++) {
            if (A[j] < A[i])
                count++;
        }
        B[count] = A[i];
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
    vector<ElemType> A = { 61,2,5,21,24,64,12,15,34,32,47,9 };
    cout << "排序前：" << endl;
    Print(A);
    CountSort(A);
    cout << "排序后：" << endl;
    Print(A);
    return 0;
}

