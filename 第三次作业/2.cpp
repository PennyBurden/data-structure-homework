//2．编程实现书P48   ADT Queue 基本操作9个，用链式存储结构实现；
#include <iostream>
using namespace std;
typedef struct LNode
{
	int data;
	struct LNode* next;
}LNode,*QueuePtr;
typedef struct LinkQueue
{
	QueuePtr front;//队列的头部指针
	QueuePtr rear;//队列的尾巴指针
}LinkQueue;
int InitQueue(LinkQueue& Q)//初始化链表指针
{
	Q.front = Q.rear = (LNode*)malloc(sizeof(LNode));//对头指针和尾指针进行开辟空间
	if (Q.front == NULL)
		exit(0);
	Q.front->next = NULL;
	return 1;
}
int DestroyQueue(LinkQueue& Q)//摧毁链表指针
{
	QueuePtr p; //从头结点开始依次向下循环，找寻是否还存在结点，存在就一个个销毁 
	while (Q.front)
	{
		p = Q.front->next; //下一个地址先存着
		free(Q.front);
		Q.front = p;
		return true;
	}
}
int ClearQueue(LinkQueue & Q)
{
	
	Q.rear = Q.front->next;//将尾指针指向头指针下一个
	while (Q.front->next)//不断地遍历链表
	{
		Q.rear = Q.rear->next;//遍历一个节点就删除一个节点
		free(Q.front->next);//将节点内容删除
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

	// 初始化队列
	if (InitQueue(Q)) {
		cout << "成功初始化队列。" << endl;
	}
	else {
		cout << "队列初始化失败。" << endl;
		return 0;
	}

	// 检查队列是否为空
	if (QueueEmpty(Q)) {
		cout << "队列为空。" << endl;
	}
	else {
		cout << "队列非空。" << endl;
	}

	// 元素入队
	for (int i = 1; i <= 5; i++) {
		if (EnQueue(Q, i)) {
			cout << "元素 " << i << " 成功入队。" << endl;
		}
		else {
			cout << "元素 " << i << " 入队失败。" << endl;
		}
	}

	// 遍历队列
	if (!QueueTraverse(Q)) {
		cout << "遍历队列失败。" << endl;
	}

	// 获取队头元素
	if (GetHead(Q) != -1) {
		cout << "队头元素是 " << GetHead(Q) << "。" << endl;
	}
	else {
		cout << "获取队头元素失败。" << endl;
	}

	// 元素出队
	if (DeQueue(Q, e)) {
		cout << "元素 " << e << " 成功出队。" << endl;
	}
	else {
		cout << "元素出队失败。" << endl;
	}

	// 获取队列长度
	cout << "队列的长度是 " << Queuelength(Q) << "。" << endl;

	// 清空队列
	if (ClearQueue(Q)) {
		cout << "成功清空队列。" << endl;
	}
	else {
		cout << "清空队列失败。" << endl;
	}

	// 销毁队列
	if (DestroyQueue(Q)) {
		cout << "成功销毁队列。" << endl;
	}
	else {
		cout << "销毁队列失败。" << endl;
	}

	return 0;
}