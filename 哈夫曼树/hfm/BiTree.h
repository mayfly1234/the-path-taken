#pragma once
#include"list.h"
#include<iostream>

#define OK 1
#define ERROR -1
#define MAXSIZE 1024
using namespace std;
typedef char Elem;//输入字母
typedef int weight;//权重
char temp[MAXSIZE];
int top = 0;

typedef struct TreeNode {
	Elem E;//字符元素
	weight W=0;//权值
	char hafmcode[MAXSIZE];//哈夫曼编码
	int codeleng=0;//哈夫曼编码长度
	struct TreeNode* Next = NULL;//邻节点
	struct TreeNode* Lchild = NULL;//左孩子
	struct TreeNode* Rchild = NULL;//右孩子
	struct TreeNode* Parent = NULL;//父节点
}TreeNode, * TNode;

int TreeInit(TNode &T) {//初始化
	T = new TreeNode;
	return OK;
}

int TreeDataIn(TNode& T, LNode& L) { //将顺序表内的字符元素及其权重输入到二叉树中
	if (L->top != 0) {
		TNode P = T;
		for (int i = 0; i < L->top; i++) {
			TNode N = new TreeNode;
			N->E = L->E[i];
			N->W = L->W[i];
			P->Next = N;
			P = P->Next;
		}
		//cout << "输入成功！" << endl;
		return OK;
	}
	else {
		cout << "无数据输入!" << endl;
		return ERROR;
	}
}

int TreeNodeSort(TNode& T) {//对二叉树节点链表进行插入排序
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

int TreeListOut(TNode& T) {//输出二叉树的所有节点及各个节点的详细信息
	TNode P = T->Next;
	if (T->Next == NULL) {
		cout << "无数据" << endl;
		return ERROR;
	}
	else {
		cout << "字符名\t权值\t左孩子\t右孩子\t哈夫曼编码" << endl;
		while (P!= NULL)
		{
			cout << "------------------------------------------------" << endl;
			if (P->Lchild == NULL && P->Rchild == NULL) {
				cout << P->E << "\t" << P->W << "\t无\t无\t";
				for (int i = 0; i < P->codeleng; i++) {
					cout << P->hafmcode[i];
				}
				cout << endl;

			}else if(P->Lchild != NULL && P->Rchild == NULL) {
				cout << P->E << "\t" << P->W << "\t"<<P->Lchild->E<<"\t无\t - "<<endl;
			}
			else if(P->Lchild == NULL && P->Rchild != NULL) {
				cout << P->E << "\t" << P->W << "\t无\t"<< P->Rchild->E << "\t - "<<endl;
			}
			else {
				cout << P->E << "\t" << P->W << "\t" << P->Lchild->E << "\t" << P->Rchild->E << "\t - "<<endl;
			}
			P = P->Next;
		}
		cout << "------------------------------------------------" << endl;
	}return OK;
}


int TreeCreat(TNode &T) {//创建哈夫曼树，给所有树节点连接起来，非叶子节点字符用‘*’代替
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
	//cout << "成功" << endl;
	return OK;
}

void GetHafmCode(TNode &T,int top) {//递归获取哈夫曼编码，从树根开始读，读到左孩子给0，读到右孩子给1。
	top++;
	if (T->Lchild != NULL) {
		temp[top-1] = '0';
		GetHafmCode(T->Lchild,top);
	}
	if (T->Rchild != NULL) {
		temp[top-1] = '1';
		GetHafmCode(T->Rchild,top);
	}
	if (T->Lchild == NULL && T->Rchild == NULL) {//读到叶子，给其哈夫曼的编码
		T->codeleng = top-1;
		for (int i = 0; i < top; i++) {
			T->hafmcode[i] = temp[i];
		}

	}
}

void HafmEncodeInit(TNode &T) {//将递归的函数包装起来，输入正确的树根
	TNode C = T->Lchild;
	GetHafmCode(C, top);
	top = 0;
}

int HafmEncode(TNode &T,char E[], int len) {//输入一串字符数组及其长度，将其转化为哈夫曼编码
	TNode P = T->Next;
	cout << "编码结果为:" << endl;
	for (int i = 0; i < len; i++) {
		while (P->E != E[i])
		{
			P = P->Next;
			if (P == NULL) {
				break;
			}
		}
		if (P == NULL) {
			cout << "编码失败" << endl;
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
	cout << "译码结果为：";
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