#include <iostream>
#include <vector>
using namespace std;

//P40.7
//设在一个带表头结点的单链表中所有元素结点的数据值无序,试编写一个函数,删除表
//中所有介于给定的两个值(作为函数参数给出)之间的元素的元素(若存在)
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


//P40.7

void DelBetweenAB(LinkList& head, int A, int B) {
	if (A > B) {
		return;
	}
	LinkList  pre = head;
	LinkList p = pre->next;
	while (p != NULL) {

		if (pre->next->data >= A && pre->next->data <= B) {
			LNode* del = p;
			pre->next = p->next;
			p = p->next;
			delete del;
		}
		else {
			pre = p;
			p = p->next;
		}
		
	}
}

int main()
{
	vector<int> data{ 3,5,6,8,1,3,9,3 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	DelBetweenAB(head,3,7);
	PrintList(head);
	return 0;
}
