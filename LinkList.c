#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define true 1
#define FALSE 0
#define false 0
#define OK 1
#define ok 1
#define ERROR 0
#define error 0
#define null 0
#define INFEASIBLE -1
#define infeasible -1
#define OVERFLOW -2
#define overflow -2
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
#define ElemType int

typedef struct LNode {
	ElemType data;
	struct LNode *next;

} LNode, *LinkList;

LinkList CreatList1(LinkList L) {
	int x = 0;
	L = (LinkList) malloc(sizeof(LNode));
	LNode *s;
	L->next = null;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode *) malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}
LinkList CreatList2(LinkList L) {
	int x = 0;
	L = (LinkList) malloc(sizeof(LNode));
	LNode *s, *r = L;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode *) malloc(sizeof(LNode));
		s->data = x;
		s->next = null;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = null;
	return L;
}
void outLinkList(LinkList L) {
	LNode *r = L->next;
	while (r != null) { //因为链表赋值的时候第一个是没有date只有next的结点
		printf("%d\t", r->data);
		r = r->next;
	}
	printf("\n");
}
LNode *GetElem(LinkList L, int n) {
	int i = 1;
	LNode *p = L->next;
	if (n == 0)
		return L;
	if (n < 1)
		return null;
	while (p && i < n) {
		p = p->next;
		i++;
	}
	return p;
}
LNode * LocateElem(LinkList L, int x) {
	LNode *p = L->next;
	while (p->data != x && p) {
		p = p->next;
	}
	return p;
}

LinkList LinkListInsert(LinkList L, LNode* x, int n) {
	//判定 插入位置n是否合法
	LNode *p;
	p = (LNode *) malloc(sizeof(LNode));
	p = GetElem(L, n - 1);
	if (!p) {
		return false;
	}
	x->next = p->next;
	p->next = x;

	return L;
}
LinkList LinkListDelElem(LinkList L, int x) {
	LNode *p = L->next, *q = L;
	while (p->data != x && p) {
		p = p->next;
		q = q->next;
	}
	if (p != null) {

		q->next = q->next->next;

	}

	return L;
}
LinkList LinkListDelPoint(LinkList L, int n) {
//	int i = 0;
	LNode *p;
	p = (LNode *) malloc(sizeof(LNode));
	p = GetElem(L, n - 1);
	p->next = p->next->next;
	return L;
}

LinkList MergeLinkList(LinkList L1, LinkList L2, LinkList L3) {
	LNode *node1 = L1->next, *node2 = L2->next, *node3 =L3;
	int i = 1;
	while (node1 && node2) {
		if (node1->data < node2->data) {
			node3->next = node1;
			node3 = node3->next;
			node1 = node1->next;

		} else {
			node3->next = node2;
			node3 = node3->next;
			node2 = node2->next;
		}
	}
//判断下
	if (node1) {
		node3->next = node1;

	} else {
		node3->next = node2;
	}

	return L3;
}

int main(void) {
	LinkList list;
	LinkList list2, list3;
	LNode *p;
	p = (LNode *) malloc(sizeof(LNode));
	LNode *q;
	q = (LNode *) malloc(sizeof(LNode));
	list = (LinkList) CreatList2(list);
	list2 = (LinkList) CreatList2(list2);
	list3 = (LinkList) malloc(sizeof(LNode));
	list3->next = null;
	outLinkList(list);
	outLinkList(list2);
	printf("==========================\n");
	p = GetElem(list, 3);
	printf("p.date=%d\n", p->data);
	printf("=================\n");
	q->data = 1234;
	list = LinkListInsert(list, q, 3);

	outLinkList(list);
	list = LinkListDelPoint(list, 5);
	outLinkList(list);
	list = LinkListDelElem(list, 7);
	outLinkList(list);
	//list3=list1 并上 list2
	list3 = MergeLinkList(list, list2, list3);
	printf("============list3\n");
	outLinkList(list3);
	printf("ok");

	return 0;
}
