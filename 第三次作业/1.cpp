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
int DestroyStack(SeqStack& S)//销毁顺序栈
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
int ClearStack(SeqStack& S)//清空顺序栈
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
		return 0;//空 栈 返 回 0 值
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
		 cout << "栈的元素为: ";
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
		cout << "成功创建链表" << endl;
	}
	else {
		cout << "未能成功创建链表" << endl;
		return 0;
	}

	 
	if (Stackempty(S)) {
		cout << "空栈." << endl;
	}
	else {
		cout << "栈不空." << endl;
	}

	// Push elements into stack
	for (int i = 1; i <= 5; i++) {
		if (Push(S, i)) {
			cout << "Push " << i << "进栈" << endl;
		}
		else {
			cout << "失败push " << i << " 进栈" << endl;
		}
	}
	if (!StackTraverse(S)) 
	{
		cout << "从头重新遍历" << endl;
	} 
	if (GetTop(S, e) != -1) {
		cout << "头部元素是 " << e << "." << endl;
	}
	else {
		cout << "未能成功获取头部元素" << endl;
	}

	 
	if (Pop(S, e)) {
		cout << "Pop " << e << " 从栈中" << endl;
	}
	else {
		cout << "未能从栈中pop元素" << endl;
	}

	 
	cout << "栈的长度为 " << StackLength(S) << "." << endl;

	 
	if (ClearStack(S)) {
		cout << "成功清理栈" << endl;
	}
	else {
		cout << "未能清理栈." << endl;
	}

	// Destroy stack
	if (DestroyStack(S)) {
		cout << "成功摧毁链表" << endl;
	}
	else {
		cout << "失败摧毁链表." << endl;
	}

	return 0;
}
