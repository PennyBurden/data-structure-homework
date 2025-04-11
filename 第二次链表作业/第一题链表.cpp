#include <iostream>
using namespace std;
typedef struct LNode
{
	int data;
	LNode* next;

}LNode;
int sort(LNode* head)
{
	LNode* cur;
    LNode* p;
	int length = 0;
	int temp;
	
	cur = head;
	p = head;
	while (cur != nullptr)
	{
        p = cur;
		while (p != nullptr)
		{
			if (cur->data >= p->data)
			{
				temp = cur->data;
				cur->data = p->data;
				p -> data = temp;
			}
            p = p->next;
		}
        cur = cur->next;
	}
	return 1;
}
int main()
{
    LNode* head = nullptr; // 头节点指针
    LNode* cur = nullptr;  // 当前节点指针

    // 创建链表并插入元素
    for (int i = 0; i < 5; i++)
    {
        LNode* newNode = new LNode;
        newNode->data = rand() % 100; // 随机生成数据
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode; // 如果头节点为空，将头节点指向新节点
            cur = head; // 当前节点也指向头节点
        }
        else
        {
            cur->next = newNode; // 将新节点连接到当前节点后
            cur = newNode; // 当前节点指针指向新节点
        }
    }

    // 输出原始链表
    cout << "原始链表: ";
    cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    // 调用排序函数对链表进行排序
    sort(head);

    // 输出排序后的链表
    cout << "排序后的链表: ";
    cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    // 释放链表内存
    while (head != nullptr)
    {
        cur = head;
        head = head->next;
        delete cur;
    }

    return 0;
}
