#include <iostream>
#include <vector>
using namespace std;

//P40.1
//没计一个递归算法, 删除不带头结点的单链表中所有值为×的结点

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)


#pragma region 建立不带头结点的链表

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

//初始化链表
bool InitList(LinkList &L) {
	L = NULL;
	return true;
}


//判断是否为空
bool IsEmpty(LinkList L) {
	return (L == NULL);
}

//使用尾插法建表
LinkList CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	//头结点
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->data = data[0];
	head->next = NULL;
	LinkList p = head;
	_for(i, 1, data.size()) {
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
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

#pragma endregion


//P40.1
void DeleteXNode(LinkList &head, ElemType X) {
	if (head == NULL) return;
	if (head->data != X) {
		return DeleteXNode(head->next, X);
	}
	LNode* q = head;
	head = head->next;
	delete q;
	return DeleteXNode(head, X);
}


int main()
{
	vector<int> data{ 2,4,6,4,6,3,6,41 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	DeleteXNode(head, 6);
	PrintList(head);
	return 0;
}
