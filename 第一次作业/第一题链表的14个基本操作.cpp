#include <iostream>
using namespace std;

// ��������ڵ�ṹ
typedef struct LNode
{
    char data;         // �ڵ�����
    LNode* next;      // ָ����һ���ڵ��ָ��
} LNode, * LinkList;

// ����������Ϣ�ṹ
typedef struct SListInfo
{
    LinkList head;    // ����ͷָ��
    LinkList tail;    // ����βָ��
    LNode* pCurNode;  // ��ǰ�ڵ�ָ��
    int length;       // ������
} SListInfo;

// ��ʼ������
int InitList(SListInfo& L)
{
    L.head = (LNode*)malloc(sizeof(LNode)); // ����ͷ�ڵ��ڴ�
    if (L.head == NULL)
        exit(0);

    L.head->next = NULL; // ��ʼ��ͷ�ڵ�
    L.tail = L.head;     // βָ��ָ��ͷ�ڵ�
    L.pCurNode = L.head; // ��ǰ�ڵ�ָ��ָ��ͷ�ڵ�
    L.length = 0;        // ��ʼ��������Ϊ0
    return 1;             // ��ʼ���ɹ�
}

// ��������
int DestroyList(SListInfo& L)
{
    LNode* p;
    while (L.head->next != NULL)
    {
        p = L.head->next;
        L.head->next = p->next;
        free(p);
    }
    free(L.head);   // �ͷ�ͷ�ڵ��ڴ�
    L.head = NULL;
    L.tail = NULL;
    L.pCurNode = NULL;
    L.length = 0;   // ��������
    return 1;        // ���ٳɹ�
}

// �������л�ȡԪ��
int GetElem(SListInfo& L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // λ�� i ���Ϸ�
    }

    LNode* p;
    p = L.head->next;
    int j = 1;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    e = p->data;   // ��ȡԪ��
    L.pCurNode = p; // ���µ�ǰ�ڵ�ָ��
    return 1;        // ��ȡ�ɹ�
}

// ��λԪ���������е�λ��
int LocateElem(SListInfo& L, char e)
{
    int j = 0;
    LNode* p;
    p = L.head->next;
    while (j < L.length)
    {
        if (p->data == e)
        {
            return j; // �ҵ�Ԫ�� e ��λ�� j
        }
        p = p->next;
        j++;
    }
    return 0; // δ�ҵ�Ԫ�� e
}

// ��ȡָ��Ԫ�ص�ǰ��Ԫ��
int PriorElem(SListInfo& L, char cur_e, char& pre_e)
{
    if (L.head->data == cur_e)
    {
        return 0; // ͷ�ڵ�û��ǰ��Ԫ��
    }
    LNode* p;
    p = L.head;
    int j = 0;
    while (j < L.length)
    {
        if (p->data == cur_e)
        {
            break;
        }
        p = p->next;
        j++;
    }
    p = L.head->next;
    for (int i = 0; i < j - 1; i++)
    {
        p = p->next;
    }
    pre_e = p->data; // ��ȡǰ��Ԫ��
}

// ��ȡָ��Ԫ�صĺ��Ԫ��
int NextElem(SListInfo& L, char cur_e, char& pre_e)
{
    if (L.head->data == cur_e)
    {
        return 0; // ͷ�ڵ�û�к��Ԫ��
    }
    LNode* p;
    p = L.head;
    int j = 0;
    while (j < L.length)
    {
        if (p->data == cur_e)
        {
            break;
        }
        p = p->next;
        j++;
    }
    p = L.head;
    for (int i = 0; i < j + 1; i++)
    {
        p = p->next;
    }
    pre_e = p->data; // ��ȡ���Ԫ��
}

// �����������Ԫ��
int ListTraverse(SListInfo& L)
{
    int j = 0;
    LNode* p;
    p = L.head;
    while (j < L.length)
    {
        cout << p->data; // ���Ԫ��
        p = p->next;
        j++;
    }
}

// ����ָ��λ��Ԫ�ص�ֵ
int SetElem(SListInfo& L, int i, char& e)
{
    int j = 0;
    LNode* p;
    char temp;
    p = L.head;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    temp = p->data;
    p->data = e;
    e = temp;
    return 1; // ���óɹ�
}

// ��ָ��λ�ò���Ԫ��
int InsertElem(SListInfo& L, int i, char e)
{
    int j = 0;
    LNode* p;
    LNode* t1 = (LNode*)malloc(sizeof(LNode)); // �����½ڵ��ڴ�
    t1->data = e;   // �����½ڵ�����
    char temp;
    p = L.head;
    while (j < i - 1)
    {
        p = p->next;
        j++;
    }
    p->next = t1; // �����½ڵ�
    t1->next = p->next;
}

// ɾ��ָ��λ�õ�Ԫ��
void DeleteList(SListInfo& L, int i, char& e)
{
    int j = 0;
    LNode* cur;
    cur = L.head;
    while (j < i - 1)
    {
        cur = cur->next;
        j++;
    }
    e = cur->next->data; // ��ȡҪɾ����Ԫ��
    LNode* p = cur->next;
    cur->next = cur->next->next; // ɾ��Ԫ��
    free(p); // �ͷ��ڴ�
}

// ��ȡ����ĳ���
int ListLength(SListInfo& L)
{
    return L.length; // ����������
}

// ��������Ƿ�Ϊ��
bool ListEmpty(SListInfo& L)
{
    if (L.head == NULL)
    {
        return false; // ����Ϊ��
    }
    else
    {
        return true; // ����ǿ�
    }
}

// �������
void ClearList(SListInfo& L)
{
    LNode* cur = L.head;
    LNode* p;
    p = cur;
    while (cur != NULL)
    {
        p = cur->next;
        free(cur); // �ͷŽڵ��ڴ�
        cur = cur->next;
    }
    L.length = 0; // ��������
}
