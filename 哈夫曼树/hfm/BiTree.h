#pragma once
#include"list.h"
#include<iostream>

#define OK 1
#define ERROR -1
#define MAXSIZE 1024
using namespace std;
typedef char Elem;//������ĸ
typedef int weight;//Ȩ��
char temp[MAXSIZE];
int top = 0;

typedef struct TreeNode {
	Elem E;//�ַ�Ԫ��
	weight W=0;//Ȩֵ
	char hafmcode[MAXSIZE];//����������
	int codeleng=0;//���������볤��
	struct TreeNode* Next = NULL;//�ڽڵ�
	struct TreeNode* Lchild = NULL;//����
	struct TreeNode* Rchild = NULL;//�Һ���
	struct TreeNode* Parent = NULL;//���ڵ�
}TreeNode, * TNode;

int TreeInit(TNode &T) {//��ʼ��
	T = new TreeNode;
	return OK;
}

int TreeDataIn(TNode& T, LNode& L) { //��˳����ڵ��ַ�Ԫ�ؼ���Ȩ�����뵽��������
	if (L->top != 0) {
		TNode P = T;
		for (int i = 0; i < L->top; i++) {
			TNode N = new TreeNode;
			N->E = L->E[i];
			N->W = L->W[i];
			P->Next = N;
			P = P->Next;
		}
		//cout << "����ɹ���" << endl;
		return OK;
	}
	else {
		cout << "����������!" << endl;
		return ERROR;
	}
}

int TreeNodeSort(TNode& T) {//�Զ������ڵ�������в�������
	if (T->Next == NULL) {
		return ERROR;
	}
	TNode P = T;
	TNode Pnext = P->Next;
	while (true)
	{
		if (Pnext->W<P->W) {
			TNode Q = T;
			TNode Qnext = Q->Next;
			while (Q!=P) {
				if (Qnext->W > Pnext->W) {
					P->Next = Pnext->Next;
					Pnext->Next = Qnext;
					Q->Next = Pnext;
					break;
				}
				Q = Q->Next;
				Qnext = Q->Next;
			}
		}
		else {
			P = P->Next;
		}
		if (P == NULL || P->Next == NULL) {
			return OK;
		}
		Pnext = P->Next;
	}
}

int TreeListOut(TNode& T) {//��������������нڵ㼰�����ڵ����ϸ��Ϣ
	TNode P = T->Next;
	if (T->Next == NULL) {
		cout << "������" << endl;
		return ERROR;
	}
	else {
		cout << "�ַ���\tȨֵ\t����\t�Һ���\t����������" << endl;
		while (P!= NULL)
		{
			cout << "------------------------------------------------" << endl;
			if (P->Lchild == NULL && P->Rchild == NULL) {
				cout << P->E << "\t" << P->W << "\t��\t��\t";
				for (int i = 0; i < P->codeleng; i++) {
					cout << P->hafmcode[i];
				}
				cout << endl;

			}else if(P->Lchild != NULL && P->Rchild == NULL) {
				cout << P->E << "\t" << P->W << "\t"<<P->Lchild->E<<"\t��\t - "<<endl;
			}
			else if(P->Lchild == NULL && P->Rchild != NULL) {
				cout << P->E << "\t" << P->W << "\t��\t"<< P->Rchild->E << "\t - "<<endl;
			}
			else {
				cout << P->E << "\t" << P->W << "\t" << P->Lchild->E << "\t" << P->Rchild->E << "\t - "<<endl;
			}
			P = P->Next;
		}
		cout << "------------------------------------------------" << endl;
	}return OK;
}


int TreeCreat(TNode &T) {//�����������������������ڵ�������������Ҷ�ӽڵ��ַ��á�*������
	TNode Fir = T->Next;
	TNode Sec = Fir->Next;
	while (Sec!=NULL)
	{
		TNode N = new TreeNode;
		TNode P = T;
		while (P->Next != NULL) {
			P = P->Next;
		}
		P->Next = N;
		N->W = Fir->W + Sec->W;
		N->E = '*';
		N->Lchild = Fir; N->Rchild = Sec;
		Fir->Parent = N;
		Sec->Parent = N;
		TreeNodeSort(T);
		Fir = T->Next;
		while (Fir->Parent != NULL) {
			Fir = Fir->Next;
		}
		Sec = Fir->Next;
		while (Sec!=NULL&&Sec->Parent!=NULL) {
			Sec = Sec->Next;
		}
	}
	T->Lchild = Fir;
	Fir->Parent = T;
	//cout << "�ɹ�" << endl;
	return OK;
}

void GetHafmCode(TNode &T,int top) {//�ݹ��ȡ���������룬��������ʼ�����������Ӹ�0�������Һ��Ӹ�1��
	top++;
	if (T->Lchild != NULL) {
		temp[top-1] = '0';
		GetHafmCode(T->Lchild,top);
	}
	if (T->Rchild != NULL) {
		temp[top-1] = '1';
		GetHafmCode(T->Rchild,top);
	}
	if (T->Lchild == NULL && T->Rchild == NULL) {//����Ҷ�ӣ�����������ı���
		T->codeleng = top-1;
		for (int i = 0; i < top; i++) {
			T->hafmcode[i] = temp[i];
		}

	}
}

void HafmEncodeInit(TNode &T) {//���ݹ�ĺ�����װ������������ȷ������
	TNode C = T->Lchild;
	GetHafmCode(C, top);
	top = 0;
}

int HafmEncode(TNode &T,char E[], int len) {//����һ���ַ����鼰�䳤�ȣ�����ת��Ϊ����������
	TNode P = T->Next;
	cout << "������Ϊ:" << endl;
	for (int i = 0; i < len; i++) {
		while (P->E != E[i])
		{
			P = P->Next;
			if (P == NULL) {
				break;
			}
		}
		if (P == NULL) {
			cout << "����ʧ��" << endl;
			return ERROR;
		}
		if (P->E == E[i]) {
			for (int j = 0; j < P->codeleng; j++) {
				cout << P->hafmcode[j];
			}
		}
		P = T->Next;
	}return OK;
}

int HafmDecode(TNode &T,char n[],int len) {
	TNode P = T->Lchild;
	cout << "������Ϊ��";
	for (int i = 0; i < len; i++) {
		if (n[i] =='0') {
			P = P->Lchild;
		}
		else {
			P = P->Rchild;
		}
		if (P->Lchild == NULL && P->Rchild == NULL) {
			cout << P->E;
			P = T->Lchild;
		}
	}
	return OK;
}