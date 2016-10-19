
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
	p = GetElem(L, n-1);
	if (!p) {
		return false;
	}
	x->next=p->next;
	p->next=x;

	return L;
}

int main(void) {
	LinkList list;
	LNode *p;
	p = (LNode *) malloc(sizeof(LNode));
	LNode *q;
	q = (LNode *) malloc(sizeof(LNode));
	list = (LinkList) CreatList2(list);
	outLinkList(list);
	printf("==========================\n");
	p = GetElem(list, 3);
	printf("p.date=%d\n", p->data);
	printf("=================\n");
	q->data=1234;
	list=LinkListInsert(list,q,3);
//	printf("f=%d====\n");
	outLinkList(list);
	printf("ok");

	return 0;
}
