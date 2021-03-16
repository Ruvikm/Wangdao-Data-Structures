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

void BuildList(List& list,int Len,int Data[]) {

	list.length = Len;
	_for(i, 0, list.length)
		list.data[i] = Data[i];
}

#pragma endregion

//P323.3
//已知线性表按顺序存储, 且每个元素都是不相同的整数型元素, 设计把所有奇数移动到
//所有偶数前边的算法(要求时间最少, 辅助空间最少)

int Partiton(List &list, int low, int high) {
	int pivot = list.data[low];
	while (low < high) {
		while (low < high && list.data[high] % 2 == 0)
			high--;
		list.data[low] = list.data[high];
		while (low < high && list.data[low] % 2 != 0)
			low++;
		list.data[high] = list.data[low];
	}
	list.data[low] = pivot;
	return low;
}


void MoveOddNum(List& A, int low, int high) {

	if (low < high) {
		int pivotpos = Partiton(A, low, high);
		MoveOddNum(A, low, pivotpos - 1);
		MoveOddNum(A, pivotpos + 1, high);
	}
}

int main()
{
	List list;
	int Data[] = { 1,4,9,11,14,24,32,54,62,81 };
	BuildList(list, 10, Data);
	cout << "排序前：" << endl;
	PrintList(list);
	cout << "排序后：" << endl;
	MoveOddNum(list, 0, list.length - 1);
	PrintList(list);
	return 0;
}