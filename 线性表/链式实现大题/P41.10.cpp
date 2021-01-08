#include <iostream>
#include <vector>
using namespace std;

//P41.10
//将一个带头结点的单链表A分解为两个带头结点的单链表A和B, 使得A表中含有原表
//中序号为奇数的元素, 而B表中含有原表中序号为偶数的元素, 且保持其相对顺序不变

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


//P41.10

void Split(LinkList &head) {
	LinkList B = (LinkList)malloc(sizeof(LNode));
	B->next = NULL;
	LinkList p = head->next;
	LinkList pre = head;
	LinkList Bp = B;
	int i = 0;
	while (p != NULL) {
		i++;
		if (i % 2 == 0) {
			LNode* q = p;
			Bp->next = q;
			Bp = q;
			pre->next = p->next;
		}else {
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
	vector<int> data{ 3,5,6,8,1,3,9,3 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	Split(head);
	return 0;
}
