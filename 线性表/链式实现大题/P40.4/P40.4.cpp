#include <iostream>
#include <vector>
using namespace std;

//P40.4
//试编写在带头结点的单链表中删除一个最小值结点的高效算法(假设最小值结点是唯一的)
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
	list = list->next;
	while (list != NULL) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

#pragma endregion


//P40.4
void DelMinNode(LinkList& head) {
	LNode* p = head->next;
	LNode* q = head;
	LNode* Minq = q, * Minp = p;
	while (p != NULL) {
		if (p->data < Minp->data) {
			Minp = p;
			Minq = q;
		}
		else {
			q = p;
			p = p->next;
		}
	}
	LNode* X = Minp;
	Minq->next = Minp->next;
	Minp = Minp->next;
	delete X;
}


int main()
{
	vector<int> data{ 3,4,6,8,1,3,9,5 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	DelMinNode(head);
	PrintList(head);
	return 0;
}
