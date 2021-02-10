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

//P20.12
//〖2013统考真题〗已知一个整数序列A = (a0, a1…, an-1), 其中0 ≤ ai < n(0 ≤i < n)。若
//存在 ap1 = ap2 = ... = apm = x 且 m > n / 2   (0≤ Pk < n,1≤ k ≤ m), 则称x为A的主元素。
//例如A=(0,5,5,3,5,7,5,5)，则5为主元素; 又如A = (0, 5, 5, 3, 5, 1, 5, 7), 则A中没有主
//元素。假设A中的n个元素保存在一个一维数组中, 请设计一个尽可能高效的算法, 找
//出A的主元素。若存在主元素, 则输岀该元素; 否则输出 - 1。要求:
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度和空间复杂度

//次优算法，用空间换时间，类似桶排
int  FindMain(List A, int n) {
	int m_num = 0;
	int* Box = new int[n](); //动态申请一个大小为n的数组
	_for(i, 0, A.length) {
		Box[A.data[i]]++;
	}
	_for(i, 0, n) {
		if (Box[i] > n / 2) {
			return i;
		}
	}
	return -1;
}

int main()
{
	List list;
	list.length = 10;
	/*int Data[] = { 1,4,9,11,14,24,32,54,62,81 };*/
	int Data[] = { 1,3,2,6,3,3,3,3,3,1 };
	_for(i, 0, list.length)
		list.data[i] = Data[i];
	PrintList(list);
	cout << "list中的主元素为：" << FindMain(list, 10) << endl;
}