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

//P19.7
//将两个有序顺序表合并为一个新的有序顺序表, 并由函数返回结果顺序表

List MergeList(List A, List B) {
	int i = 0, j = 0;
	List C;
	int k = 0;
	while (i < A.length && j < B.length) {
		if (A.data[i] >= B.data[j]) {
			C.data[k++] = B.data[j++];
		}
		else {
			C.data[k++] = A.data[i++];
		}
	}
	while (i < A.length) {
		C.data[k++] = A.data[i++];
	}
	while (j < B.length) {
		C.data[k++] = B.data[j++];
	}
	C.length = k;
	return C;
}

int main()
{
	List list1, list2;
	list1.length = 9;
	int Data1[] = { 1,4,9,11,14,24,39,54,76,99 };
	_for(i, 0, list1.length)
		list1.data[i] = Data1[i];
	PrintList(list1);

	list2.length = 5;
	int Data2[] = { 11,24,43,65,71 };
	_for(i, 0, list2.length)
		list2.data[i] = Data2[i];
	PrintList(list2);
	PrintList(MergeList(list1, list2));
}