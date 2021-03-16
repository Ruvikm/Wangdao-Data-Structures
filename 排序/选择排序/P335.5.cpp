#include <iostream>
#include <vector>

using namespace std;

#define ElemType int

//P335.5
//试设计一个算法, 判断一个数据序列是否构成一个小根堆

bool IsHeap(ElemType A[],int len) {
    if (len % 2 == 0) {
        if (A[len / 2] > A[len]) {
            return false;
            for (int i = len / 2 - 1; i >= 1; i--) {
                if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                    return false;
            }
        }
        else {
            for (int i = len / 2; i >= 1; i--) {
                if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                    return false;
            }
        }
        return true;
    }
}

int main()
{
    ElemType A[] = { -1,2,4,5,21,45,21,44,22,87,2,4,8 };
    ElemType B[] = { -1,2,4,3 };
    if (IsHeap(B, 3))
        cout << "是小根堆" << endl;
    else
        cout << "不是小根堆" << endl;
    return 0;
}
