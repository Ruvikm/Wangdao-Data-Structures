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

//P19.2
//设计一个高效算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O⑴

void reverse(List& list) {
	if (!list.length)
		return;
	for (int i = 0; i < list.length / 2; i++) {
		swap(list.data[i], (list.data[list.length - i - 1]));
	}
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,3,9,43,12,54,76,38 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	reverse(list);
	PrintList(list);
}