#include <iostream>
#include <vector>
using namespace std;

//P40.6
//有一个带头结点的单链表L,设计一个算法使其元素递增有序
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


//P40.6
//算法思想：将链表的头结点后第一个节点与后面的节点断开，然后重新在合适的位置插入
void SortList(LinkList &head) {
	LinkList p = head->next;
	LinkList q = p->next;
	LinkList pre;
	p->next = NULL;
	p = q;
	while (q != NULL) {
		p = q->next;
		pre = head;
		for (; pre->next != NULL && (pre->next->data < q->data); pre = pre->next);
		q->next = pre->next;
		pre->next = q;
		q = p;
	}
}

int main()
{
	vector<int> data{ 3,4,6,8,1,3,9,5 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	SortList(head);
	PrintList(head);
	return 0;
}
