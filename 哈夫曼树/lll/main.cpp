#include"list.h"
#include"BiTree.h"
#include"file.h"
#include<iostream>
#include<string>
using namespace std;
typedef char Elem;//输入字母
typedef int weight;//权重

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
		cout << "*************欢迎来到哈夫曼编码系统************" << endl;
		cout << "请输入你的选择:" << endl;
		cout << "0、退出" << endl;
		cout << "1、输入字符和权值" << endl;
		cout << "2、查看所有字符情况" << endl;
		cout << "3、删除字符" << endl;
		cout << "4、构造哈夫曼树" << endl;
		cout << "5、查看哈夫曼树" << endl;
		cout << "6、编码" << endl;
		cout << "7、译码" << endl;
		cout << "8、读取文件构造哈夫曼树" << endl;
		cout << "9、读取文件进行编码" << endl;
		cout << "10、读取文件进行译码"<<endl;
		cin >> loop;
		switch (loop) {
		case 0:
			break;
		case 1:
			cout << "请输入字符：" << endl;
			//E = cin.get();
			cin >> E;
			cout << "请输入权值：" << endl;
			cin >> W;
			ListAdd(L,E,W);
			break;
		case 2:
			ListVisit(L);
			break;
		case 3:
			cout << "请输入要删除的字符：" << endl;
			cin >> E;
			ListDel(L, E);
			break;
		case 4:
			TreeDataIn(T, L);
			TreeNodeSort(T);
			TreeCreat(T);
			cout << "构造哈夫曼树成功!" << endl;
			break;
		case 5:
			HafmEncodeInit(T);
			TreeListOut(T);
			break;
		case 6:
			
			cout << "请输入字符进行编码(输入*停止)" << endl;
			linelen = 0;
			while (cin >> Inline[linelen])
			{
				linelen++;
		
				if (Inline[linelen - 1] == '*')break;
			}
			HafmEncode(T, Inline, linelen);
			break;
		case 7:
			cout << "请输入字符进行译码(输入*停止)" << endl;
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
			cout << "是否查看读取的字符" << endl;
			cout << "1、是" << endl << "0、否" << endl;
			cin >> n;
			if (n) {
				ListVisit(L);
			}
			cout << "是否构建哈夫曼树" << endl;
			cout << "1、是" << endl << "0、否" << endl;
			cin >> n;
			if (n) {
				TreeDataIn(T, L);
				TreeNodeSort(T);
				TreeCreat(T);
				cout << "构造哈夫曼树成功!" << endl;
			}
			break;
		case 9:
			EncodeFromfile(T);
			break;
		case 10:
			DecodeFromfile(T);
			break;
		default:
			cout << "无效输入" << endl;
			break;

		}
	}
	return 0;
	
}