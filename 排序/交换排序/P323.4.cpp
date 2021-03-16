#include <cstdio>
#include <iostream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

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

//P323.4
//试重新编写考点精析中的快速排序的划分算法, 使之每次选取的枢轴值都是随机地从当
//前子表中选择的

int Partiton(List& list, int low, int high) {
	int seed = time(0);
	srand(seed);
	int Num = low + rand() % (high - low + 1);
	swap(list.data[Num], list.data[low]);
	int pivot = list.data[low];
	cout << "枢轴：" << pivot << endl;
	while (low < high) {
		while (low < high && list.data[high] >= pivot)
			high--;
		list.data[low] = list.data[high];
		while (low < high && list.data[low] <= pivot)
			low++;
		list.data[high] = list.data[low];
	}
	list.data[low] = pivot;
	return low;
}


void QuickSort(List& A, int low, int high) {

	if (low < high) {
		int pivotpos = Partiton(A, low, high);
		QuickSort(A, low, pivotpos - 1);
		QuickSort(A, pivotpos + 1, high);
	}
}

int main()
{
	List list;
	int Data[] = { 1,43,22,12,14,24,18,54,32,81 };
	BuildList(list, 10, Data);
	cout << "排序前：" << endl;
	PrintList(list);
	cout << "排序后：" << endl;
	QuickSort(list, 0, list.length - 1);
	PrintList(list);
	return 0;
}