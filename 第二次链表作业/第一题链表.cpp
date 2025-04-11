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
    LNode* head = nullptr; // ͷ�ڵ�ָ��
    LNode* cur = nullptr;  // ��ǰ�ڵ�ָ��

    // ������������Ԫ��
    for (int i = 0; i < 5; i++)
    {
        LNode* newNode = new LNode;
        newNode->data = rand() % 100; // �����������
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode; // ���ͷ�ڵ�Ϊ�գ���ͷ�ڵ�ָ���½ڵ�
            cur = head; // ��ǰ�ڵ�Ҳָ��ͷ�ڵ�
        }
        else
        {
            cur->next = newNode; // ���½ڵ����ӵ���ǰ�ڵ��
            cur = newNode; // ��ǰ�ڵ�ָ��ָ���½ڵ�
        }
    }

    // ���ԭʼ����
    cout << "ԭʼ����: ";
    cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    // �����������������������
    sort(head);

    // �������������
    cout << "����������: ";
    cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;

    // �ͷ������ڴ�
    while (head != nullptr)
    {
        cur = head;
        head = head->next;
        delete cur;
    }

    return 0;
}
