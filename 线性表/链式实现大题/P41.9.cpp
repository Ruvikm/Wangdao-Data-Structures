#include <iostream>
#include <vector>
using namespace std;

//P41.9
//给定一个带表头结点的单链表, 设head为头指针, 结点结构为(data, next), data
//为整型元素, next为指针, 试写出算法:按递增次序输出单链表中各结点的数据元素,
//并释放结点所占的存储空间(要求 : 不允许使用数组作为辅助空间)

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


//P41.9

void SortPrintAndFree(LinkList &head) {
	while (head ->next!= NULL) {
		LNode* p = head->next;
		LNode*  minpre = head;
		while (p->next != NULL) {
			if (p->next->data < minpre->next->data) {
				minpre = p;
			}
			else {
				p = p->next;
			}
		}
		LNode* del = minpre->next;
		minpre->next = del->next;
		cout <<del->data << " ";
		delete del;
	}
	cout << endl;
}

int main()
{
	vector<int> data{ 3,5,6,8,1,3,9,3 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	SortPrintAndFree(head);
	PrintList(head);
	delete head;
	return 0;
}
