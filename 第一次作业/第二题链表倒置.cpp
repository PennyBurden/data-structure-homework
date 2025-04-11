#include <iostream>
using namespace std;

// 定义链表节点结构
struct LNode
{
    int data;      // 节点数据
    LNode* next;   // 指向下一个节点的指针
};

// 定义单链表信息结构
struct SListInfo
{
    LNode* head;   // 链表头指针
    LNode* tail;   // 链表尾指针
    int length;    // 链表长度
    LNode* cur;    // 当前节点指针
};

// 反转单链表函数
void Reverse(SListInfo& L)
{
    LNode* pre;   // 用于存储前一个节点
    LNode* cur;   // 当前节点
    LNode* net;   // 下一个节点

    pre = nullptr; // 初始时前一个节点为空
    net = nullptr; // 初始时下一个节点为空
    cur = L.head;  // 从链表头开始

    // 遍历链表
    while (cur != nullptr)
    {
        net = cur->next; // 保存当前节点的下一个节点
        cur->next = pre; // 反转当前节点的指针，使其指向前一个节点

        pre = cur;      // 更新前一个节点为当前节点
        cur = net;      // 更新当前节点为下一个节点
    }

    L.head = pre; // 将链表头指针指向反转后的链表头
    return;
}
