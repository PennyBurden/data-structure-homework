int ListDelete_L(LinkList& L, int min, int max)
{
    LinkList p, q, pre = NULL; // ��������ڵ�ָ���ǰ��ָ��
    if (min > max)
        return 0; // �����Сֵ�������ֵ�����ش����־

    p = L; // �� p ָ�������ͷ�ڵ�
    pre = p; // pre ָ�� p����ʼʱ����ָ��ͬһ���ڵ�
    p = p->next; // p ָ����һ���ڵ�

    while (p && p->data < max)
    {
        if (p->data <= min)
        {
            pre = p; // ����ڵ�ֵС�ڵ�����Сֵ��pre ָ��ǰ�ڵ�
            p = p->next; // p ָ����һ���ڵ�
        }
        else
        {
            pre->next = p->next; // ��������ɾ����ǰ�ڵ�
            q = p; // ����ǰ�ڵ㱣���� q ��
            p = p->next; // p ָ����һ���ڵ�
            free(q); // �ͷ� q ָ��Ľڵ���ڴ�
        }
    }

    return 1; // �����ɹ�
}
