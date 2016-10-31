/*
 * SqList.h
 *
 *  Created on: 2016��10��11��
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
	int *elem;   //������˳�����Ԫ�����͵�����ָ�룬ָ��˳����洢�ռ�Ļ�ַ
	int length;       //˳����ĳ���(Ҳ��Ԫ�ظ���)
	int listsize;     //��ǰ�����˳����Ĵ洢����
} SqList;

int InitList(SqList *L) {     //��ʼ�����Ա�list
	L->elem = malloc(LIST_INIT_SIZE * sizeof(int));
	printf(" malloc +++++++ size %d \n ", (int) L->elem);
	if (L->elem == 0) {     //�ж�������䲻�ɹ����˳�
		exit(-1);
	}
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return ok;
}
int InitListsize(SqList *L, int listsize) {     //InitList  @override
	printf("override\n");
	L->elem = malloc(listsize * sizeof(int));
	printf("listsize malloc +++++++ size %d \n ", (int) L->elem);
	if (L->elem == 0) {     //�ж�������䲻�ɹ����˳�
		exit(-1);
	}
	L->length = 0;
	L->listsize = listsize;
	return ok;
}

int isListSize(SqList *L) {     //�ж� ����
	//��� ����  ��0 ����1
	if (L->listsize == L->length) {	//�������ռ�=Ԫ�ؿռ�=����
		printf("nonononononononono");
		return 0;
	} else
		return 1;

}

int ReList(SqList *L) {     //���� list
	printf("************************");
	if (L->elem == 0) {
		exit(error);
	}
	int *q;
	q = realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(int));
	printf("\n   this realloc +++++++ size %d \n ", (int) q);
	if (q != null) {
		L->elem = q;
		L->listsize += LISTINCREMENT;
	}
	return ok;
}

int ispoint(SqList *L, int x) {     //�жϲ���Ԫ�ص�λ���Ƿ�Ϸ�
	if (x < 0 || x > L->length + 1) {
		printf("x-- point  error\n");
		exit(overflow);
	} else {
		return 1;
	}
}

int ListInsert(SqList (*L), int x, int e) {     //���x��λ��ǰ�����һ��Ԫ��
	int i = 0;
	ispoint(L, x);     //�жϲ���λ��
	if (isListSize(L) == 0) { //�ж϶���
		ReList(L); //���˾�����
	}
	for (i = L->length; i > x; i--) { //�ƶ�λ��
		L->elem[i] = L->elem[i - 1];
	}
	L->elem[x] = e; //��������
	L->length += 1; //����Ԫ�ظ���
	return ok;
}
int ListDel(SqList (*L), int x) { //ɾ����xλ�õ�Ԫ�ز�����
	int i = 0;
	ispoint(L, x); //�ж���ɾ����λ�úϷ���
	int e = L->elem[x]; //�Ƚ� Ԫ�ظ�ֵ�� e
	for (i = x + 1; i < L->length; i++) { //�����ƶ� ���ǹ�ȥ
		L->elem[i] = L->elem[i + 1];
	}
	L->length -= 1; //����Ԫ�ظ���
	return e; //����ɾ����Ԫ��
}

int Compare(int *e1, int *e2) {
	if (*e1 == *e2) {
		return 1;
	} else
		return 0;
}
int LocateElem(SqList *L, int *e) { //����ĳ��Ԫ�ص��±�
	int i = 0;
	for (i = 0; i < L->length; i++) { //����Ԫ��
		if (Compare(&(L->elem[i]), e)) { //�Ƚ��Ƿ����
			return i; //��ȷ���
		}
	}
	return -1; //e����L��
}
int mergeList(SqList *L1, SqList *L2) { //����e����L2��������L1�������L1��
	int i = 0;
	if (L1 == 0 || L2 == 0) {	//���ж����Ƿǿ�
		exit(error);
	}
	for (i = 0; i < L2->length; i++) {	//���� L2 �е�ÿһ��Ԫ��
		//��ÿһ��for��  ���Ľ����� �õ���ǰ�� һ��Ԫ��  �� L1 ������Ԫ�ؽ��бȽϣ����ҷ��������Ĳ���
		int *e = &(L2->elem[i]);	//��ǰԪ�ط���e  ��������
		if (LocateElem(L1, e) == -1) {	//��ǰԪ��e �������L1��
			ListInsert(L1, L1->length, *e);	//����
		}
	}
	return ok;
}

void ascList(SqList *L1) {
	int i, j, flag;
	for (i = 0; i < L1->length - 1; i++) {
		for (j = i; j < L1->length; j++) {
			if (L1->elem[i] > L1->elem[j]) {
				flag = L1->elem[i];
				L1->elem[i] = L1->elem[j];
				L1->elem[j] = flag;

			}
		}
	}
}

SqList mergeListByL1ByL2(SqList *L1, SqList *L2) {//L1,L2Ϊ����ݼ����Ա� ������L3ͬ������ݼ�  ������Դ ΪL1��L2�������ظ�����
	int i = 0, j = 0;
	if (L1 == null || L2 == null) {
		exit(error);
	}
	SqList *L3 = malloc(sizeof(int));	//�����ɫ�ľ���
	InitListsize(L3, L1->length + L2->length);	//��д��ʼ������  L3��listsize= L1+L2
	printf("\nL3.length  :%d\n", L3->length);
	while (i < L1->length && j < L2->length) {
		if (L1->elem[i] < L2->elem[j]) {	//�Ƚ�����Ԫ�� �ĸ�С��
			L3->elem[L3->length] = L1->elem[i];
			L3->length++;
			i++;

		} else {
			L3->elem[L3->length] = L2->elem[j];
			L3->length++;
			j++;
		}
	}
	while (i < L1->length) {
		L3->elem[L3->length++] = L1->elem[i++];
	}
	while (j < L2->length) {
		L3->elem[L3->length++] = L2->elem[j++];
	}
	return *L3;
}

#endif /* H_SQLIST_H_ */