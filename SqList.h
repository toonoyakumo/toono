/*
 * SqList.h
 *
 *  Created on: 2016年10月11日
 *      Author: Administrator
 */

#ifndef H_SQLIST_H_

#define H_SQLIST_H_

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

typedef struct {
	int *elem;   //定义了顺序表中元素类型的数组指针，指向顺序表存储空间的基址
	int length;       //顺序表的长度(也即元素个数)
	int listsize;     //当前分配给顺序表的存储容量
} SqList;

int InitList(SqList *L) {     //初始化线性表list
	L->elem = malloc(LIST_INIT_SIZE * sizeof(int));
	printf(" malloc +++++++ size %d \n ", (int) L->elem);
	if (L->elem == 0) {     //判定如果分配不成功则退出
		exit(-1);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return ok;
}

int isListSize(SqList *L) {     //判断 队满
	//如果 满了  则0 否则1
	if (L->listsize == L->length) {	//如果分配空间=元素空间=队满
		printf("nonononononononono");
		return 0;
	} else
		return 1;

}

int ReList(SqList *L) {     //扩充 list
	printf("************************");
	if (L->elem == 0) {
		exit(error);
	}
	int *q;

	q = realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
	printf("\n   this realloc +++++++ size %d \n ", (int) q);
	if (q != null) {     //释放掉 会不会 q就访问不到了，初测可能不会
		free(L->elem);
		L->elem = q;
		L->listsize += LISTINCREMENT;
	}
	return ok;
}

int ispoint(SqList *L, int x) {     //判断插入元素的位置是否合法
	if (x < 0 || x > L->length + 1) {
		printf("x-- point  error\n");
		exit(overflow);
	} else {
		return 1;
	}
}

int ListInsert(SqList (*L), int x, int e) {     //向第x个位置前面插入一个元素
	int i = 0;
	ispoint(L, x);     //判断插入位置
	if (isListSize(L) == 0) { //判断队满
		ReList(L); //满了就扩充
	}
	for (i = L->length; i > x; i--) { //移动位置
		L->elem[i] = L->elem[i - 1];
	}
	L->elem[x] = e; //插入数据
	L->length += 1; //更新元素个数
	return ok;
}
int ListDel(SqList (*L), int x) { //删除第x位置的元素并返回
	int i = 0;
	ispoint(L, x); //判定下删除的位置合法性
	int e = L->elem[x]; //先将 元素赋值给 e
	for (i = x + 1; i < L->length; i++) { //挨个移动 覆盖过去
		L->elem[i] = L->elem[i + 1];
	}
	L->length -= 1; //更新元素个数
	return e; //返回删除的元素
}

int Compare(int *e1, int *e2) {
	if (*e1 == *e2) {
		return 1;
	} else
		return 0;
}
int LocateElem(SqList *L, int *e) { //返回某个元素的下标
	int i = 0;
	for (i = 0; i < L->length; i++) { //遍历元素
		if (Compare(&(L->elem[i]), e)) {//比较是否相等
			return i;//相等返回
		}
	}
	return -1;//e不在L中
}
int mergeList(SqList *L1, SqList *L2) { //存在e属于L2但不属于L1，则放入L1中
	int i = 0;
	if (L1 == 0 || L2 == 0) {	//先判断他们非空
		exit(error);
	}
	for (i = 0; i < L2->length; i++) {	//遍历 L2 中的每一个元素
		//在每一个for中  做的仅仅是 拿到当前的 一个元素  和 L1 中所有元素进行比较，并且符合条件的插入
		int *e = &(L2->elem[i]);	//当前元素放入e  便于理解
		if (LocateElem(L1, e) == -1) {	//当前元素e 如果不在L1中
			ListInsert(L1, L1->length, *e);	//插入
		}
	}
	return ok;
}

#endif /* H_SQLIST_H_ */
