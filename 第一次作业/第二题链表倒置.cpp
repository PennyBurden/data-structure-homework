#include <iostream>
using namespace std;

// ��������ڵ�ṹ
struct LNode
{
    int data;      // �ڵ�����
    LNode* next;   // ָ����һ���ڵ��ָ��
};

// ���嵥������Ϣ�ṹ
struct SListInfo
{
    LNode* head;   // ����ͷָ��
    LNode* tail;   // ����βָ��
    int length;    // ������
    LNode* cur;    // ��ǰ�ڵ�ָ��
};

// ��ת��������
void Reverse(SListInfo& L)
{
    LNode* pre;   // ���ڴ洢ǰһ���ڵ�
    LNode* cur;   // ��ǰ�ڵ�
    LNode* net;   // ��һ���ڵ�

    pre = nullptr; // ��ʼʱǰһ���ڵ�Ϊ��
    net = nullptr; // ��ʼʱ��һ���ڵ�Ϊ��
    cur = L.head;  // ������ͷ��ʼ

    // ��������
    while (cur != nullptr)
    {
        net = cur->next; // ���浱ǰ�ڵ����һ���ڵ�
        cur->next = pre; // ��ת��ǰ�ڵ��ָ�룬ʹ��ָ��ǰһ���ڵ�

        pre = cur;      // ����ǰһ���ڵ�Ϊ��ǰ�ڵ�
        cur = net;      // ���µ�ǰ�ڵ�Ϊ��һ���ڵ�
    }

    L.head = pre; // ������ͷָ��ָ��ת�������ͷ
    return;
}
