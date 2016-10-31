/*
 ============================================================================
 Name        : stack.c
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
#define MaxSize 50

typedef struct {
	ElemType data[MaxSize];
	int top;
} SqStack;

SqStack* CreateStack() {
	SqStack *p;
	p = malloc(sizeof(SqStack));
	p->top = -1;
	return p;
}
//Õ»¿Õ ==-1£¬Õ»Âú==1
int isStackMax(SqStack *ss, int flag) {
	if (ss->top == -1 && flag == -1) {
		printf("is stack null ");
		exit(-1);
	}
	if (ss->top == MaxSize - 1 && flag == 1) {
		printf("is stack maxsize over");
		exit(1);
	}
	return 0;
}
int getTop(SqStack *ss) {
	isStackMax(ss, -1);
	return ss->data[ss->top];

}

int pop(SqStack *ss) {
	//ÅÐ¶Ï¶Ô¿Õ¶ÓÂú
	ElemType x;
	isStackMax(ss, -1);
	x = ss->data[ss->top--];
	return x;
}

int push(SqStack *ss, ElemType x) {
	//ÅÐ¶Ï¶Ô¿Õ¶ÓÂú
	isStackMax(ss, 1);
	ss->data[++ss->top] = x;

	return x;
}

void outStack(SqStack *ss) {
	int i = 0;
	for (i = 0; i <= ss->top; i++) {
		printf("%d-data:%d\n", i, ss->data[i]);
	}

}

int main(void) {
	printf("begin\n");
	SqStack *sq1 = CreateStack();
//pop(sq1);//²âÊÔ¶Ô¿Õ
	push(sq1, 3);
	push(sq1, 4);
	push(sq1, 77);
//	sq1->top = MaxSize - 1; //²âÊÔ¶ÓÂú
	push(sq1, 78);

	printf("%d\n", sq1->top);
	outStack(sq1);

	printf("end\n");

	return EXIT_SUCCESS;
}
