#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

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

void BuildList(List& list, int Len, int Data[]) {

	list.length = Len;
	_for(i, 0, list.length)
		list.data[i] = Data[i];
}

#pragma endregion

//P323.5
//试编写一个算法, 使之能够在数组L[1…n]中找出第小的元素(即从小到大排序后处于
//第k个位置的元素)

int Kth_Elem(List& list, int low, int high, int k) {

	int pivot = list.data[low];
	int low_temp = low;
	int high_temp = high;
	while (low < high) {
		while (low < high && list.data[high] >= pivot)
			high--;
		list.data[low] = list.data[high];
		while (low < high && list.data[low] <= pivot)
			low++;
		list.data[high] = list.data[low];
	}
	list.data[low] = pivot;
	if (low == k)
		return list.data[low];
	else if (low > k)
		return Kth_Elem(list, low_temp, low - 1, k);
	else
		return Kth_Elem(list, low + 1, high_temp, k);
}

int main()
{
	List list;
	int Data[] = { 1,4,2,13,86,24,32,125,62,21 };
	BuildList(list, 10, Data);
	cout << "list为：" << endl;
	PrintList(list);
	int k = 5;
	cout << "第" << k << "小的元素为：" << Kth_Elem(list, 0, list.length - 1, k) << endl;
	return 0;
}