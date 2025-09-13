#include<iostream>
#include<string>
#include"list.h"
#include"Graph.h"
using namespace std;



int main() {
	int loop = 1;
	int classnub;
	LNode L;
	Listinit(L);
	Graph G;
	Class temp;
	Graphinit(G);
	while (loop) {
		cout << endl;
		cout << "*************欢迎来到课程管理系统************" << endl;
		cout << "请输入你的选择:" << endl;
		cout << "1、输入学期数、每学期最大分数和课程数量" << endl;
		cout << "2、输入课程" << endl;
		cout << "3、删除课程" << endl;
		cout << "4、元素查找" << endl;
		cout << "5、查看所有课程" << endl;
		cout << "6、输出计划编排" << endl;
		cout << "7、退出" << endl;
		cin >> loop;
		switch (loop) {
		case 1:
			cout << "请输入学期数：" << endl;
			cin >> termnub;
			cout << "请输入每学期最大学分：" << endl;
			cin >> maxscore;
			cout << "请输入课程总数量：" << endl;
			cin >> classnub;
			break;
		case 2:
			ListAdd(L);
			break;
		case 3:
			cout << "请输入要删除的课程名：" << endl;
			cin >> temp;
			ListDel(L, temp);
			break;
		case 4:
			cout << "请输入要查询的课程名：" << endl;
			cin >> temp;
			ListSeach(L, temp);
			break;
		case 5:
			ListVisit(L);
			break;
		case 6:
			GraphCreat(G, L, classnub);
			GraphOut(G);
			//Gout(G);
			break;
		case 7:
			loop = 0;
			break;
		default:loop = 0;
			break;

		}

	}
	return 0;
}