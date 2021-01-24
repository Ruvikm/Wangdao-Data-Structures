#include <iostream>
#include <vector>
using namespace std;

#define MaxSize 5
#define ElemType int

//P71.5
//设有两个栈s1、s2都采用顺序栈方式, 并共享一个存储区[0, …, maxsize - 1]
//为了尽量利用空间, 减少溢出的可能, 可采用栈顶相向、迎面增长的存储方式。
//试设计s1,s2有关入栈和出栈的操作算法


#pragma region P71.5建立共享顺序栈

typedef struct {
	ElemType data[MaxSize];
	int top[2];
}SqStack;

void InitStack(SqStack &S) {
	S.top[0] = -1;
	S.top[1] = MaxSize - 1;
}
 
bool Push(SqStack& S, ElemType x,int i) {
	if (S.top[1] - S.top[0] == 1) {
		cout << "栈以满！" << endl;
		return false;
	}
	switch (i)
	{
		case 0: {
			S.data[++S.top[0]] = x;
			return true;
		}
		case 1: {
			S.data[--S.top[1]] = x; 
			return true;
		}
		default: {
			cout << "入栈序号错误!" << endl; 
			return false;
		}
	}
}

bool Pop(SqStack& S, ElemType& x,int i) {
	switch (i)
	{
		case 0: {
			if (S.top[0] == -1) {
				cout << "0号栈为空！" << endl;
				return false;
			}
			x = S.data[S.top[0]--];
			return true;
		}
		case 1: {
			if (S.top[1] == MaxSize-1) {
				cout << "1号栈为空！" << endl;
				return false;
			}
			x = S.data[S.top[1]++];
			return true;
		}
		default: {
			cout << "入栈序号错误!" << endl; 
			return false;
		}
	}
}

#pragma endregion



int main()
{
	//test
	SqStack S;
	InitStack(S);
	Push(S, 2, 0);
	Push(S, 1, 0);
	Push(S, 4, 1);
	Push(S, 3, 1);
	int x;
	Pop(S, x, 0);
	cout << x << endl;
	Pop(S, x, 0);
	cout << x << endl;
	Pop(S, x, 1);
	cout << x << endl;
	Pop(S, x, 1);
	cout << x << endl;
	return 0;
}

