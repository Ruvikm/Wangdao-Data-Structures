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

//P20.10
//〖2010统考真题〗设将n(n > 1)个整数存放到一维数组R中。设计一个在时间和空间两
//方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置, 即将R中的
//数据由(X0,X1,…,Xn-1)变换为(Xp+Xp+1…,Xn-1,X0,X1…,Xp - 1)。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度和空间复杂度

void MoveList(List& list, int MoveStep) {
	//BA=(A^-1*B^-1)^-1
	Reserve(list, 0, MoveStep - 1, MAX);
	Reserve(list, MoveStep, list.length - 1, MAX);
	Reserve(list, 0, list.length - 1, MAX);
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,11,14,24,32,54,62,81 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	MoveList(list, 3);
	PrintList(list);
}