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

//P20.11
//〖2011统考真题】一个长度为L(L≥1)的升序序列S, 处在第[L/2]个位置的数称为S的
//中位数。例如, 若序列S1 = (1, 13, 15, 17, 19), 则S1的中位数是15, 两个序列的中位数
//是含它们所有元素的升序序列的中位数。例如, 若S2 = (2, 4, 6, 8, 20), 则S1和S2的中位
//数是11。现在有两个等长升序序列A和B, 试设计一个在时间和空间两方面都尽可能
//高效的算法, 找出两个序列A和B的中位数。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度和空间复杂度

//改编的归并排序
int FindMid(List A, List B) {
	int i = 0, j = 0;
	while (i + j != (A.length + B.length) / 2 - 1) {
		if (A.data[i] <= B.data[j]) {
			i++;
		}
		else {
			j++;
		}
	}
	return A.data[i] < B.data[j] ? A.data[i] : B.data[j];
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
	cout << "list1与list2的中位数为：" << FindMid(list1, list2) << endl;
}