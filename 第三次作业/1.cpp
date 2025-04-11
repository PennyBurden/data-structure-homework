#define STACKINITSIZE 256
#define STACKINCREMENT 128
#include <iostream>
using namespace std;
typedef struct SeqStack
{
	int* pBase;
	int* pTop;
	int stacksize;
}SeqStack;
int InitStack(SeqStack& S)
{
	S.pBase = (int*)malloc(STACKINITSIZE * sizeof(int));
	if (S.pBase == NULL)
	{
		exit(0);
	}
	S.pTop = S.pBase;
	S.stacksize = STACKINITSIZE;
	return 1;
}
int DestroyStack(SeqStack& S)//����˳��ջ
{
	if (S.pBase != NULL)
	{
		free(S.pBase);
		S.pBase = NULL;
	}
	S.pTop = NULL;
	S.stacksize = 0;
	return 1;

}
int ClearStack(SeqStack& S)//���˳��ջ
{
	S.pTop = S.pBase;
	return 1;
}
bool Stackempty(SeqStack& S)
{
	if (S.pTop == S.pBase)
	{
		return 1;
	}
	else
		return 0;
}
int StackLength(SeqStack& S)
{
	return S.pTop - S.pBase;
}
int GetTop(SeqStack S, int& e)
{
	if (S.pTop == S.pBase)
	{
		return -1;
	}
	e = *(S.pTop - 1);
	return 1;
}
int Push(SeqStack& S, int e)
{
	if (S.pTop - S.pBase >= S.stacksize)
	{
		S.pBase = (int*)realloc(S.pBase, (S.stacksize + STACKINCREMENT) * sizeof(int));
		if (S.pBase == NULL)
			exit(0);
		S.pTop = S.pBase + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.pTop = e;
	S.pTop++;
	return 1;

}
int Pop(SeqStack& S, int& e)
{
	if (S.pTop == S.pBase)
	{
		return 0;//�� ջ �� �� 0 ֵ
	}
	e = *(S.pTop - 1);
	S.pTop--;
	return 1;
}
int StackTraverse(SeqStack& S)
{
	if (S.pBase == S.pTop) 
	{		 
		return 0;  
	}
	else 
	{
		int* pCur  = S.pBase;  
		 cout << "ջ��Ԫ��Ϊ: ";
		while (pCur != S.pTop) 
		{  
			cout << *pCur  << " ";   
			pCur++;  
		}
		cout << endl;
		return 1;
	}
}
int main()
{
	SeqStack S;
	int e;

	 
	if (InitStack(S)) {
		cout << "�ɹ���������" << endl;
	}
	else {
		cout << "δ�ܳɹ���������" << endl;
		return 0;
	}

	 
	if (Stackempty(S)) {
		cout << "��ջ." << endl;
	}
	else {
		cout << "ջ����." << endl;
	}

	// Push elements into stack
	for (int i = 1; i <= 5; i++) {
		if (Push(S, i)) {
			cout << "Push " << i << "��ջ" << endl;
		}
		else {
			cout << "ʧ��push " << i << " ��ջ" << endl;
		}
	}
	if (!StackTraverse(S)) 
	{
		cout << "��ͷ���±���" << endl;
	} 
	if (GetTop(S, e) != -1) {
		cout << "ͷ��Ԫ���� " << e << "." << endl;
	}
	else {
		cout << "δ�ܳɹ���ȡͷ��Ԫ��" << endl;
	}

	 
	if (Pop(S, e)) {
		cout << "Pop " << e << " ��ջ��" << endl;
	}
	else {
		cout << "δ�ܴ�ջ��popԪ��" << endl;
	}

	 
	cout << "ջ�ĳ���Ϊ " << StackLength(S) << "." << endl;

	 
	if (ClearStack(S)) {
		cout << "�ɹ�����ջ" << endl;
	}
	else {
		cout << "δ������ջ." << endl;
	}

	// Destroy stack
	if (DestroyStack(S)) {
		cout << "�ɹ��ݻ�����" << endl;
	}
	else {
		cout << "ʧ�ܴݻ�����." << endl;
	}

	return 0;
}
