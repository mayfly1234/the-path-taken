#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include"list.h"
#include"BiTree.h"
#define ERROR -1

int EncodeFromfile(TNode &T) {
	fstream fin;
	fin.open("Encode.txt", ios::in);;//���ļ�
	if (!fin.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;//�ж��Ƿ��
		return ERROR;
	}
	char Inline[MAXSIZE];
	int top = 0;
	while (fin>>Inline[top])//���ļ��ж�ȡ�ַ���Ȩ��
	{
		top++;
	}
	HafmEncode(T, Inline, top);//���б���
	fin.close();

	return OK;
} 

int DecodeFromfile(TNode& T) {
	fstream fin;
	fin.open("Decode.txt", ios::in );
	if (!fin.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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

int GetElemFromfile(LNode &L) {//���ļ��ж�ȡ�ַ���Ȩֵ
	fstream fin;
	fin.open("Tree.txt", ios::in);
	if (!fin.is_open()) {//���ļ�
		cout << "�ļ���ʧ�ܣ�" << endl;
		return ERROR;
	}
	int n; char m;
	while (fin >> m&& fin >> n){//���ζ�ȡ�ַ���Ȩֵ
		ListAdd(L, m, n);//���
	}
	fin.close();
	cout << "��ȡ�ɹ�" << endl;
	return OK;
}

