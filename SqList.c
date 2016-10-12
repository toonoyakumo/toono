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
void insrandLinst(SqList *L, int len) {
	int i = 0;
	srand((int) time(0));
	if(L==NULL)exit(error);//判断线性表是否为空
	while (i < len) {
		L->elem[i] = rand() % 20 + 1;//申城随机数并赋值
		L->length += 1;
		i++;
	}
}

int main(void) {
	SqList *list = malloc(sizeof(int));	//看着初始化总是黄色警告心烦
	SqList *list2 = malloc(sizeof(int));	//看着初始化总是黄色警告心烦
	InitList(list);   //这里面不能将一个指针 指定为空
	InitList(list2);
	inlist(list, 10);
	insrandLinst(list2, 10);
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
	mergeList(list,list2);
	outlist(list);
	printf("ok");
	return EXIT_SUCCESS;
}
