#include <iostream>
#include <vector>
using namespace std;

//P42.20
//设头指针为L的带有表头结点的非循环双向链表, 其每个结点中除有pred(前驱
//指针)、data(数据)和next(后继指针)域外, 还有一个访问频度域freq。在
//链表被启用前, 其值均初始化为零。每当在链表中进行一次 Locate(L, x)运算时
//令元素值为ⅹ的结点中freq域的值增1, 并使此链表中结点保持按访问频度非增
//(递减)的顺序排列, 同时最近访问的结点排在频度相同的结点前面, 以便使频繁
//访问的结点总是靠近表头。试编写符合上述要求的 Locate(L, x)运算的算法, 该
//运算为函数过程, 返回找到结点的地址, 类型为指针型

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region 建立带头结点的双链表

typedef struct LNode {
	ElemType data;
	struct LNode* next, * prior;
	int freq = 0;
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
	L->prior = NULL;
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
	head->next = NULL;
	LinkList p = head;
	_for(i, 0, data.size()) {
		LNode* s = (LinkList)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		s->prior = p;
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
	LinkList plist = list->next;
	while (plist != NULL) {
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


//P42.20
LNode* Locate(LinkList L, int x) {
	LinkList p = L->next, pre = L;
	for (; p && p->data != x; p = p->next);
	if (!p) {
		cout << "x is not exist!" << endl;
		return NULL;
	}
	else {
		(p->freq)++;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		pre = p->prior;
		for (; pre != L && pre->freq <= p->freq; pre = pre->prior);
		p->next = pre->next;
		pre->next->prior = p;
		p->prior = pre;
		pre->next = p;
	}
	return p;
}

int main()
{
	cout << "输入数据:" << endl;
	vector<int> data1{ 1,3,4,7,2,1 }; 
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	cout << "测试结果:" << endl;
	Locate(A, 3);
	Locate(A, 99);
	Locate(A, 4);
	Locate(A, 4);
	Locate(A, 2);
	Locate(A, 7);
	PrintList(A);
	return 0;
}
