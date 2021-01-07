/**
*作    者：Ruvik
*CSND地址：https://blog.csdn.net/ruvikm
**GitHub ：https://github.com/Ruvikm

//                .-~~~~~~~~~-._       _.-~~~~~~~~~-.
//            __.'              ~.   .~              `.__
//          .'//                  \./               \\`.
//        .'//                     |                     \\`.
//      .'// .-~"""""""~~~~-._     |     _,-~~~~"""""""~-. \\`.
//    .'//.-"                 `-.  |  .-'                 "-.\\`.
//  .'//______.============-..   \ | /   ..-============.______\\`.
//.'______________________________\|/______________________________`.
**/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <ctype.h>
#include <queue>
#include <list>
#include <map>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;

//P40.1

#define ElemType int
#define _for(i,a,b) for(int i=(a);i<=(b);i++)

typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

void DeleteXNode(LinkList linklist, ElemType X) {
}

LinkList CreatList(int len, vector<int> data) {
	if (len < 1) {
		return NULL;
	}
	LinkList head = (LinkList)malloc(sizeof(LNode));
	LinkList point = head;
	head->data = data[0];
	head->next = NULL;
	_for(i, 1, data.size()) {
		LNode* s = (LNode*)malloc(sizeof(LNode));
		s->data = data[i];
		s->next = NULL;
		point->next = s;
		point = s;
	}
}

void PrintList(LinkList list) {
	while (list->next != NULL) {
		printf("%d", list->data);
		list = list->next;
	}
}

int main()
{
	vector<int> data{ 2,4,6,1,5,3,7,41 };
	LinkList list;
	list = CreatList(8, data);
	PrintList(list);
	return 0;
}