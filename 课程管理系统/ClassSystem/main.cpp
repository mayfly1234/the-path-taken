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
		cout << "*************��ӭ�����γ̹���ϵͳ************" << endl;
		cout << "���������ѡ��:" << endl;
		cout << "1������ѧ������ÿѧ���������Ϳγ�����" << endl;
		cout << "2������γ�" << endl;
		cout << "3��ɾ���γ�" << endl;
		cout << "4��Ԫ�ز���" << endl;
		cout << "5���鿴���пγ�" << endl;
		cout << "6������ƻ�����" << endl;
		cout << "7���˳�" << endl;
		cin >> loop;
		switch (loop) {
		case 1:
			cout << "������ѧ������" << endl;
			cin >> termnub;
			cout << "������ÿѧ�����ѧ�֣�" << endl;
			cin >> maxscore;
			cout << "������γ���������" << endl;
			cin >> classnub;
			break;
		case 2:
			ListAdd(L);
			break;
		case 3:
			cout << "������Ҫɾ���Ŀγ�����" << endl;
			cin >> temp;
			ListDel(L, temp);
			break;
		case 4:
			cout << "������Ҫ��ѯ�Ŀγ�����" << endl;
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