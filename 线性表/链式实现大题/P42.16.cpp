#include <iostream>
#include <vector>
using namespace std;

//P42.16
//两个整数序列A = a1,a2,a3…, an和B = b1, b2, b3, …, bn已经存入两个单链表中, 设计
//个算法, 判断序列B是否是序列A的连续子序列

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region 建立带头结点的链表

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//初始化链表
bool InitList(LinkList& L) {
	//分配一个头结点
	L = (LNode*)malloc(sizeof(LNode));
	//内存不足，分配失败
	if (L == NULL) {
		return false;
	}
	//头结点之后暂时还没有节点
	L->next = NULL;
	return true;
}


//判断是否为空
bool IsEmpty(LinkList L) {
	return ((L->next) == NULL);
}

//使用尾插法建表
LinkList CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	//头结点
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList p = head;
	_for(i, 0, data.size()) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	return head;
}
//输出链表
void PrintList(LinkList list) {
	if (IsEmpty(list)) {
		cout << "the list is null" << endl;
		return;
	}
	list = list->next;
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int Getlen(LinkList L) {
	int len = 0;
	while (L != NULL) {
		L = L->next;
		len++;
	}
	return len;
}
#pragma endregion


//P42.16

bool Subsequences(LinkList& A, LinkList& B) {
	LinkList pa = A->next, pb = B->next, pre = pa;
	while (pa && pb) {
		if (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
		}
		else {
			pre = pre->next;
			pa = pre;
			pb = B->next;
		}
	}
	if (!pb)
		return true;
	else
		return false;
}

int main()
{
	cout << "输入数据:" << endl;
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 3,5,7,9 };
	LinkList A;
	InitList(A);
	LinkList B;
	InitList(B);
	A = CreatList(data1);
	B = CreatList(data2);
	PrintList(A);
	PrintList(B);
	cout << "测试结果:" << endl;
	if (Subsequences(A, B)) {
		cout << "序列B是序列A的连续子序列" << endl;
	}
	else {
		cout << "序列B不是序列A的连续子序列" << endl;
	}
	return 0;
}
