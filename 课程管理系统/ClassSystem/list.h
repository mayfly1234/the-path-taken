#pragma once
#include<iostream>
#define OK 1
#define ERROR -1
#define MAXSIZE 50
using namespace std;
typedef string Class;


typedef struct ListNode {
	Class C;/*本课程名称*/
	Class subclass[MAXSIZE];/*后继课程*/
	int subclassnub=0;/*后继课程数量*/
	//Class preclass[MAXSIZE];/*前驱课程*/
	int preclassnub = 0;/*前驱课程数量*/
	int score = 0;
	struct ListNode* next;/*链表节点后续*/
}ListNode, * LNode;  /*结点类型, */

//////////////////////////////////////////////

int Listinit(LNode& L)//链表初始化
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
int ListSeach(LNode &L,Class C) {//查找，找到链表中课程名和C相同的节点
	LNode P = L->next;
	int n = 0;
	while (P->next != NULL) {
		if (P->C == C) {
			cout << "该课程名：" << P->C << endl;
			cout << "该课程的前驱课程数量："<<P->preclassnub << endl;
			cout << "该课程的后继课程数量："<<P->subclassnub << endl;
			cout << "后继课程为：" << endl;
			for (int i = 0; i < P->subclassnub; i++) {
				cout << i + 1 << "、" << P->subclass[i] << endl;
			}
			cout << "该课程的学分：" <<P->score<< endl;

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
			cout << "删除成功！" << endl;
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
	while (P->next != NULL)//找到队尾
	{
		P = P->next;
	}P->next = New;
	cout << "请输入课程" << endl;
	cin >> New->C;//输入课程
	cout << "请输入该课程学分" << endl;
	cin >> New->score;//输入学分
	cout << "请输入该课程的前驱课程数量：" << endl;
	cin >> New->preclassnub;
	cout << "请输入该课程的后继课程数量：" << endl;
	cin >> New->subclassnub;
	for (int i = 0; i < New->subclassnub; i++) {
		cout << "请输入第" << i + 1 << "个后继课程" << endl;
		cin >> New->subclass[i];
	}
	cout << "输入完成！" << endl;
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
			cout << "课程名：" << P->C << endl;
			cout << "学分：" << P->score << endl;
			cout << "后继课程：" << endl;
			for (int i = 0; i < P->subclassnub; i++) {
				cout << i + 1 << "、" << P->subclass[i] << endl;
			}
			cout << "前驱数量为：" << P->preclassnub << endl;
			cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;//分隔
			P = P->next;
		}
	}
}


