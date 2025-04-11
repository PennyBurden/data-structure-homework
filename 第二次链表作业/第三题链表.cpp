#include <iostream>
using namespace std;

// 定义链表节点结构
struct Node 
{
	int data;       // 数据
	Node* next;     // 指向下一个节点的指针
	Node(int val) : data(val), next(nullptr) {} // 构造函数
};

// 创建一个循环链表，包括n个节点
Node* createCircularLinkedList(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	Node* head = new Node(1);  // 创建第一个节点，即链表头
	Node* current = head;     // 用于迭代创建其他节点

	// 创建剩余的n-1个节点，将它们连接到链表中
	for (int i = 2; i <= n; i++) 
	{
		current->next = new Node(i); // 创建新节点
		current = current->next;     // 移动到下一个节点
	}

	current->next = head; // 将链表首尾相连，形成循环

	return head; // 返回链表头
}

// 解决约瑟夫问题
int josephus(int n, int m) 
{
	Node* head = createCircularLinkedList(n); // 创建循环链表
	Node* prev = nullptr; // 用于跟踪前一个节点
	Node* current = head; // 用于迭代循环链表

	// 循环直到只剩一个节点
	while (n > 1)
	{
		for (int i = 1; i < m; i++)
		{
			prev = current; // 移动前一个节点
			current = current->next; // 移动当前节点
		}

		// 从链表中移除当前节点
		prev->next = current->next;
		delete current;
		current = prev->next;
		n--;
	}

	int lastSurvivor = current->data; // 最后留下的人的位置
	delete current;

	return lastSurvivor;
}

int main() 
{
	int n, m;
	cout << "请输入正整数n：";
	cin >> n;
	cout << "请输入正整数m：";
	cin >> m;
	int result = josephus(n, m); // 解决约瑟夫问题
	cout << "最后留下的人的位置是：" << result << endl;

	return 0;
}