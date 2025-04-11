#include <iostream>
using namespace std;

// 定义链表节点结构
typedef struct LNode
{
    char data;         // 节点数据
    LNode* next;      // 指向下一个节点的指针
} LNode, * LinkList;

// 定义链表信息结构
typedef struct SListInfo
{
    LinkList head;    // 链表头指针
    LinkList tail;    // 链表尾指针
    LNode* pCurNode;  // 当前节点指针
    int length;       // 链表长度
} SListInfo;

// 初始化链表
int InitList(SListInfo& L)
{
    L.head = (LNode*)malloc(sizeof(LNode)); // 分配头节点内存
    if (L.head == NULL)
        exit(0);

    L.head->next = NULL; // 初始化头节点
    L.tail = L.head;     // 尾指针指向头节点
    L.pCurNode = L.head; // 当前节点指针指向头节点
    L.length = 0;        // 初始化链表长度为0
    return 1;             // 初始化成功
}

// 销毁链表
int DestroyList(SListInfo& L)
{
    LNode* p;
    while (L.head->next != NULL)
    {
        p = L.head->next;
        L.head->next = p->next;
        free(p);
    }
    free(L.head);   // 释放头节点内存
    L.head = NULL;
    L.tail = NULL;
    L.pCurNode = NULL;
    L.length = 0;   // 重置链表
    return 1;        // 销毁成功
}

// 从链表中获取元素
int GetElem(SListInfo& L, int i, char& e)
{
    if (i < 1 || i > L.length)
    {
        return 0; // 位置 i 不合法
    }

    LNode* p;
    p = L.head->next;
    int j = 1;
    while (j < i)
    {
        p = p->next;
        j++;
    }
    e = p->data;   // 获取元素
    L.pCurNode = p; // 更新当前节点指针
    return 1;        // 获取成功
}

// 定位元素在链表中的位置
int LocateElem(SListInfo& L, char e)
{
    int j = 0;
    LNode* p;
    p = L.head->next;
    while (j < L.length)
    {
        if (p->data == e)
        {
            return j; // 找到元素 e 在位置 j
        }
        p = p->next;
        j++;
    }
    return 0; // 未找到元素 e
}

// 获取指定元素的前驱元素
int PriorElem(SListInfo& L, char cur_e, char& pre_e)
{
    if (L.head->data == cur_e)
    {
        return 0; // 头节点没有前驱元素
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
    pre_e = p->data; // 获取前驱元素
}

// 获取指定元素的后继元素
int NextElem(SListInfo& L, char cur_e, char& pre_e)
{
    if (L.head->data == cur_e)
    {
        return 0; // 头节点没有后继元素
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
    pre_e = p->data; // 获取后继元素
}

// 遍历链表并输出元素
int ListTraverse(SListInfo& L)
{
    int j = 0;
    LNode* p;
    p = L.head;
    while (j < L.length)
    {
        cout << p->data; // 输出元素
        p = p->next;
        j++;
    }
}

// 设置指定位置元素的值
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
    return 1; // 设置成功
}

// 在指定位置插入元素
int InsertElem(SListInfo& L, int i, char e)
{
    int j = 0;
    LNode* p;
    LNode* t1 = (LNode*)malloc(sizeof(LNode)); // 分配新节点内存
    t1->data = e;   // 设置新节点数据
    char temp;
    p = L.head;
    while (j < i - 1)
    {
        p = p->next;
        j++;
    }
    p->next = t1; // 插入新节点
    t1->next = p->next;
}

// 删除指定位置的元素
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
    e = cur->next->data; // 获取要删除的元素
    LNode* p = cur->next;
    cur->next = cur->next->next; // 删除元素
    free(p); // 释放内存
}

// 获取链表的长度
int ListLength(SListInfo& L)
{
    return L.length; // 返回链表长度
}

// 检查链表是否为空
bool ListEmpty(SListInfo& L)
{
    if (L.head == NULL)
    {
        return false; // 链表为空
    }
    else
    {
        return true; // 链表非空
    }
}

// 清空链表
void ClearList(SListInfo& L)
{
    LNode* cur = L.head;
    LNode* p;
    p = cur;
    while (cur != NULL)
    {
        p = cur->next;
        free(cur); // 释放节点内存
        cur = cur->next;
    }
    L.length = 0; // 重置链表
}
