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

typedef struct LinkNode//����ṹ��
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
void NodeCpy(LNode& a, LNode& b) {//����strcpy,��b�ڵ�ĳ���next���������Ƹ�a;
    a->id = b->id;
    a->name = b->name;
    a->pri = b->pri;
    a->pub = b->pub;
    a->time = b->time;
    a->wri = b->wri;
}
//////////////////////////////
LNode initLink() {//��ʼ������
    LNode head;
    //head = (Node*)malloc(sizeof(LinkNode));
    head = new Node();//mallocֻ�������ڴ棬�������string��������new()����malloc
    head->next = NULL;
    return head;
}
//////////////////////////////////////////
void MessageIn(LNode& L)//��������
{
    LNode newN = new Node();
    LNode  p = L;
    while (p->next != NULL)//β�巨��������
    {
        p = p->next;
    }p->next = newN;
    newN->next = NULL;
    /////////////��������
    printf("��������ţ�");
    cin >> newN->id;
    printf("������������");
    cin >> (newN->name);
    printf("���������ߣ�");
    cin >> (newN->wri);
    printf("��������浥λ��");
    cin >> (newN->pub);
    printf("���������ʱ�䣺");
    cin >> (newN->time);
    printf("������۸�");
    cin >> (newN->pri);
    /////////////////////

}
/////////////////////////////////////////////////
void MessagePut(LNode& L, LNode&N) {//������һ������һ�ִ��뷽������N�ڵ����L������
    LNode newN = new Node();
    NodeCpy(newN, N);
    LNode  p = L;
    while (p->next != NULL)//β�巨��������
    {
        p = p->next;
    }p->next = newN;
    newN->next = NULL;
}
void Nodeprint(LNode& p) {//�ڵ��ӡ

    cout << "===================" << endl;
    cout << "���:";
    cout << p->id << endl;
    cout << "����:";
    cout << p->name << endl;
    cout << "����:";
    cout << p->wri << endl;
    cout << "���浥λ:";
    cout << p->pub << endl;
    cout << "����ʱ��:";
    cout << p->time << endl;
    cout << "�۸�:";
    cout << p->pri << endl;
}
/////////////////////////
void NodeExchange(LNode& a, LNode& b) {//�����ڵ�Ԫ�ػ���
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
void NodeSortPri(LNode& L) {//�ڵ����򣨸��ݼ۸�Ӵ�С����
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
void NodeSortBN(LNode& L) {//�ڵ����򣨸��������Ӵ�С����
    LNode i = L->next;
    for (; i != NULL; i = i->next) {
        LNode j = L->next;
        for (; j != NULL; j = j->next) {
            if (i->name > j->name) {//���ﱾ������strcmp�ģ����Ƿ��ָ�string�������µ���������֮������ò��ˣ���ֱ�ӱȣ���Ҳ����
                NodeExchange(i, j);
            }
        }
    }
}
void MessageVisit(LNode& L)//�������
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
        }p = p->next;//����������Ľڵ����һ���µ�����

    }
    NodeSortBN(N);
    NodeSortPri(N);//������������
}
/////////////////////////////////////////
int MessageStat(LNode& L, writer w) {//ͳ�������Ŀ
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
int MessageDelet(LNode& L, bookid id) {//ɾ���鼮
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
        cout << "δ��ѯ�����鼮" << endl;
        return ERROR;
        }

}


int main()
{
    LNode L = initLink();
    writer n = "woziji";
    for (int i = 0; i < 10; i++) {//����10����
        MessageIn(L);
    }
    cout << "��������Ϊwoziji���飺"<<endl;
    LNode a=initLink();
    MessageSeach(L, a, n);
    MessageVisit(a);
    cout << "����Ϊ��" << endl;
    MessageStat(L, n);
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
     MessageDelet(L,3);
     MessageVisit(L);
    return 0;
}
