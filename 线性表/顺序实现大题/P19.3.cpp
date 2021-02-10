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

//P19.3
//对长度为n的顺序表L, 编写一个时间复杂度为O(m)空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素

void DeleteX(List& list, int X) {
	int k = 0, i = 0;
	while (i < list.length) {
		if (list.data[i] == X)
			k++;
		else
			list.data[i - k] = list.data[i];
		i++;
	}
	list.length = list.length - k;
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,3,9,3,12,3,76,3 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	DeleteX(list, 3);
	PrintList(list);
}