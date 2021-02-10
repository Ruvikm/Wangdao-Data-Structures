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

//P20.9
//线性表(a1,a2,a3,..,an)中的元素递增有序且按顺序存储于计算机内。
//要求设计一算法, 完成用最少时间在表中查找数值为x的元素, 若找到则将其与后继元素位置相交换,
//若找不到则将其插入表中并使表中元素仍递增有序

//我的方法 大力出奇迹
void CheckAndSwap(List& A, int x) {
	bool flag = true;
	_for(i, 0, A.length) {
		if (A.data[i] == x) {
			swap(A.data[i], A.data[i + 1]);
			printf("Find it\n");
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("Not find\n");
		int i = 0;
		for (i = 0; i < A.length && A.data[i] <= x; i++);
		if (i < A.length)
		{
			for (int j = A.length; j >= i; j--) {
				A.data[j + 1] = A.data[j];
			}
		}
		A.data[i] = x;
		A.length += 1;
	}
}

//答案方法 折半查找
void SearchExchangeInsert(List& A, int x) {
	int low = 0, mid = A.length / 2, high = A.length - 1;
	bool Isfind = false;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == A.data[mid]) {
			Isfind = true;
			printf("Find\n");
			break;
		}
		if (x > A.data[mid]) {
			low = mid + 1;
		}
		if (x < A.data[mid]) {
			high = mid - 1;
		}
	}
	if (Isfind && mid != A.length - 1) {
		swap(A.data[mid], A.data[mid + 1]);
	}
	if (!Isfind) {
		int i = 0;
		for (i = A.length - 1; i > high; i--) {
			A.data[i + 1] = A.data[i];
		}
		A.data[i + 1] = x;
		A.length += 1;
	}
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,11,14,24,32,54,62,81 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	//CheckAndSwap(list, 54);
	SearchExchangeInsert(list, 23);
	PrintList(list);
}