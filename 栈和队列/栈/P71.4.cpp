#include <iostream>
#include <vector>
using namespace std;

//P71.4
//设单链表的表头指针为L, 结点结构由data和next两个域构成, 其中data域为字
//符型。试设计算法判断该链表的全部n个字符是否中心对称。例如xyx、xyyx都是中
//心对称

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


//P71.4
bool Palindrome(LinkList L, int n) {
	int* s = (int*)malloc(sizeof(int) * (n / 2));
	LinkList p = L->next;
	int count = 0;
	for (count = 0; count < n / 2; count++) {
		s[count] = p->data;
		p = p->next;
	}
	count--;
	if (n % 2 == 1)
		p = p->next;

	while (p && s[count] == p->data) {
		count--;
		p = p->next;
	}
	free(s);
	if (count == -1)
		return true;
	return false;
}


int main()
{
	vector<int> data{ 1,2,3,4,4,3,2,1 };
	LinkList head;
	InitList(head);
	head = CreatList(data);
	PrintList(head);
	cout << Palindrome(head,data.size());
	return 0;
}
