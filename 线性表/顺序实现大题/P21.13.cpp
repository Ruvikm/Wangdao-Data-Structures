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

//P21.13
//〖2018统考真题】给定一个含n(n≥1)个整数的数组, 请设计一个在时间上尽可能高效
//的算法, 找出数组中未出现的最小正整数。例如, 数组{ -5,3,2,3 }中未出现的最小正整数
//是1; 数组{ 1,2,3 }中未出现的最小正整数是4。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度和空间复杂度

//用空间换时间
int FindMinNum(List A, int n) {
	int* Box = new int[n + 1]();
	_for(i, 0, A.length) {
		if (A.data[i] > 0 && A.data[i] <= n)
			Box[A.data[i]]++;
	}
	_for(i, 1, n) {
		if (!Box[i])
			return i;
	}
	return -1;
}

int main()
{
	List list;
	list.length = 10;
	int Data[] = { 1,4,9,-11,14,-24,32,54,-62,81 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	cout << "list中未出现的最小正整数是为：" << FindMinNum(list, 10) << endl;
}