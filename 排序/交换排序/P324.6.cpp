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

//P323.6
//〖2016统考真题】已知由n(n≥2)个正整数构成的集合A = { ak|0 ≤ k ≤ n }, 将其划分为两
//个不相交的子集A1和A2, 元素个数分别是n1和n2, A1和A2中的元素之和分别为S1和S2
//设计一个尽可能高效的划分算法, 满足|n1 - n2|最小且| S1 - S1|最大。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++语言描述算法, 关键之处给出注释
//3)说明你所设计算法的平均时间复杂度和空间复杂度

int Partiton(List& list) {

	int low = 0, low0 = 0, high = list.length - 1, high0 = list.length - 1, k = list.length / 2;
	bool NoFind = true;
	while (NoFind) {
		int pivot = list.data[low];
		while (low < high) {
			while (low < high && list.data[high] >= pivot)
				high--;
			if (low != high)
				list.data[low] = list.data[high];
			while (low < high && list.data[low] <= pivot)
				low++;
			if (low != high)
				list.data[high] = list.data[low];
		}
		list.data[low] = pivot;
		if (low == k - 1)
			NoFind = false;
		else {
			if (low < k - 1) {
				low0 = ++low;
				high = high0;
			}
			else {
				high0 = --high;
				low = low0;
			}
		}
	}
	
	int s1 = 0, s2 = 0;
	_for(i, 0, k)
		s1 += list.data[i];
	_for(i, k, list.length)
		s2 += list.data[i];
	return s2 - s1;

}

int main()
{
	List list;
	int Data[] = { 1,43,22,12,14,24,18,54,32,81 };
	BuildList(list, 10, Data);
	cout << "list为：" << endl;
	PrintList(list);
	cout << "排序后：" << endl;
	sort(list.data, list.data + 10);
	PrintList(list);
	cout << "S2-S1最大值为：" << Partiton(list) << endl;
	return 0;
}