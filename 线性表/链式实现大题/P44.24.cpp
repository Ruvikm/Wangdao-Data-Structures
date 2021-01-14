#include <iostream>
#include <vector>
using namespace std;

//P44,24
//设计一个算法完成以下功能:判断一个链表是否有环, 如果有, 找出环的入口点并返回,
//否则返回NULL

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
	//list = list->next;
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


//P43.24
LNode* FindCycle(LinkList L) {
	LinkList fast = L, slow = L;
	while (slow != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}
	if (slow == NULL || (fast->next == NULL))
		return NULL;
	LinkList p = L, q = slow;
	for (; p != q; p = p->next, q = q->next);
	return q;
 }
int main()
{
	vector<int> data{ 1,3,5,7,9,11,13,15 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	LinkList p = head->next, q = p;
	for (; p->next; p = p->next);
	for (; q->next && q->data != 9; q = q->next);
	p->next = q;
	//PrintList(head->next);
	LinkList cycle = FindCycle(head);
	PrintList(cycle);
	return 0;
}
