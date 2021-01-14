#include <iostream>
#include <vector>
using namespace std;

//P42.19
//设有一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链
//表中结点值最小的结点并输出，然后将该结点从中删除, 直到单链表空为止，再删除表
//头结点。

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region 建立带头结点的循环单链表

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
	L->next = L;
	return true;
}


//判断是否为空
bool IsEmpty(LinkList L) {
	return ((L->next) == L);
}

//判断结点P是否为表尾结点
bool IsTail(LinkList L, LNode* p) {
	return (p->next == L);
}

//使用尾插法建表
LinkList CreatList(vector<int> data) {
	if (data.size() < 1) {
		return NULL;
	}
	//头结点
	LNode* head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	LinkList p = head;
	_for(i, 0, data.size()) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		p->next = s;
		p = s;
	}
	p->next = head;
	return head;
}
//输出链表
void PrintList(LinkList list) {
	if (IsEmpty(list)) {
		cout << "the list is null" << endl;
		return;
	}
	LinkList plist = list->next;
	while (plist->next != list->next) {
		printf("%d ", plist->data);
		plist = plist->next;
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


//P42.19
void DelMinPrint(LinkList& A) {
	LinkList p = A->next;
	LinkList pre = A;
	LNode* minp = p;
	LNode* minpre = A;
	while (A->next != A)
	{
		p = A->next;
		pre = A;
		minp = p;
		minpre = pre;
		while (p != A) {
			
			if (p->data < minp->data) {
				minp = p;
				minpre = pre;
			}
			else {
				pre = p;
				p = p->next;
			}
		}
		minpre->next = minp->next;
		cout << minp->data<<" ";
		delete minp;
	}
	cout << endl;
	
}


int main()
{
	cout << "输入数据:" << endl;
	vector<int> data1{ 1,3,5,9,7,2 };
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	cout << "测试结果:" << endl;
	DelMinPrint(A);
	PrintList(A);
	return 0;
}
