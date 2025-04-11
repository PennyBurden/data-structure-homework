#include<iostream>
using namespace std;

// ����˫������ڵ�ṹ��
typedef struct DuLNode
{
	int data;         // ������
	DuLNode* pre;     // ǰ��ָ��
	DuLNode* next;    // ���ָ��
}*DuLinkList;

// ��ʼ������
int InitList(DuLinkList& L, int e)
{
	// ��̬�����ڴ�
	L = (DuLinkList)malloc(sizeof(DuLNode));
	if (!L)
	{
		// �ڴ�����ʧ�ܣ��˳�����
		exit(0);
	}
	// ��preָ����ΪNULL��nextָ��ָ���Լ�����ʾ��ʼ��һ��������
	L->pre = NULL;
	L->next = L;
	return 1;
}

// �������в���Ԫ��
int ListInsert_DL(DuLinkList& L, int e)
{
	// ��̬�����ڴ�
	DuLinkList p;
	p = (DuLinkList)malloc(sizeof(DuLNode));
	if (!p)
		return 0;  // �ڴ�����ʧ�ܣ�����0
	p->data = e;  // ���ýڵ�������Ϊe
	p->next = L->next;  // ���½ڵ��nextָ��ָ��ͷ�ڵ����һ���ڵ�
	L->next = p;  // ��ͷ�ڵ��nextָ��ָ���½ڵ�
	return 1;
}

// ������ѭ������ת��Ϊ˫��ѭ������
int ListCirToDu(DuLinkList& L)
{
	DuLinkList p, q;
	q = L;  // qָ��ָ��ͷ�ڵ�
	p = L->next;  // pָ��ָ��ͷ�ڵ����һ���ڵ�
	while (p != L) {
		p->pre = q;  // ����p�ڵ��preָ��Ϊq
		q = p;  // q����ƶ�
		p = p->next;  // p����ƶ�
	}
	if (p == L) p->pre = q;  // ��p�ص�ͷ�ڵ�ʱ������ͷ�ڵ��preָ��Ϊ��������һ���ڵ�
	return 1;
}

int main()
{
	DuLinkList L;
	int n, e;
	cout << "������ڵ�������";
	cin >> n;

	// ��ʼ������
	if (!InitList(L, 0)) {
		cout << "��ʼ������ʧ�ܣ�" << endl;
		return -1;
	}

	// �������в���Ԫ��
	for (int i = 0; i < n; i++) {
		cout << "������� " << i + 1 << " ��Ԫ�أ�";
		cin >> e;
		if (!ListInsert_DL(L, e)) {
			cout << "����Ԫ��ʧ�ܣ�" << endl;
			return -1;
		}
	}

	// ������ѭ������ת��Ϊ˫��ѭ������
	ListCirToDu(L);

	// ��ӡ�����е�Ԫ��
	DuLinkList p = L->next;
	while (p != L) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}