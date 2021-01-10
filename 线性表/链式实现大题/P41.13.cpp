#include <iostream>
#include <vector>
using namespace std;

//P41.13
//假设有两个按元素值递增次序排列的线性表, 均以单链表形式存储。请编写算法将这两
//个单链表归并为一个按元素值递减次序排列的单链表, 并要求利用原来两个单链表的结
//点存放归并后的单链表

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


//P41.13

void Consolidation(LinkList& A, LinkList& B) {
	LinkList p1 = A->next, p2 = B->next;
	LinkList pre1 = A, pre2 = B;
	pre1->next = NULL;
	while (p1 != NULL && p2 != NULL) {
		if (p1->data <= p2->data) {  // 将x节点头插到A中
			LinkList r = p1->next;
			LNode* x = p1;
			x->next = pre1->next;
			pre1->next = x;
			p1 = r;
		}
		else {
			LinkList r = p2->next;
			LNode* x = p2;
			x->next = pre1->next;
			pre1->next = x;
			p2 = r;
		}
	}
	//将剩余的接上
	while (p1 != NULL) {
		LinkList r = p1->next;
		LNode* x = p1;
		x->next = pre1->next;
		pre1->next = x;
		p1 = r;
	}
	while (p2 != NULL) {
		LinkList r = p2->next;
		LNode* x = p2;
		x->next = pre1->next;
		pre1->next = x;
		p2 = r;
	}
	

}

int main()
{
	vector<int> data1{ 1,3,5,7,9,11 };
	vector<int> data2{ 2,4,6,8 };
	LinkList A;
	InitList(A);
	LinkList B;
	InitList(B);
	A = CreatList(data1);
	B = CreatList(data2);
	PrintList(A);
	PrintList(B);
	Consolidation(A,B);
	PrintList(A);
	return 0;
}
