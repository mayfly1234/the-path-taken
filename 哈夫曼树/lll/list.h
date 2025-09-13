#pragma once
#include<iostream>

#define OK 1
#define ERROR -1
#define MAXSIZE 1024

using namespace std;
typedef char Elem;//输入字母
typedef int weight;//权重


typedef struct SQList {
	Elem E[MAXSIZE];//字符元素
	weight W[MAXSIZE];//权值
	int top;
}Node,*LNode;//节点类型

int ListInit(LNode &L){
	L = new SQList;//分配空间
	L->top=0;//头
	return OK;
}

int ListAdd(LNode& L, Elem D, weight W) {
	if (L->top < MAXSIZE) {//判断是否溢出
		L->E[L->top] = D;
		L->W[L->top] = W;
		L->top++;
		//cout << "输入成功！";
		return OK;
	}
	else {
		cout << "输入错误!" << endl;
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
			cout << "删除成功！" << endl;
			return OK;
		}
	}
	cout << "删除失败，未找到该元素" <<D<< endl;
	return ERROR;
}

int ListVisit(LNode& L) {
	if (L->top == 0) {
		cout << endl<< "***无元素***" << endl;
		return ERROR;
	}
	else {
		for (int i = 0; i < L->top; i++) {
			cout << "----------------------" << endl;
			cout << "第" << i + 1 << "项" << endl;
			cout << "元素:'" << L->E[i] << "'" << endl;
			cout << "权重：" << L->W[i] << endl;

		}
		cout << "----------------------" << endl;
		return OK;
	}
}