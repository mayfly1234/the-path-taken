#pragma once
#include<iostream>
#include<string>
#include"list.h"
#define OK 1
#define ERROR -1
#define MAXSIZE 50
using namespace std;

typedef string Class;
typedef string Vtype;
typedef int Edgetype;

int termnub;//ѧ����
int maxscore;//������
int times=1;//ѭ������


int stack[MAXSIZE];//�ݴ�ڵ��������
int top = 0;

typedef struct topuGraph {
	Vtype V[MAXSIZE];//����
	int score[MAXSIZE];//ѧ��
	Edgetype E[MAXSIZE][MAXSIZE];//��
	int Vertexnum;//������
	int outnub[MAXSIZE];//������
	int innub[MAXSIZE];//�����
}*Graph;

void Graphinit(Graph& G) {
	G = new topuGraph;
}

void GraphCreat(Graph& G, LNode& L,int classnub) {
	G->Vertexnum = classnub;
	LNode P = L->next;
	for (int i = 0; i <G->Vertexnum; i++) {
		G->V[i] = P->C;//��ÿ�����㸳ֵѧ��
		G->outnub[i] = P->subclassnub;
		G->innub[i] = P->preclassnub;
		G->score[i] = P->score;
	    P = P->next;
	}
	for (int i = 0; i < G->Vertexnum; i++) {
		for (int j = 0; j < G->Vertexnum; j++) {
			G->E[i][j] = 0;
		}
	}
	P = L->next;//Pָ�����¹�λ
	for (int i = 0; i < G->Vertexnum; i++) {
		for (int j = 0; j < G->Vertexnum; j++) {
			if (P->subclassnub == 0) {
				break;//��P�ڵ����޺�̣���ֱ����ת��һ��
			}
			else {
				for (int k = 0; k < P->subclassnub; k++) {
					if (G->V[j] == P->subclass[k]) {
						G->E[i][j] = 1;
					}
				}
			}
		}
		P = P->next;
	}
}

void GraphNodeDel(Graph &G,int i) {
	G->innub[i] = -1;
	for (int j = 0; j<= G->Vertexnum; j++) {
		if (G->E[i][j] != 0) {
			G->E[i][j] = 0;
			G->innub[j]--;
		}

	}
}

void GraphOut(Graph &G) {
	int totalscore = 0;
	cout << "��" << times << "ѧ�ڿγ�Ϊ��" << endl;
	for (int i = 0; i < G->Vertexnum; i++) {
		if (G->innub[i] == 0&&totalscore<=maxscore) {
			totalscore += G->score[i];
			cout << G->V[i]<<" ";

			stack[top] = i;
			top++;
		}
     }
	for (int i=0;i<=top;i++) {
		GraphNodeDel(G, stack[i]);
	}
	times++;
	cout << "�ܷ�Ϊ��" << totalscore << endl;
	if (times == termnub + 1) {
		times = 1;
		return;
	}
	GraphOut(G);
}

void Gout(Graph& G) {//���ڲ��ԣ���������ڽӾ���ĵ�
	for (int i = 0; i < G->Vertexnum; i++) {
		for (int j = 0; j < G->Vertexnum; j++) {
			cout << "(" << i << "," << j <<"):" << G->E[i][j]  << endl;
		}
	}
}