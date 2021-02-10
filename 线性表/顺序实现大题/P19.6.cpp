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

//P19.6
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同

void OlderlyDeleteSame(List& list) {

	_for(i, 0, list.length) {
		if (list.data[i + 1] == list.data[i]) {
			for (int j = i + 1; j < list.length; j++) {
				list.data[j] = list.data[j + 1];
			}
			list.length -= 1;
			if (i)
				i -= 1;
		}
	}
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 1,4,9,9,9,9,9,24,14,3 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	OlderlyDeleteSame(list);
	PrintList(list);
}