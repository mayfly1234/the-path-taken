#pragma once
#include<iostream>
#define OK 1
#define ERROR -1
#define MAXSIZE 50
using namespace std;
typedef string Class;


typedef struct ListNode {
	Class C;/*���γ�����*/
	Class subclass[MAXSIZE];/*��̿γ�*/
	int subclassnub=0;/*��̿γ�����*/
	//Class preclass[MAXSIZE];/*ǰ���γ�*/
	int preclassnub = 0;/*ǰ���γ�����*/
	int score = 0;
	struct ListNode* next;/*����ڵ����*/
}ListNode, * LNode;  /*�������, */

//////////////////////////////////////////////

int Listinit(LNode& L)//�����ʼ��
{
	if (L = new ListNode)
	{
		L->next = NULL;
		return OK;
	}
	else {
		return ERROR;
	}
}//Listinit

/////////////////////////////////////////////
int ListSeach(LNode &L,Class C) {//���ң��ҵ������пγ�����C��ͬ�Ľڵ�
	LNode P = L->next;
	int n = 0;
	while (P->next != NULL) {
		if (P->C == C) {
			cout << "�ÿγ�����" << P->C << endl;
			cout << "�ÿγ̵�ǰ���γ�������"<<P->preclassnub << endl;
			cout << "�ÿγ̵ĺ�̿γ�������"<<P->subclassnub << endl;
			cout << "��̿γ�Ϊ��" << endl;
			for (int i = 0; i < P->subclassnub; i++) {
				cout << i + 1 << "��" << P->subclass[i] << endl;
			}
			cout << "�ÿγ̵�ѧ�֣�" <<P->score<< endl;

			return OK;
		}
		P = P->next;
	}
	if (P->next == NULL) {
		cout << "Not find!" << endl;
		return ERROR;
	}
}

////////////////////////////////////////////////////////
int ListDel(LNode& L, Class C) {
	LNode P = L;
	LNode Q = P->next;
	while (Q!= NULL) {
		if (Q->C == C) {
			P->next = Q->next;
			Q->next = NULL;
			free(Q);
			cout << "ɾ���ɹ���" << endl;
			return OK;
		}
		P = P->next;
		Q = Q->next;
	}
}

void ListAdd(LNode &L)
{
	LNode New = new ListNode;
	New->next = NULL;
	LNode P = L;
	while (P->next != NULL)//�ҵ���β
	{
		P = P->next;
	}P->next = New;
	cout << "������γ�" << endl;
	cin >> New->C;//����γ�
	cout << "������ÿγ�ѧ��" << endl;
	cin >> New->score;//����ѧ��
	cout << "������ÿγ̵�ǰ���γ�������" << endl;
	cin >> New->preclassnub;
	cout << "������ÿγ̵ĺ�̿γ�������" << endl;
	cin >> New->subclassnub;
	for (int i = 0; i < New->subclassnub; i++) {
		cout << "�������" << i + 1 << "����̿γ�" << endl;
		cin >> New->subclass[i];
	}
	cout << "������ɣ�" << endl;
	cout << "=========================" << endl;
}// ListAdd

////////////////////////////////////////////////////////

int ListVisit(LNode& L) {
	LNode P = L->next;
	if (L->next == NULL) {
		return ERROR;
	}
	else {
		while (P!=NULL)
		{
			cout << "�γ�����" << P->C << endl;
			cout << "ѧ�֣�" << P->score << endl;
			cout << "��̿γ̣�" << endl;
			for (int i = 0; i < P->subclassnub; i++) {
				cout << i + 1 << "��" << P->subclass[i] << endl;
			}
			cout << "ǰ������Ϊ��" << P->preclassnub << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;//�ָ�
			P = P->next;
		}
	}
}


