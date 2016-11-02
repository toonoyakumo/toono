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
	ElemType date2;
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
int getElemEqual(LinkStack ls, StackNode *s) {
	//没有遍历到元素s 返回0
	//遍历到元素s 并且系数相加！=0 返回1
	//遍历到 元素s 并且系数相加==0 返回-1

	StackNode *r = ls;
	while (r->next) {
		printf("lable1=======,r.date2=%d,s.date2=%d\n", r->next->date2,
				s->date2);
		if (r->next->date2 == s->date2) {
			printf("==\n");
			//元素s 指数相同
			if (r->next->date + s->date == 0) {
				//指数互补
				printf("-1\n");
				return -1;

			} else {
				//指数不互补
				printf("1\n");
				return 1;
			}
		}
		r = r->next;
	}

	return 0;
}

StackNode* getElemPoint(LinkStack ls, StackNode* s) {
	StackNode *r = ls, *p;
	p = malloc(sizeof(StackNode));
	while (r->next->date2 != s->date2) {

		r = r->next;

	}
	p = r;
	return p;
}

LinkStack push(LinkStack ls, ElemType x, ElemType y) {
	StackNode *p;
	StackNode *r;
	int flag = 0;
	StackNode *s = malloc(sizeof(StackNode));
	r = getPoint(ls, 1);
	s->date = x;
	s->date2 = y;
	//压栈时遍历判定 是否存在这个多项式； ，不存在正常压栈
	//如果存在在判定多项式的系数相加是否=0 ，不等0合并
	//如果=0则 找到这个位置的 前一个 位置指针 将这个元素删除 不做添加
	flag = getElemEqual(ls, s);

	if (flag == 0) {
		//没有遍历到元素s 返回0,正常压栈
		r->next = s;
		s->next = null;
	}

	printf("flag=%d\n", flag);
	if (flag == 1) {

		p = getElemPoint(ls, s);
//////遍历到元素s 并且系数相加！=0 返回1
//		//找到相等元素的前一个元素的指针
		p->next->date += x;
//
////		然后相加
//
	}
	if (flag == -1) {
		p = getElemPoint(ls, s);
		//找到相等元素的前一个指针
		//删掉当前元素
		//r=r.next
		p->next = p->next->next;

	}
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
		printf("%d:%d---%d\n", i++, r->date, r->date2);
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
	push(p, 1, 3);
	push(p, 2, 3);
	push(p, 3, 4);
	push(p, -3, 4);

	outLinkStack(p);

	printf("end\n");

	return EXIT_SUCCESS;

}
