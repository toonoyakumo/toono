/*
 ============================================================================
 Name        : SqList.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "../_h/SqList.h"//头文件地址

void outlist(SqList *L) {
	int i = 0;
	while (i < L->length) {
		printf("%d\t", (*L).elem[i]);
		i++;
	}
	printf("\n");
}
void inlist(SqList *L, int len) {
	int i = 0;
	while (i < len) {
		L->elem[i] = i;
		L->length += 1;
		i++;
	}
}
void insrandLinst(SqList *L, int x, int len_a, int len_b) {
	int i = 0;
	//判定 len_a 与 Len_b 的位置
	if (!(0 <= len_a && len_a < len_b && len_a <= L->length
			&& len_b <= L->listsize)) {
		printf("a to b point error\n");
		exit(error); //判定是否满足值域  0<lena<=length and lena<lenb<listsize
	}
	srand((int) time(0));
	if (L == NULL)
		exit(error); //判断线性表是否为空
	for (i = len_a; i < len_b; i++) {
		L->elem[i] = rand() % x + 1; //申城随机数并赋值
	}
	L->length = len_b;
}
int main(void) {
	SqList *list = malloc(sizeof(int));	//看着初始化总是黄色警告心烦
	SqList *list2 = malloc(sizeof(int));	//看着初始化总是黄色警告心烦
	SqList *l3 = malloc(sizeof(int));	//重要的事情重复三次

	InitList(list);   //这里面不能将一个指针 指定为空
	InitListsize(list2, 10);
	inlist(list, 10);
	insrandLinst(list2, 20, 0, list->listsize);
	outlist(list);
	printf("1 listsize:%d   2 length :%d  \n", list->listsize, list->length);
	int p = 99;
	ListInsert(list, 10, p);
	printf("1 listsize:%d   2 length :%d  \n", list->listsize, list->length);
	outlist(list);
	printf("this  listdel %d\n", ListDel(list, 5));
	printf("1 listsize:%d   2 length :%d  \n", list->listsize, list->length);
	printf(" 十月十一日\n");
	int a = 9;
	printf("%d", LocateElem(list, &a));
	printf("=====================\n");
	outlist(list2);
	printf("===================\n");
	mergeList(list, list2);
	outlist(list);
	printf("十一月十一日下午===============\n");

//从新赋值下
	insrandLinst(list, 30, 0, list->listsize);
	insrandLinst(list2, 30, 0, list2->listsize);
	//排序下
	ascList(list);
	ascList(list2);
	printf("=========================");
	outlist(list);
	outlist(list2);
	printf("\n%d\n%d\n", list->length, list2->length);
	InitListsize(l3, 30);
	*l3 = mergeListByL1ByL2(list, list2);
	outlist(l3);
	printf("%d", l3->length);
	printf("ok");
	return EXIT_SUCCESS;
}
