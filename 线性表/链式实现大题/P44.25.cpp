#include <iostream>
#include <vector>
using namespace std;

//P44.25
//设线性表L = (a1,a2, a3,…, an-2,an-1,an)采用带头结点的单链表保存
//请设计一个空间复杂度为O(1)且时间上尽可能高效的算法, 重新排列 L中的各结点, 得
//到线性表L = (a1, an,a2,an-1, a3, an-2…)。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C艹语言描述算法, 关键之处给出注释
//3)说明你所设计的算法的时间复杂度

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

int Getlen(LinkList L) {
	int len = 0;
	while (L != NULL) {
		L = L->next;
		len++;
	}
	return len;
}

#pragma endregion


//P44.25


void Custom_sort(LinkList& L) {
	LinkList p, q, r, s;
	p = q = L;
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL) {
			q = q->next;
		}
	}
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = p->next;
		p->next = q;
		q = r;
	}
	s = L->next;
	q = p->next;
	p->next = NULL;
	while (q != NULL) {
		r = q->next;
		q->next = s->next;
		s->next = q;
		s = q->next;
		q = r;
	}

}

int main()
{
	vector<int> data{ 1,3,5,7,15,13,11,9 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	Custom_sort(head);
	PrintList(head);
	return 0;
}
