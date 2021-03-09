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

void swap(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

//给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List* list, int start, int end, int size) {
	if (end <= start || end >= size) {
		return;
	}
	int mid = (start + end) / 2;
	_rep(i, 0, mid - start) {
		swap(&list->data[start + i], &list->data[end - i]);
	}
}

void PrintList(List list) {
	_rep(i, 1, list.length) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

#pragma endregion

//P278.6
//写出折半查找的递归算法。初始调用时,1ow为1,high为ST.length。

int BinSearch(List list, int key, int low, int high) {
	
	// 返回key在表中的序号
	if (low > high) {
		return 0;
	}
	int mid = (low + high) / 2;
	if (key > list.data[mid])
		return BinSearch(list, key, mid + 1, high);
	else if (key < list.data[mid])
		return BinSearch(list, key, low, mid - 1);
	else
		return mid;
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { -99999,2,3,5,7,9,11,13,15,41 };
	//顺序表的第0个位置不存数据
	for (int i = 1; i <= list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	cout << "位置为：" << BinSearch(list, 15, 1, list.length) << endl;
	return 0;
}