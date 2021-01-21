#include <iostream>
#include <vector>
using namespace std;

//P85.1
//若希望循环队列中的元素都能得到利用, 则需设置一个标志域tag, 并以tag的值为0
//或1来区分队头指针 front和队尾指针rear相同时的队列状态是“空”还是“满”。试
//编写与此结构相应的入队和出队算法
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f
#define MaxSize 3

#pragma region 建立循环队列

typedef struct {
	ElemType data[MaxSize];
	int front, rear;
	int tag;
}SqQueue;


//初始化链表
void InitList(SqQueue& Q) {
	Q.front = Q.rear = 0;
}

bool EnQueue(SqQueue& Q, ElemType x) {
	if (Q.front == Q.rear && Q.tag == 1) {
		cout << "full!" << endl;
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = 1;
	return true;
}

bool DeQueue(SqQueue& Q, ElemType& x) {
	if (Q.front == Q.rear && Q.tag == 0) {
		cout << "enpty" << endl;
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = 0;
	return true;
}


#pragma endregion




int main()
{
	SqQueue Q;
	InitList(Q);
	EnQueue(Q, 1);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 4);
	int x;
	DeQueue(Q, x);
	cout << x << endl;

	DeQueue(Q, x);
	cout << x << endl;

	DeQueue(Q, x);
	cout << x << endl;

	DeQueue(Q, x);
	cout << x << endl;
	return 0;
}