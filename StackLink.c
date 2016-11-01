/*
 ============================================================================
 Name        : StackLink.c
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

typedef struct LinkNode {
	ElemType date;
	struct LinkNode *next;
}*LinkStack, StackNode;

StackNode* getPoint(LinkStack ls, int flag) {
	StackNode *r = ls;
	StackNode *p = ls;
	if (flag == 0 && ls->next == null) {
		printf("linkstack  null\n");
		exit(0);
	}
	if (flag == 0) {
		while (r->next != null) {
			p = r;
			r = r->next;
		}
	}
	while (r->next != null) {
		r = r->next;
	}
	if (flag == 0) {
		return p;
	} else {
		return r;
	}
}

LinkStack push(LinkStack ls, ElemType x) {
	StackNode *r;
	r = getPoint(ls, 1);
	StackNode *s = malloc(sizeof(StackNode));
	s->date = x;
	r->next = s;
	s->next = null;
	return ls;
}

StackNode* pop(LinkStack ls) {
//返回一个位置
	StackNode *r, *s;
	r = getPoint(ls, 0);
	s = r->next;
	r->next = null;
	return s;
}

void outLinkStack(LinkStack ls) {
	int i = 1;
	StackNode *r = ls->next;
	while (r && ls != null) {
		printf("%d:%d\n", i++, r->date);
		r = r->next;
	}

}
LinkStack createStackLink(LinkStack ls) {
	StackNode *s = malloc(sizeof(StackNode));
	if (s != null) {
		s->next = null;
	}
	ls = s;
	return ls;
}

int main(void) {
	puts("begin\n"); /* prints ok */
	LinkStack p = null;
	p = createStackLink(p);
pop(p);
	push(p, 2);
	push(p, 2);
	push(p, 4);
	push(p, 2);
	push(p, 4);

	push(p, 4);
	pop(p);
	pop(p);
	pop(p);
	outLinkStack(p);

	printf("end\n");

	return EXIT_SUCCESS;

}
