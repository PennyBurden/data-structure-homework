#include <iostream>
using namespace std;

// ��������ڵ�ṹ
struct Node 
{
	int data;       // ����
	Node* next;     // ָ����һ���ڵ��ָ��
	Node(int val) : data(val), next(nullptr) {} // ���캯��
};

// ����һ��ѭ����������n���ڵ�
Node* createCircularLinkedList(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	Node* head = new Node(1);  // ������һ���ڵ㣬������ͷ
	Node* current = head;     // ���ڵ������������ڵ�

	// ����ʣ���n-1���ڵ㣬���������ӵ�������
	for (int i = 2; i <= n; i++) 
	{
		current->next = new Node(i); // �����½ڵ�
		current = current->next;     // �ƶ�����һ���ڵ�
	}

	current->next = head; // ��������β�������γ�ѭ��

	return head; // ��������ͷ
}

// ���Լɪ������
int josephus(int n, int m) 
{
	Node* head = createCircularLinkedList(n); // ����ѭ������
	Node* prev = nullptr; // ���ڸ���ǰһ���ڵ�
	Node* current = head; // ���ڵ���ѭ������

	// ѭ��ֱ��ֻʣһ���ڵ�
	while (n > 1)
	{
		for (int i = 1; i < m; i++)
		{
			prev = current; // �ƶ�ǰһ���ڵ�
			current = current->next; // �ƶ���ǰ�ڵ�
		}

		// ���������Ƴ���ǰ�ڵ�
		prev->next = current->next;
		delete current;
		current = prev->next;
		n--;
	}

	int lastSurvivor = current->data; // ������µ��˵�λ��
	delete current;

	return lastSurvivor;
}

int main() 
{
	int n, m;
	cout << "������������n��";
	cin >> n;
	cout << "������������m��";
	cin >> m;
	int result = josephus(n, m); // ���Լɪ������
	cout << "������µ��˵�λ���ǣ�" << result << endl;

	return 0;
}