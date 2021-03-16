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

//P323.7
//荷兰国旗问题:设有一个仅由红、白、蓝三种颜色的条块组成的条块序列, 请编写一个时间
//复杂度为O(m)的算法, 使得这些条块按红、白、蓝的顺序排好, 即排成荷兰国旗图案

void Flag_Arrange(List &list) {
	int i = 0, j = 0, k = list.length - 1;
	while (j <= k) {
		switch (list.data[j]){ 
			case 0: {
				swap(list.data[i++], list.data[j++]);
				break;
			}
			case 1:{
				j++;
				break;
			}
			case 2: {
				swap(list.data[j], list.data[k--]);
			}
		}
	}
}


int main()
{
	List list;
	//设红为0，白为1，蓝为2
	int Color[] = { 1,0,1,2,2,1,2,0,1,2 };
	BuildList(list, 10, Color);
	cout << "排序前为：" << endl;
	PrintList(list);
	cout << "排序后为：" << endl;
	Flag_Arrange(list);
	PrintList(list);
	return 0;
}