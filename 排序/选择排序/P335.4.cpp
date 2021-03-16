#include <iostream>
#include <vector>
using namespace std;

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

//P335.4
//编写一个算法, 在基于单链表表示的待排序关键字序列上进行简单选择排序

void SortList(LinkList &head) {

	LinkList h = head->next;
	head = NULL;
	while (h) {
		LinkList max = h, maxpre = NULL, pre = NULL, p = h;
		while (p) {
			if (p->data > max->data) {
				max = p;
				maxpre = pre;
			}
			pre = p;
			p = p->next;
		}
		if (max == h)
			h = h->next;
		else
			maxpre->next = max->next;
		max->next = head;
		head = max;
	}
}

int main()
{
	vector<int> data{ 3,54,26,18,34,47,19,57 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	cout << "排序前：" << endl;
	PrintList(head->next);
	cout << "排序后：" << endl;
	SortList(head);
	PrintList(head->next);
	return 0;
}
