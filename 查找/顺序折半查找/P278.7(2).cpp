#include <iostream>
#include <vector>
using namespace std;

#pragma region 建立带头结点的链表

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)

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

//P278.7(2)
//线性表中各结点的检索概率不等时,可用如下策略提高顺序检索的效率:若找到指定的
//结点,则将该结点和其前驱结点(若存在)交换, 使得经常被检索的结点尽量位于表的
//前端。试设计在顺序结构和链式结构的线性表上实现上述策略的顺序裣索算法。

//链式实现

int Search(LinkList &head,ElemType key) {

	int i = 0;
	LinkList p = head->next,pre=head;
	while (p && p->data != key) {
		i++;
		pre = p;
		p = p->next;
	}
	if (p) {
		swap(p->data, pre->data);
		return --i;
	}
	return -1;
}

int main()
{
	vector<int> data{ 2,4,6,8,13,23,36,41,63 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	cout << "位置为：" << Search(head, 8) << endl;
	cout << "位置为：" << Search(head, 8) << endl;
	cout << "位置为：" << Search(head, 8) << endl;
	cout << "位置为：" << Search(head, 41) << endl;
	cout << "位置为：" << Search(head, 41) << endl;
	PrintList(head);
	return 0;
}
