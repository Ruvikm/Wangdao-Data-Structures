#include <iostream>
#include <vector>
using namespace std;

//P41.14
//设A和B是两个单链表(带头结点), 其中元素递增有序。设计一个算法从A和B中的
//公共元素产生单链表C, 要求不破坏A、B的结点

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


//P41.14

LinkList FindComonList(LinkList& A, LinkList& B) {
	LinkList pa = A->next, pb = B->next;
	LinkList C= (LinkList)malloc(sizeof(LNode));
	C->next = NULL;
	LinkList pc = C;
	while (pa && pb) {
		if (pa->data < pb->data) {
			pa = pa->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
		}
		else{ // 相等
			LNode* r = (LNode*)malloc(sizeof(LNode));
			r->data = pa->data;
			r->next = NULL;
			pc->next = r;
			pc = r;
			pa = pa->next;
			pb = pb->next;
		}
	}
	return C;
}

int main()
{
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 1,4,5,9 };
	LinkList A;
	InitList(A);
	LinkList B;
	InitList(B);
	A = CreatList(data1);
	B = CreatList(data2);
	PrintList(A);
	PrintList(B);
	LinkList C =FindComonList(A, B);
	PrintList(C);
	return 0;
}
