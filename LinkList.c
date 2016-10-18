/*
 ============================================================================
 Name        : LinkList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

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

LinkList CreatList2(LinkList L) {

	int x=0;
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
void outLinkList(LinkList L){
LNode *r=L;
	while(r->next!=null){//因为链表赋值的时候第一个是没有date只有next的结点
		printf("%d\t",r->next->data);
		r=r->next;

	}
	printf("\n");
}
int main(void) {
LinkList list;
list=(LinkList)CreatList2(list);
outLinkList(list);
printf("ok");

	return 0;
}
