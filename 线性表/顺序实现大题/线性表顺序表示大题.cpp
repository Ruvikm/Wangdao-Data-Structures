#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 30
#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)

typedef struct {
	int data[MAX];
	int length;
}List;

void swap(int* a, int* b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

//给定一个List，传入List的大小，要逆转的起始位置
void Reserve(List* list, int start, int end, int size) {
	if (end <= start || end >= size) {
		return;
	}
	int mid = (start + end) / 2;
	_rep(i, 0, mid - start) {
		swap(&list->data[start + i], &list->data[end - i]);
	}
	/*  _for(i, 0, list->length) {
		  printf("%d ", list->data[i]);
	  }*/
}

//P19.1
//从顺序表中删除具有最小值的元素(假设唯一)并由函数返回被删元素的值。空出的位
//置由最后一个元素填补, 若顺序表为空则显示出错信息并退出运行
int FindMin(List* list)
{
	if (!(*list).length) {
		printf("Error!\n");
		return -1;
	}

	int Min = 9999;
	int point;
	for (int i = 0; i < (*list).length; i++)
	{
		if ((*list).data[i] < Min)
		{
			Min = (*list).data[i];
			point = i;
		}
	}
	(*list).data[point] = (*list).data[(*list).length - 1];
	(*list).length -= 1;
	return Min;
}

//P19.2
//设计一个高效算法，将顺序表的所有元素逆置，要求算法的空间复杂度为O⑴
void reverse(List* list) {
	if (!list->length)
		return;
	for (int i = 0; i < (*list).length / 2; i++) {
		swap(&(list->data[i]), &(list->data[list->length - i - 1]));
	}
}

//P19.3
//对长度为n的顺序表L, 编写一个时间复杂度为O(m)空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素
void DeleteX(List* list, int X) {
	for (int i = 0; i < (*list).length; i++) {
		if ((*list).data[i] == X) {
			for (int j = i + 1; j < (*list).length; j++) {
				(*list).data[j - 1] = (*list).data[j];
			}
			(*list).length -= 1;
			break;
		}
	}
}

//P19.4
//从有序顺序表中删除其值在给定值s与t之间(要求s < t)的所有元素, 如果s或t不合
//理或顺序表为空, 则显示出错信息并退出运行
void OrderlyDelete(List* list, int X, int T) {
	int i = 0, j = 0;
	for (i; i < (*list).length; i++)
		if ((*list).data[i] >= X)
			break;

	for (j; j < (*list).length; j++) {
		if ((*list).data[j] > T)
			break;
	}
	int len = j - 1;
	for (i; i < (*list).length; i++, j++) {
		list->data[i] = list->data[j];
	}
	list->length -= len;
}

//P19.5
//从顺序表中删除其值在给定值s与t之间(包含s和t, 要求s < t)的所有元素,
//如果s或t不合理或顺序表为空, 则显示出错信息并退出运行
void DeleteS_T(List* list, int S, int T) {
	if (S >= T || !list->length)
		return;

	for (int i = 0; i < (*list).length; i++) {
		if ((*list).data[i] >= S && (*list).data[i] <= T) {
			for (int j = i + 1; j < (*list).length; j++) {
				(*list).data[j - 1] = (*list).data[j];
			}
			//要重新回退一个位置，重新检测，否则会跳过某些数字
			if (i)
				i -= 1;
			(*list).length -= 1;
		}
	}
}

//P19.6
//从有序顺序表中删除所有其值重复的元素,使表中所有元素的值均不同

void OlderlyDeleteSame(List* list) {
	for (int i = 0; i < list->length; i++) {
		if (list->data[i + 1] == list->data[i]) {
			for (int j = i + 1; j < list->length; j++) {
				list->data[j] = list->data[j + 1];
			}
			list->length -= 1;
			if (i)
				i -= 1;
		}
	}
}

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

//P19.8
//已知在一维数组A[m + n]中依次存放两个线性表(a1, a2, a3…, am)和(b, b2, b3, …, bn)。试编
//写一个函数, 将数组中两个顺序表的位置互换, 即将(b1,b2,b3,…, bn)放在(a1，a2, a3, …, am)的前面

void swaplist(List* A, int m, int n, int size) {
	Reserve(A, 0, m + n - 1, size);
	Reserve(A, 0, n - 1, size);
	Reserve(A, n, m + n - 1, size);
}

//P20.9线性表(a1,a2,a3,..,an)中的元素递增有序且按顺序存储于计算机内。
//要求设计一算法, 完成用最少时间在表中查找数值为x的元素, 若找到则将其与后继元素位置相交换,
//若找不到则将其插入表中并使表中元素仍递增有序

//我的方法 大力出奇迹
void CheckAndSwap(List* A, int x) {
	bool flag = true;
	_for(i, 0, A->length) {
		if (A->data[i] == x) {
			swap(&A->data[i], &A->data[i + 1]);
			printf("Find it\n");
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("Not find\n");
		int i = 0;
		for (i = 0; i < A->length && A->data[i] <= x; i++);
		if (i < A->length)
		{
			for (int j = A->length; j >= i; j--) {
				A->data[j + 1] = A->data[j];
			}
		}
		A->data[i] = x;
		A->length += 1;
	}
}

//答案方法 折半查找
void SearchExchangeInsert(List* A, int x) {
	int low = 0, mid = A->length / 2, high = A->length - 1;
	bool Isfind = false;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x == A->data[mid]) {
			Isfind = true;
			printf("Find\n");
			break;
		}
		if (x > A->data[mid]) {
			low = mid + 1;
		}
		if (x < A->data[mid]) {
			high = mid - 1;
		}
	}
	if (Isfind && mid != A->length - 1) {
		printf("Swap\n");
		swap(&A->data[mid], &A->data[mid + 1]);
	}
	if (!Isfind) {
		int i = 0;
		printf("%d", low);
		for (i = A->length - 1; i > high; i--) {
			A->data[i + 1] = A->data[i];
		}
		A->data[i + 1] = x;
		A->length += 1;
	}
}

