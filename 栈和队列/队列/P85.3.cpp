#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define ElemType int
#define MaxSize 3

//P85.3
//利用两个栈S1, S2来模拟一个队列, 已知栈的4个运算定义如下
//	Push(s, x);				//元素x入栈S
//	Pop(s, X);				//S出栈并将出栈的值赋给x
//	StackEmpty(s);			//判断栈是否为空
//	Stackoverflow(s);		//判断栈是否满

//	如何利用栈的运算来实现该队列的3个运算(形参由读者根据要求自己设计) ?
//	Enqueue					//将元素x入队
//	Dequeue					//出队,并将出队元素存储在ⅹ中
//	QueueEmpty				//判断队列是否为空

bool Enqueue(stack<int> &S1, stack<int> &S2,ElemType x) {
	if (S1.size() != MaxSize) {
		S1.push(x);
		return true;
	}
	if (S1.size() == MaxSize && !S2.empty()) {
		cout << "队列已满！" << endl;
		return false;
	}
	if (S1.size() == MaxSize && S2.empty()) {
		while (!S1.empty()) {
			int temp = S1.top();
			S1.pop();
			S2.push(temp);
		}
		S1.push(x);
		return true;
	}
}

bool Dequeue(stack<int> &S1, stack<int> &S2, ElemType &x) {
	if (!S2.empty()) {
		x = S2.top();
		S2.pop();
		return true;
	}
	if (S1.empty() && S2.empty()) {
		cout << "队列为空！" << endl;
		return false;
	}
	if (!S1.empty() && S2.empty()) {
		while (!S1.empty()) {
			int temp = S1.top();
			S1.pop();
			S2.push(temp);
		}
		x = S2.top();
		S2.pop();
		return true;
	}
}

bool QueueEmpty(stack<int> S1, stack<int> S2) {
	return (S1.empty() && S2.empty());
}


int main()
{
	//test
	stack<int> S1, S2;

	cout << QueueEmpty(S1, S2) << endl;

	Enqueue(S1, S2, 1);
	Enqueue(S1, S2, 2);
	Enqueue(S1, S2, 3);
	Enqueue(S1, S2, 4);

	int x;
	Dequeue(S1, S2, x);
	cout << x << endl;
	Dequeue(S1, S2, x);
	cout << x << endl;
	Dequeue(S1, S2, x);
	cout << x << endl;
	Dequeue(S1, S2, x);
	cout << x << endl;
	return 0;
}

