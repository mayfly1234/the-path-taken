#include"list.h"
#include"BiTree.h"
#include"file.h"
#include<iostream>
#include<string>
using namespace std;
typedef char Elem;//������ĸ
typedef int weight;//Ȩ��

int main() {
	int loop=1;
	int n;
	char Inline[MAXSIZE];
	int linelen=0;
	int Elemmunber=0;
	LNode L;
	Elem E;
	TNode T;
	TreeInit(T);
	ListInit(L);
	weight W;
	while (loop) {
		cout << endl;
		cout << "*************��ӭ��������������ϵͳ************" << endl;
		cout << "���������ѡ��:" << endl;
		cout << "0���˳�" << endl;
		cout << "1�������ַ���Ȩֵ" << endl;
		cout << "2���鿴�����ַ����" << endl;
		cout << "3��ɾ���ַ�" << endl;
		cout << "4�������������" << endl;
		cout << "5���鿴��������" << endl;
		cout << "6������" << endl;
		cout << "7������" << endl;
		cout << "8����ȡ�ļ������������" << endl;
		cout << "9����ȡ�ļ����б���" << endl;
		cout << "10����ȡ�ļ���������"<<endl;
		cin >> loop;
		switch (loop) {
		case 0:
			break;
		case 1:
			cout << "�������ַ���" << endl;
			//E = cin.get();
			cin >> E;
			cout << "������Ȩֵ��" << endl;
			cin >> W;
			ListAdd(L,E,W);
			break;
		case 2:
			ListVisit(L);
			break;
		case 3:
			cout << "������Ҫɾ�����ַ���" << endl;
			cin >> E;
			ListDel(L, E);
			break;
		case 4:
			TreeDataIn(T, L);
			TreeNodeSort(T);
			TreeCreat(T);
			cout << "������������ɹ�!" << endl;
			break;
		case 5:
			HafmEncodeInit(T);
			TreeListOut(T);
			break;
		case 6:
			
			cout << "�������ַ����б���(����*ֹͣ)" << endl;
			linelen = 0;
			while (cin >> Inline[linelen])
			{
				linelen++;
		
				if (Inline[linelen - 1] == '*')break;
			}
			HafmEncode(T, Inline, linelen);
			break;
		case 7:
			cout << "�������ַ���������(����*ֹͣ)" << endl;
			linelen = 0;
			while (cin >> Inline[linelen])
			{
				linelen++;

				if (Inline[linelen - 1] == '*')break;
			}
			HafmDecode(T, Inline, linelen);
			break;
		case 8:
			GetElemFromfile(L);
			cout << "�Ƿ�鿴��ȡ���ַ�" << endl;
			cout << "1����" << endl << "0����" << endl;
			cin >> n;
			if (n) {
				ListVisit(L);
			}
			cout << "�Ƿ񹹽���������" << endl;
			cout << "1����" << endl << "0����" << endl;
			cin >> n;
			if (n) {
				TreeDataIn(T, L);
				TreeNodeSort(T);
				TreeCreat(T);
				cout << "������������ɹ�!" << endl;
			}
			break;
		case 9:
			EncodeFromfile(T);
			break;
		case 10:
			DecodeFromfile(T);
			break;
		default:
			cout << "��Ч����" << endl;
			break;

		}
	}
	return 0;
	
}