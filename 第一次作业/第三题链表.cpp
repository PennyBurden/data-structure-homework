#include <iostream>
using namespace std;

// 定义链表节点结构
struct LNode
{
    int data;         // 节点数据
    struct LNode* next; // 指向下一个节点的指针
};

// 定义单链表信息结构
struct SListInfo
{
    LNode* head;   // 链表头指针
    LNode* tail;   // 链表尾指针
    LNode* cur;    // 当前节点指针
    int length;    // 链表长度
};

// 删除链表中的重复元素
void Delete_the_same(SListInfo& a1)
{
    if (a1.head == nullptr)
    {
        return; // 如果链表为空，直接返回
    }

    LNode* cur = a1.head; // 当前节点指针
    LNode* p1;           // 前一个节点指针

    // 遍历链表
    while (cur->next != nullptr)
    {
        p1 = cur; // p1 指向当前节点

        // 再次遍历链表，查找与当前节点数据相同的节点
        while (p1->next != nullptr)
        {
            if (cur->data == p1->next->data)
            {
                LNode* p2 = p1->next;         // p2 指向重复节点
                p1->next = p1->next->next;    // 跳过重复节点
                delete p2;                    // 释放内存
                a1.length--;                  // 减少链表长度
            }
            else
            {
                cur = cur->next; // 如果不是重复元素，继续遍历
            }
        }

        cur = cur->next; // 移动到下一个节点
    }
}

int main()
{
    // 在主函数中使用 Delete_the_same 函数来删除链表中的重复元素
    SListInfo list;
    // 初始化链表并添加元素
   

    // 调用 Delete_the_same 函数删除重复元素
    Delete_the_same(list);

    // 打印删除重复元素后的链表
    
    return 0;
}
