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

typedef struct DNode {
	ElemType data;
	struct DNode *prior, *next;

} DNode, *DLinkList;

DLinkList CreatList1(DLinkList dl) {
	int x = 0;
	dl = (DLinkList) malloc(sizeof(DNode));
	DNode *s;
	dl->next = null;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList) malloc(sizeof(DNode));
		s->data = x;
		s->next = dl->next;
		if (s->next != null)
			s->next->prior = s;
		s->prior = dl;
		dl->next = s;
		scanf("%d", &x);
	}

	return dl;
}

DNode *GetElem(DLinkList dl, int n) {
	int i = 1;
	DNode *p = dl->next;
	if (n == 0)
		printf("0");
	exit(0);
	if (n < 1)
		return null;
	while (p && i < n) {
		p = p->next;
		i++;
	}
	return p;
}

DLinkList DLinkListPointInsert(DLinkList dl, int n, DNode *x) {
	//查询是否有这个位置 ，有则返回位置
	DNode *p;
	p = (DNode *) malloc(sizeof(DNode));
	p = GetElem(dl, n - 1);
	if (!p) {
		printf("null");
		exit( false);
	}
//插入
	x->next = p->next;
	x->prior = p;
	x->next->prior = x;
	p->next = x;

	return dl;
}
//插入到某个元素的后面
DLinkList DLinkListElmeInsert(DLinkList dl, DNode w, DNode x) {
//查询是否有这个元素 有则返回位置
	//插入

	return dl;
}

DLinkList CreatList2(DLinkList dl) {
	int x = 0;
	dl = (DLinkList) malloc(sizeof(DNode));
	DNode *s, *r = dl;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DLinkList) malloc(sizeof(DNode));
		s->data = x;
		s->prior = r;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = null;
	return dl;
}

void outLinkList(DLinkList L) {
	DNode *r = L->next;
	while (r != null) { //因为链表赋值的时候第一个是没有date只有next的结点
		printf("%d\t", r->data);
		if (r->prior != null && r->prior != L)
			printf("prior.data=%d\t", r->prior->data);
		if (r->next != null)
			printf("next.data=%d\t", r->next->data);

		printf("\n");
		r = r->next;
	}
	printf("\n");
}

int main(void) {
	DLinkList list1;
	DNode *a;
	a = malloc(sizeof(DNode));
	a->data = 44;
	list1 = malloc(sizeof(DNode));
	list1 = CreatList2(list1);
	outLinkList(list1);

	list1 = DLinkListPointInsert(list1, 0, a);

	outLinkList(list1);

	printf("hello ");
	return 0;
}
