#include <iostream>
#include <vector>
using namespace std;

//P43.22
//假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时,
//可共享相同的后缀存储空间，例如，“loading”和 “being”的存储映像如下图所示。
//设str1和str2分别指向两个单词所在单链表的头结点, 链表结点结构为data,next,
//请设计一个时间上尽可能高效的算法, 找出由Str1和str2所指向两个链表共同后缀
//的起始位置(如图中字符i所在结点的位置p)。要求
//1)给出算法的基本设计思想
//2)根据设计思想, 采用C或C++或Java语言描述算法, 关键之处给出注释
//3)说明你所设计算法的时间复杂度

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


//P42.22
LinkList FindCom(LinkList A,LinkList B) {
	int len1 = Getlen(A), len2 = Getlen(B), Diff = abs(len1 - len2);
	LinkList longlist, shortlist;
	if (len1 > len2) {
		longlist = A->next;
		shortlist = B->next;
	}
	else {
		longlist = B->next;
		shortlist = A->next;
	}
	while (Diff--)
		longlist = longlist->next;
	while (longlist) {
		if (longlist == shortlist)
			return longlist;
		longlist = longlist->next;
		shortlist = shortlist->next;
	}
}

int main()
{
	vector<int> data1{ 3,5,6,8,1,4,9,77 };
	vector<int> data2{ 2,5,7,88,31 };
	LinkList head1;
	LinkList head2;
	InitList(head1);
	InitList(head2);
	head1 = CreatList(data1);
	head2 = CreatList(data2);
	LinkList com = head1->next;
	LinkList P = head2->next;
	for (; com != NULL && com->data != 8; com = com->next);
	for (; P->next != NULL; P = P->next);
	P->next = com;
	PrintList(head1->next);
	PrintList(head2->next);
	LinkList C = FindCom(head1, head2);
	PrintList(C);
	return 0;
}
