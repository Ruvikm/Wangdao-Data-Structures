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
	_for(i, 0, list.length) {
		cout << list.data[i] << " ";
	}
	cout << endl;
}

#pragma endregion

//P278.7(1)
//线性表中各结点的检索概率不等时,可用如下策略提高顺序检索的效率:若找到指定的
//结点,则将该结点和其前驱结点(若存在)交换, 使得经常被检索的结点尽量位于表的
//前端。试设计在顺序结构和链式结构的线性表上实现上述策略的顺序裣索算法。

//顺序实现
int Search(List &list, int key) {

	int i = 0;
	for (i; i < list.length && list.data[i] != key; i++);
	if (i < list.length && i > 0) {
		swap(list.data[i], list.data[i - 1]);
		return --i;
	}
	return -1;
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = {2,3,5,7,9,11,13,15,41 };
	//顺序表的第0个位置不存数据
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	cout << "位置为：" << Search(list, 9) << endl;
	cout << "位置为：" << Search(list, 9) << endl;
	cout << "位置为：" << Search(list, 9) << endl;
	cout << "位置为：" << Search(list, 9) << endl;
	cout << "位置为：" << Search(list, 13) << endl;
	cout << "位置为：" << Search(list, 13) << endl;
	PrintList(list);
	return 0;
}