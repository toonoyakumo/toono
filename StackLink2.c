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
	//û�б�����Ԫ��s ����0
	//������Ԫ��s ����ϵ����ӣ�=0 ����1
	//������ Ԫ��s ����ϵ�����==0 ����-1

	StackNode *r = ls;
	while (r->next) {
		printf("lable1=======,r.date2=%d,s.date2=%d\n", r->next->date2,
				s->date2);
		if (r->next->date2 == s->date2) {
			printf("==\n");
			//Ԫ��s ָ����ͬ
			if (r->next->date + s->date == 0) {
				//ָ������
				printf("-1\n");
				return -1;

			} else {
				//ָ��������
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
	//ѹջʱ�����ж� �Ƿ�����������ʽ�� ������������ѹջ
	//����������ж�����ʽ��ϵ������Ƿ�=0 ������0�ϲ�
	//���=0�� �ҵ����λ�õ� ǰһ�� λ��ָ�� �����Ԫ��ɾ�� �������
	flag = getElemEqual(ls, s);

	if (flag == 0) {
		//û�б�����Ԫ��s ����0,����ѹջ
		r->next = s;
		s->next = null;
	}

	printf("flag=%d\n", flag);
	if (flag == 1) {

		p = getElemPoint(ls, s);
//////������Ԫ��s ����ϵ����ӣ�=0 ����1
//		//�ҵ����Ԫ�ص�ǰһ��Ԫ�ص�ָ��
		p->next->date += x;
//
////		Ȼ�����
//
	}
	if (flag == -1) {
		p = getElemPoint(ls, s);
		//�ҵ����Ԫ�ص�ǰһ��ָ��
		//ɾ����ǰԪ��
		//r=r.next
		p->next = p->next->next;

	}
	return ls;

}

StackNode* pop(LinkStack ls) {
//����һ��λ��
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
