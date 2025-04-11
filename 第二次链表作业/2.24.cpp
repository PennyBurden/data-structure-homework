int ListMergeOppose(LinkList& A, LinkList& B, LinkList& C)
{
	LinkList a1, a2, a3, a4;
	qa = pa;	// 保存pa的前驱指针
	qb = pb;	// 保存pb的前驱指针
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
			qa->next = A->next;	//将当前最小结点插入A表表头
			A->next = qa;
		}
		else {
			qb = pb;
			pb = pb->next;
			qb->next = A->next;	//将当前最小结点插入A表表头
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