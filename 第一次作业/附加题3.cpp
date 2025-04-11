int ListDelete_L(LinkList& L, int min, int max)
{
    LinkList p, q, pre = NULL; // 定义链表节点指针和前驱指针
    if (min > max)
        return 0; // 如果最小值大于最大值，返回错误标志

    p = L; // 将 p 指向链表的头节点
    pre = p; // pre 指向 p，初始时它们指向同一个节点
    p = p->next; // p 指向下一个节点

    while (p && p->data < max)
    {
        if (p->data <= min)
        {
            pre = p; // 如果节点值小于等于最小值，pre 指向当前节点
            p = p->next; // p 指向下一个节点
        }
        else
        {
            pre->next = p->next; // 从链表中删除当前节点
            q = p; // 将当前节点保存在 q 中
            p = p->next; // p 指向下一个节点
            free(q); // 释放 q 指向的节点的内存
        }
    }

    return 1; // 操作成功
}
