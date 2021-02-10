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

//P19.5
//从顺序表中删除其值在给定值s与t之间(包含s和t, 要求s < t)的所有元素,
//如果s或t不合理或顺序表为空, 则显示出错信息并退出运行

void DeleteS_T(List& list, int S, int T) {
	if (S >= T || !list.length)
		return;

	for (int i = 0; i < list.length; i++) {
		if (list.data[i] >= S && list.data[i] <= T) {
			for (int j = i + 1; j < list.length; j++) {
				list.data[j - 1] = list.data[j];
			}
			//要重新回退一个位置，重新检测，否则会跳过某些数字
			if (i)
				i -= 1;
			list.length -= 1;
		}
	}
}

int main()
{
	List list;
	list.length = 9;
	int Data[] = { 2,4,9,5,11,5,24,14,44 };
	for (int i = 0; i < list.length; i++)
		list.data[i] = Data[i];
	PrintList(list);
	DeleteS_T(list, 4, 11);
	PrintList(list);
}