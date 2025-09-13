#include <iostream>
#include<string>
#include <stdio.h>
#include<stdlib.h>
#define  OK 1
#define ERROR -1
using namespace std;
typedef string bookname;
typedef int bookid;
typedef string writer;
typedef string pubilsher;
typedef string pubilshtime;
typedef int price;

typedef struct LinkNode//定义结构体
{
    bookid id;
    bookname name;
    writer wri;
    pubilsher pub;
    pubilshtime time;
    price pri;
    struct LinkNode* next;
}Node,*LNode;
////////////////////////////////////
void NodeCpy(LNode& a, LNode& b) {//类似strcpy,将b节点的除了next其他都复制给a;
    a->id = b->id;
    a->name = b->name;
    a->pri = b->pri;
    a->pub = b->pub;
    a->time = b->time;
    a->wri = b->wri;
}
//////////////////////////////
LNode initLink() {//初始化链表
    LNode head;
    //head = (Node*)malloc(sizeof(LinkNode));
    head = new Node();//malloc只会申请内存，不会调用string，所以用new()代替malloc
    head->next = NULL;
    return head;
}
//////////////////////////////////////////
void MessageIn(LNode& L)//数据输入
{
    LNode newN = new Node();
    LNode  p = L;
    while (p->next != NULL)//尾插法输入数据
    {
        p = p->next;
    }p->next = newN;
    newN->next = NULL;
    /////////////数据输入
    printf("请输入书号：");
    cin >> newN->id;
    printf("请输入书名：");
    cin >> (newN->name);
    printf("请输入作者：");
    cin >> (newN->wri);
    printf("请输入出版单位：");
    cin >> (newN->pub);
    printf("请输入出版时间：");
    cin >> (newN->time);
    printf("请输入价格：");
    cin >> (newN->pri);
    /////////////////////

}
/////////////////////////////////////////////////
void MessagePut(LNode& L, LNode&N) {//和输入一样，另一种存入方法；将N节点存入L链表中
    LNode newN = new Node();
    NodeCpy(newN, N);
    LNode  p = L;
    while (p->next != NULL)//尾插法存入数据
    {
        p = p->next;
    }p->next = newN;
    newN->next = NULL;
}
void Nodeprint(LNode& p) {//节点打印

    cout << "===================" << endl;
    cout << "书号:";
    cout << p->id << endl;
    cout << "书名:";
    cout << p->name << endl;
    cout << "作者:";
    cout << p->wri << endl;
    cout << "出版单位:";
    cout << p->pub << endl;
    cout << "出版时间:";
    cout << p->time << endl;
    cout << "价格:";
    cout << p->pri << endl;
}
/////////////////////////
void NodeExchange(LNode& a, LNode& b) {//两个节点元素互换
    LNode temp = new Node;;
    temp->id = a->id;
    temp->name = a->name;
    temp->pri = a->pri;
    temp->pub = a->pub;
    temp->time = a->time;
    temp->wri = a->wri;
    a->id = b->id;
    a->name = b->name;
    a->pri = b->pri;
    a->pub = b->pub;
    a->time = b->time;
    a->wri = b->wri;
    b->id = temp->id;
    b->name = temp->name;
    b->pri = temp->pri;
    b->pub = temp->pub;
    b->time = temp->time;
    b->wri = temp->wri;
    free(temp);
}
void NodeSortPri(LNode& L) {//节点排序（根据价格从大到小排序）
    LNode i = L->next;
    for (; i != NULL; i = i->next) {
        LNode j = L->next;
        for (; j != NULL; j = j->next) {
            if (i->pri > j->pri) {
                NodeExchange(i, j);
            }
        }
    }
}
void NodeSortBN(LNode& L) {//节点排序（根据书名从大到小排序）
    LNode i = L->next;
    for (; i != NULL; i = i->next) {
        LNode j = L->next;
        for (; j != NULL; j = j->next) {
            if (i->name > j->name) {//这里本来想用strcmp的，但是发现给string定义了新的数据类型之后好像用不了，能直接比，倒也容易
                NodeExchange(i, j);
            }
        }
    }
}
void MessageVisit(LNode& L)//数据输出
{
    LNode p =L->next;
    while (p!=NULL) {
        Nodeprint(p);
        p = p->next;
    }
}
///////////////////////////////////////
void MessageSeach(LNode &L,LNode &N,writer w) {
    LNode p = L->next;

    while (p!= NULL)
    {
        if (p->wri == w) {
            MessagePut(N, p);
            //Nodeprint(p);
        }p = p->next;//将所有满足的节点组成一个新的链表

    }
    NodeSortBN(N);
    NodeSortPri(N);//给新链表排序
}
/////////////////////////////////////////
int MessageStat(LNode& L, writer w) {//统计书的数目
    LNode p = L->next;
    int n=0;
    while (p!=NULL)
    {
        if (p->wri == w) {
            ++n;
        }p = p->next;

    }
    cout << n<<endl ;
    return 1;
}
//////////////////////////////////////////////////////
int MessageDelet(LNode& L, bookid id) {//删除书籍
    LNode p = L;
    LNode q = p->next;
    while (q!=NULL)
    {
        if (q->id == id) {
            p->next = q->next;
            free(q);
            return OK;
        }
        q = q->next;
        p = p->next;
    }
     if (p->next == NULL) {
        cout << "未查询到该书籍" << endl;
        return ERROR;
        }

}


int main()
{
    LNode L = initLink();
    writer n = "woziji";
    for (int i = 0; i < 10; i++) {//输入10本书
        MessageIn(L);
    }
    cout << "所有作者为woziji的书："<<endl;
    LNode a=initLink();
    MessageSeach(L, a, n);
    MessageVisit(a);
    cout << "数量为：" << endl;
    MessageStat(L, n);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
     MessageDelet(L,3);
     MessageVisit(L);
    return 0;
}
