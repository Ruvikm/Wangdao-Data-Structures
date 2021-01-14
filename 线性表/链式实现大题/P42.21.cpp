#include <iostream>
#include <vector>
using namespace std;

//P42.21
//已知一个带有表头结点的单链表，结点结构为
//			data	link
//假设该链表只给出了头指针1ist。在不改变链表的前提下, 请设计一个尽可能高效的
//算法, 查找链表中倒数第k个位置上的结点(k为正整数)。若查找成功, 算法输出该结
//点的data域的值, 并返回1; 否则, 只返回0。
//1)描述算法的基本设计思想
//2)描述算法的详细实现步骤
//3)根据设计思想和实现步骤, 采用程序设计语言描述算法(使用C、C++或Java语
//实现), 关键之处请给出简要注释

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


//P42.21
//自己版本
int PenultiMateK(LinkList L, int k) {
	int len = Getlen(L);
	int pin = len - k ;
	int count = 1;
	LinkList p = L->next;
	for (; p && count != pin; p = p->next, count++);
	if (p) {
		cout << p->data;
		return 1;
	}
	else {
		cout << "The element in the penultimate k position does not exist" << endl;
		return 0;
	}	
}

//书上版本
int Search_K(LinkList L, int k) {
	int count = 0;
	LinkList p = L->next, pk = p;
	while (p) {
		if (count < k)
			count++;
		else
			pk = pk->next;
		p = p->next;
	}
	if (count < k) {
		cout << "The element in the penultimate k position does not exist" << endl;
		return 0;
	}
	else {
		cout << pk->data;
		return 1;
	}
}

int main()
{
	vector<int> data{ 1,3,5,7,9,11,13,15 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	//PenultiMateK(head, 3);
	Search_K(head, 8);
	return 0;
}
