#include <iostream>
#include <vector>
using namespace std;

//P41.8
//给定两个单链表,编写算法找出两个链表的公共结点
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
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int GetLenth(LinkList L) {
	int len = 0;
	LinkList p = L->next;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	return len;
}

#pragma endregion


//P41.8
//公共节点后全是公共的，“Y”型
LinkList FindCommonList(LinkList A,LinkList B) {
	int LenA = GetLenth(A), LenB = GetLenth(B), DiffLen=abs(LenA-LenB);
	LinkList LongList, ShortList;
	if (LenA > LenB) {
		LongList = A->next;
		ShortList = B->next;
	}
	else {
		LongList = B->next;
		ShortList = A->next;
	}
	while (DiffLen--) {
		LongList = LongList->next;
	}
	while (LongList != NULL) {
		if (LongList == ShortList) {
			return LongList;
		}
		else {
			LongList = LongList->next;
			ShortList = ShortList->next;
		}

	}
}

int main()
{
	vector<int> data1{ 3,5,6,8,1,4,9,77 };
	vector<int> data2{ 2,5,7,88,31};
	LinkList head1;
	LinkList head2;
	InitList(head1);
	InitList(head2);
	head1 = CreatList(data1);
	head2 = CreatList(data2);
	LinkList com = head1->next;
	LinkList P = head2;
	for (; com != NULL && com->data != 8; com = com->next);
	for (; P ->next!= NULL; P = P->next);
	P->next = com;
	PrintList(head1->next);
	PrintList(head2->next);
	LinkList CommList = FindCommonList(head1, head2);
	PrintList(CommList);
	return 0;
}
