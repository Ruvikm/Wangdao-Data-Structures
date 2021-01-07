#include <iostream>
#include <vector>
using namespace std;

//P40.5
//试编写算法将带头结点的单链表就地逆置,所谓“就地”是指辅助空间复杂度为O(1)
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


//P40.5
//算法思想：将指针反过来
void ReverseList(LinkList& head) {
	LNode* pre, * p = head->next, * r = p->next;
	p->next = NULL;
	while (r != NULL) {
		pre = p;
		p = r;
		r = r->next;
		p->next = pre;
	}
	head->next = p;
}

int main()
{
	vector<int> data{ 3,4,6,8,1,3,9,5 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	ReverseList(head);
	PrintList(head);
	return 0;
}
