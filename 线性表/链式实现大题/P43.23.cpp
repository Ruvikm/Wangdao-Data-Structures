#include <iostream>
#include <vector>
using namespace std;

//P43.23
//用单链表保存m个整数, 结点的结构为[data][1ink], 且 |data| ≤ n
//(n为正整数)。现要求设计一个时间复杂度尽可能高效的算法, 对于链表中data的绝对值
//相等的结点, 仅保留第一次出现的结点而删除其余绝对值相等的结点。
//要求
//1)给出算法的基本设计思想
//2)使用C或C + 语言, 给出单链表结点的数据类型定义
//3)根据设计思想, 采用C或C + 语言描述算法, 关键之处给出注释
//4)说明你所设计算法的时间复杂度和空间复杂度

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define INF 0x3f3f3f3f
#define N 30

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


//P43.23
void de_duplication(LinkList L) {
	vector<int> box(N + 1, 0);
	LinkList p = L->next, pre = L;
	while(p) {
		if (!box[abs(p->data)]) {
			box[abs(p->data)] = 1;
			pre = p;
			p = p->next;
		}
		else {
			LNode* r = p->next;
			pre->next = p->next;
			delete p;
			p = r;
		}
	}
	box.clear();
}

int main()
{
	vector<int> data{ 21,-11,-15,-7,15,11,13,15 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	de_duplication(head);
	PrintList(head);
	return 0;
}
