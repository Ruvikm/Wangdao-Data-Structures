#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma region 建立顺序存储的线性表

#define MAX 30
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)

typedef struct {
	int data[MAX];
	int length;
}List;

void swap(int& a, int& b) {
	int t;
	t = a;
	a = b;
	b = t;
}

//给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List& list, int start, int end, int size) {
	if (end <= start || end >= size) {
		return;
	}
	int mid = (start + end) / 2;
	_rep(i, 0, mid - start) {
		swap(list.data[start + i], list.data[end - i]);
	}
}

void PrintList(List list) {
	_for(i, 0, list.length) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

#pragma endregion

//P19.8
//已知在一维数组A[m + n]中依次存放两个线性表(a1, a2, a3…, am)和(b, b2, b3, …, bn)。试编
//写一个函数, 将数组中两个顺序表的位置互换, 即将(b1,b2,b3,…, bn)放在(a1，a2, a3, …, am)的前面

void swaplist(List& A, int m, int n, int size) {
	Reserve(A, 0, m + n - 1, size);
	Reserve(A, 0, n - 1, size);
	Reserve(A, n, m + n - 1, size);
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,7,14,24,12,54,42,32 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	swaplist(list, 4, 6, list.length);
	PrintList(list);
}