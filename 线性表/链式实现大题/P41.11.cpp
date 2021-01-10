#include <iostream>
#include <vector>
using namespace std;

//P41.11
//设C = { a1,b1,a2，b2,…,an，bn }为线性表, 采用带头结点的hc单链表存放, 设计一个就地
//算法, 将其拆分为两个线性表, 使得A = { a1,a2…,an }, B = { bn,…,b2,b1 }

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
	head->data = NULL;
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

#pragma endregion


//P41.11
//把10题改成头插法就行
void Splitting(LinkList &head) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LinkList p = head->next;
	LinkList pre = head;
	LinkList Bp=B;
	int i = 0;
	while (p != NULL) {
		i++;
		if (i % 2 == 0) {
			LNode* q = p;
			pre->next = p->next;
			q->next = Bp->next;
			Bp->next = q;
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
	cout << "A:" << endl;
	PrintList(head);
	cout << "B:" << endl;
	PrintList(B);
}

int main()
{
	vector<int> data{ 1,2,3,4,5,6,7,8 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	Splitting(head);
	return 0;
}
