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

int termnub;//学期数
int maxscore;//最大分数
int times=1;//循环次数


int stack[MAXSIZE];//暂存节点序号数组
int top = 0;

typedef struct topuGraph {
	Vtype V[MAXSIZE];//顶点
	int score[MAXSIZE];//学分
	Edgetype E[MAXSIZE][MAXSIZE];//边
	int Vertexnum;//顶点数
	int outnub[MAXSIZE];//出度数
	int innub[MAXSIZE];//入度数
}*Graph;

void Graphinit(Graph& G) {
	G = new topuGraph;
}

void GraphCreat(Graph& G, LNode& L,int classnub) {
	G->Vertexnum = classnub;
	LNode P = L->next;
	for (int i = 0; i <G->Vertexnum; i++) {
		G->V[i] = P->C;//给每个顶点赋值学科
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
	P = L->next;//P指针重新归位
	for (int i = 0; i < G->Vertexnum; i++) {
		for (int j = 0; j < G->Vertexnum; j++) {
			if (P->subclassnub == 0) {
				break;//若P节点中无后继，则直接跳转下一步
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
	cout << "第" << times << "学期课程为：" << endl;
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
	cout << "总分为：" << totalscore << endl;
	if (times == termnub + 1) {
		times = 1;
		return;
	}
	GraphOut(G);
}

void Gout(Graph& G) {//用于测试，输出所有邻接矩阵的点
	for (int i = 0; i < G->Vertexnum; i++) {
		for (int j = 0; j < G->Vertexnum; j++) {
			cout << "(" << i << "," << j <<"):" << G->E[i][j]  << endl;
		}
	}
}