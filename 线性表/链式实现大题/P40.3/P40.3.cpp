#include <iostream>
#include <vector>
using namespace std;

//P40.3
//设L为带头结点的单链表,编写算法实现从尾到头反向输出每个结点的值
#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)


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
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

#pragma endregion


//P40.3
void ReversePrint(LinkList L) {
	if (L->next != NULL) {
		ReversePrint(L->next);
	}
	cout << L->data<<" ";
}


int main()
{
	vector<int> data{ 2,4,5,6,7,3,6,41 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head->next);
	ReversePrint(head->next);
	return 0;
}
