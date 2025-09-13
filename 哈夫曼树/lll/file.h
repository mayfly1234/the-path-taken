#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"list.h"
#include"BiTree.h"
#define ERROR -1

int EncodeFromfile(TNode &T) {
	fstream fin;
	fin.open("Encode.txt", ios::in);;//打开文件
	if (!fin.is_open()) {
		cout << "文件打开失败！" << endl;//判断是否打开
		return ERROR;
	}
	char Inline[MAXSIZE];
	int top = 0;
	while (fin>>Inline[top])//从文件中读取字符和权重
	{
		top++;
	}
	HafmEncode(T, Inline, top);//进行编码
	fin.close();

	return OK;
} 

int DecodeFromfile(TNode& T) {
	fstream fin;
	fin.open("Decode.txt", ios::in );
	if (!fin.is_open()) {
		cout << "文件打开失败！" << endl;
		return ERROR;
	}
	char Inline[MAXSIZE];
	int top = 0;
	while (fin >> Inline[top])
	{
		top++;
	}
	HafmDecode(T, Inline, top);
	fin.close();

	return OK;
}

int GetElemFromfile(LNode &L) {//从文件中读取字符和权值
	fstream fin;
	fin.open("Tree.txt", ios::in);
	if (!fin.is_open()) {//打开文件
		cout << "文件打开失败！" << endl;
		return ERROR;
	}
	int n; char m;
	while (fin >> m&& fin >> n){//依次读取字符、权值
		ListAdd(L, m, n);//入表
	}
	fin.close();
	cout << "读取成功" << endl;
	return OK;
}

