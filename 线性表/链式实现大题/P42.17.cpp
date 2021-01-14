#include <iostream>
#include <vector>
using namespace std;

//P42.17
//设计一个算法用于判断带头结点的循环双链表是否对称

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f

#pragma region 建立带头结点的循环双链表

typedef struct LNode {
	ElemType data;
	struct LNode* next, * prior;
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
	L->prior = L;
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
		s->prior = p;
		p->next = s;
		p = s;
	}
	p->next = head;
	head->prior = p;
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


//P42.17

bool Palindrome(LinkList& A) {
	LinkList P = A->next;
	LinkList Q = A->prior;
	for (; P->data == Q->data && (P->prior != Q && P != Q ); P = P->next, Q = Q->prior);
	if (P->prior == Q || P == Q)
		return true;
	return false;

}

int main()
{
	cout << "输入数据:" << endl;
	vector<int> data1{ 1,3,7,7,3,1 }; // 偶数
	/*vector<int> data1{ 1,3,7,9,7,3,1 };*/  //奇数 
	LinkList A;
	InitList(A);
	A = CreatList(data1);
	PrintList(A);
	cout << "测试结果:" << endl;
	if (Palindrome(A)) {
		cout << "序列A对称" << endl;
	}
	else {
		cout << "序列A不对称" << endl;
	}
	return 0;
}
