#pragma once
#include<iostream>

#define OK 1
#define ERROR -1
#define MAXSIZE 1024

using namespace std;
typedef char Elem;//������ĸ
typedef int weight;//Ȩ��


typedef struct SQList {
	Elem E[MAXSIZE];//�ַ�Ԫ��
	weight W[MAXSIZE];//Ȩֵ
	int top;
}Node,*LNode;//�ڵ�����

int ListInit(LNode &L){
	L = new SQList;//����ռ�
	L->top=0;//ͷ
	return OK;
}

int ListAdd(LNode& L, Elem D, weight W) {
	if (L->top < MAXSIZE) {//�ж��Ƿ����
		L->E[L->top] = D;
		L->W[L->top] = W;
		L->top++;
		//cout << "����ɹ���";
		return OK;
	}
	else {
		cout << "�������!" << endl;
		return ERROR;
	}
}

int ListDel(LNode& L, Elem D) {
	for (int i = 0; i < L->top; i++) {
		if (L->E[i] == D) {
			while (i + 1 < L->top)
			{
				L->E[i] = L->E[i + 1];
				L->W[i] = L->W[i + 1];
				i++;
			} L->top--;
			cout << "ɾ���ɹ���" << endl;
			return OK;
		}
	}
	cout << "ɾ��ʧ�ܣ�δ�ҵ���Ԫ��" <<D<< endl;
	return ERROR;
}

int ListVisit(LNode& L) {
	if (L->top == 0) {
		cout << endl<< "***��Ԫ��***" << endl;
		return ERROR;
	}
	else {
		for (int i = 0; i < L->top; i++) {
			cout << "----------------------" << endl;
			cout << "��" << i + 1 << "��" << endl;
			cout << "Ԫ��:'" << L->E[i] << "'" << endl;
			cout << "Ȩ�أ�" << L->W[i] << endl;

		}
		cout << "----------------------" << endl;
		return OK;
	}
}