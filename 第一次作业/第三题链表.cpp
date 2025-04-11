#include <iostream>
using namespace std;

// ��������ڵ�ṹ
struct LNode
{
    int data;         // �ڵ�����
    struct LNode* next; // ָ����һ���ڵ��ָ��
};

// ���嵥������Ϣ�ṹ
struct SListInfo
{
    LNode* head;   // ����ͷָ��
    LNode* tail;   // ����βָ��
    LNode* cur;    // ��ǰ�ڵ�ָ��
    int length;    // ������
};

// ɾ�������е��ظ�Ԫ��
void Delete_the_same(SListInfo& a1)
{
    if (a1.head == nullptr)
    {
        return; // �������Ϊ�գ�ֱ�ӷ���
    }

    LNode* cur = a1.head; // ��ǰ�ڵ�ָ��
    LNode* p1;           // ǰһ���ڵ�ָ��

    // ��������
    while (cur->next != nullptr)
    {
        p1 = cur; // p1 ָ��ǰ�ڵ�

        // �ٴα������������뵱ǰ�ڵ�������ͬ�Ľڵ�
        while (p1->next != nullptr)
        {
            if (cur->data == p1->next->data)
            {
                LNode* p2 = p1->next;         // p2 ָ���ظ��ڵ�
                p1->next = p1->next->next;    // �����ظ��ڵ�
                delete p2;                    // �ͷ��ڴ�
                a1.length--;                  // ����������
            }
            else
            {
                cur = cur->next; // ��������ظ�Ԫ�أ���������
            }
        }

        cur = cur->next; // �ƶ�����һ���ڵ�
    }
}

int main()
{
    // ����������ʹ�� Delete_the_same ������ɾ�������е��ظ�Ԫ��
    SListInfo list;
    // ��ʼ���������Ԫ��
   

    // ���� Delete_the_same ����ɾ���ظ�Ԫ��
    Delete_the_same(list);

    // ��ӡɾ���ظ�Ԫ�غ������
    
    return 0;
}
