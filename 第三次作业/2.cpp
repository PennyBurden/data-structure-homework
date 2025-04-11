//2�����ʵ����P48   ADT Queue ��������9��������ʽ�洢�ṹʵ�֣�
#include <iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;//���е�ͷ��ָ��
	QueuePtr rear;//���е�β��ָ��
}LinkQueue;
int InitQueue(LinkQueue& Q)//��ʼ������ָ��
{
	Q.front = Q.rear = (LNode*)malloc(sizeof(LNode));//��ͷָ���βָ����п��ٿռ�
	if (Q.front == NULL)
		exit(0);
	Q.front->next = NULL;
	return 1;
}
int DestroyQueue(LinkQueue& Q)//�ݻ�����ָ��
{
	QueuePtr p; //��ͷ��㿪ʼ��������ѭ������Ѱ�Ƿ񻹴��ڽ�㣬���ھ�һ�������� 
	while (Q.front)
	{
		p = Q.front->next; //��һ����ַ�ȴ���
		free(Q.front);
		Q.front = p;
		return true;
	}
}
int ClearQueue(LinkQueue & Q)
{
	
	Q.rear = Q.front->next;//��βָ��ָ��ͷָ����һ��
	while (Q.front->next)//���ϵر�������
	{
		Q.rear = Q.rear->next;//����һ���ڵ��ɾ��һ���ڵ�
		free(Q.front->next);//���ڵ�����ɾ��
		Q.front->next = Q.rear;
	}
	Q.rear = Q.front;
	return 1;
}
bool QueueEmpty(LinkQueue& Q)
{
	if (Q.front = Q.rear)
	{
		return 1;
	}
	else
	{
		return  0;
	}
}
int Queuelength(LinkQueue &Q)
{
	int length = 0;
	while (Q.front != Q.rear)
	{
		length++;
		Q.front = Q.front->next;

	}
	return length;
}
int GetHead(LinkQueue& Q)
{
	return Q.front->next->data;
}
int QueueTraverse(LinkQueue Q)
{
	if (Q.front == Q.rear)
	{
		return 0;
	}

	LNode* cur;
	cur = Q.front;
	while (cur != Q.rear)
	{
		cout << cur->data;
		cout << " ";
		cur = cur ->next;
	}
}
int EnQueue(LinkQueue &Q,int e)
{
	LNode* s;
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		exit(0);
	}
	s->data = e;
	Q.rear->next = s;
	Q.rear = s;
	return 1;
}

int DeQueue(LinkQueue& Q, int& e)
{
	LNode* p;
	if (Q.front == Q.rear)
	{
		return 0;
	}
	p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
	{
		Q.rear == Q.front;
	}
	free(p);
	return 1;
}
int main()
{
	LinkQueue Q;
	int e;

	// ��ʼ������
	if (InitQueue(Q)) {
		cout << "�ɹ���ʼ�����С�" << endl;
	}
	else {
		cout << "���г�ʼ��ʧ�ܡ�" << endl;
		return 0;
	}

	// �������Ƿ�Ϊ��
	if (QueueEmpty(Q)) {
		cout << "����Ϊ�ա�" << endl;
	}
	else {
		cout << "���зǿա�" << endl;
	}

	// Ԫ�����
	for (int i = 1; i <= 5; i++) {
		if (EnQueue(Q, i)) {
			cout << "Ԫ�� " << i << " �ɹ���ӡ�" << endl;
		}
		else {
			cout << "Ԫ�� " << i << " ���ʧ�ܡ�" << endl;
		}
	}

	// ��������
	if (!QueueTraverse(Q)) {
		cout << "��������ʧ�ܡ�" << endl;
	}

	// ��ȡ��ͷԪ��
	if (GetHead(Q) != -1) {
		cout << "��ͷԪ���� " << GetHead(Q) << "��" << endl;
	}
	else {
		cout << "��ȡ��ͷԪ��ʧ�ܡ�" << endl;
	}

	// Ԫ�س���
	if (DeQueue(Q, e)) {
		cout << "Ԫ�� " << e << " �ɹ����ӡ�" << endl;
	}
	else {
		cout << "Ԫ�س���ʧ�ܡ�" << endl;
	}

	// ��ȡ���г���
	cout << "���еĳ����� " << Queuelength(Q) << "��" << endl;

	// ��ն���
	if (ClearQueue(Q)) {
		cout << "�ɹ���ն��С�" << endl;
	}
	else {
		cout << "��ն���ʧ�ܡ�" << endl;
	}

	// ���ٶ���
	if (DestroyQueue(Q)) {
		cout << "�ɹ����ٶ��С�" << endl;
	}
	else {
		cout << "���ٶ���ʧ�ܡ�" << endl;
	}

	return 0;
}