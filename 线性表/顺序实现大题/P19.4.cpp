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

//P19.4
//从有序顺序表中删除其值在给定值s与t之间(要求s < t)的所有元素, 如果s或t不合
//理或顺序表为空, 则显示出错信息并退出运行

void OrderlyDelete(List& list, int X, int T) {
	int i = 0, j = 0;
	for (i; i < list.length; i++)
		if (list.data[i] >= X)
			break;

	for (j; j < list.length; j++) {
		if (list.data[j] > T)
			break;
	}
	int len = j - 1;
	for (i; i < list.length; i++, j++) {
		list.data[i] = list.data[j];
	}
	list.length -= len;
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,6,9,11,12,24,34,44 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	OrderlyDelete(list, 4, 24);
	PrintList(list);
}