//P20.10
//〖2010统考真题〗设将n(n > 1)个整数存放到一维数组R中。设计一个在时间和空间两
//方面都尽可能高效的算法。将R中保存的序列循环左移p(0<p<n)个位置, 即将R中的
//	数据由(X0,X1,…,Xn-1)变换为(Xp+Xp+1…,Xn-1,X0,X1…,Xp - 1)。要求
//	1)给出算法的基本设计思想
//	2)根据设计思想, 采用C或C++ + 或Java语言描述算法, 关键之处给出注释
//	3)说明你所设计算法的时间复杂度和空间复杂度

void MoveList(List* list, int MoveStep) {
	//BA=(A^-1*B^-1)^-1
	Reserve(list, 0, MoveStep - 1, MAX);
	Reserve(list, MoveStep, list->length - 1, MAX);
	Reserve(list, 0, list->length - 1, MAX);
}

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

//P20.12
//〖2013统考真题〗已知一个整数序列A = (a0, a1…, an-1), 其中0 ≤ ai < n(0 ≤i < n)。若
//	存在 ap1 = ap2 = ... = apm = x 且 m > n / 2   (0≤ Pk < n,1≤ k ≤ m), 则称x为A的主元素。
//	例如A=(0,5,5,3,5,7,5,5)，则5为主元素; 又如A = (0, 5, 5, 3, 5, 1, 5, 7), 则A中没有主
//	元素。假设A中的n个元素保存在一个一维数组中, 请设计一个尽可能高效的算法, 找
//	出A的主元素。若存在主元素, 则输岀该元素; 否则输出 - 1。要求:
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C十或Java语言描述算法, 关键之处给出注释
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
			return A.data[i];
		}
	}
	return -1;
}

//P21.13
//〖2018统考真题】给定一个含n(n≥1)个整数的数组, 请设计一个在时间上尽可能高效
//的算法, 找出数组中未出现的最小正整数。例如, 数组{ -5,3,2,3 }中未出现的最小正整数
//是1; 数组{ 1,2,3 }中未出现的最小正整数是4。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C艹语言描述算法, 关键之处给出注释
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
	List list1;
	List list2;
	list1.length = 4;
	list2.length = 5;
	int Data1[] = { 1,3,2,3 };
	int Data2[] = { 22,43,64,87,180 };

	for (int i = 0; i < list1.length; i++)
		list1.data[i] = Data1[i];

	for (int i = 0; i < list2.length; i++)
		list2.data[i] = Data2[i];

	printf("%d", FindMinNum(list1, 4));
}