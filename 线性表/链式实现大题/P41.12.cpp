#include <iostream>
#include <vector>
using namespace std;

//P41.12
//在一个递增有序的线性表中有数值相同的元素存在。若存储方式为单链表, 设计算法
//去掉数值相同的元素, 使表中不再有重复的元素, 例如(7, 10, 10, 21, 30, 42, 42, 42, 51, 70)
//将变为(7, 10, 21, 30, 42, 51, 70)

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


//P41.12

void de_duplication(LinkList& head) {
	LinkList p = head->next;
	LinkList pre = head;
	while (p != NULL) {
		if (p->data == pre->data) {
			LNode* del = p;
			pre->next = p->next;
			delete del;
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}

int main()
{
	vector<int> data{ 7,10,10,21,30,42,42,42,51,70 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	de_duplication(head);
	PrintList(head);
	return 0;
}
