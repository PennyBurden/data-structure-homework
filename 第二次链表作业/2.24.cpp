int ListMergeOppose(LinkList& A, LinkList& B, LinkList& C)
{
	LinkList a1, a2, a3, a4;
	qa = pa;	// ����pa��ǰ��ָ��
	qb = pb;	// ����pb��ǰ��ָ��
	pa = pa->next;
	pb = pb->next;
	A->next = NULL;
	C = A;
	while (pa && pb) 
	{
		if (pa->data < pb->data) 
		{
			qa = pa;
			pa = pa->next;
			qa->next = A->next;	//����ǰ��С������A���ͷ
			A->next = qa;
		}
		else {
			qb = pb;
			pb = pb->next;
			qb->next = A->next;	//����ǰ��С������A���ͷ
			A->next = qb;
		}
	}
	while (pa) 
	{
		qa = pa;
		pa = pa->next;
		qa->next = A->next;
		A->next = qa;
	}
	while (pb) 
	{
		qb = pb;
		pb = pb->next;
		qb->next = A->next;
		A->next = qb;
	}
	pb = B;
	free(pb);
	return OK;
}
}