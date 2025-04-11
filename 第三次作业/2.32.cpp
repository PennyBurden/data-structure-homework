#include<iostream>
using namespace std;

// 定义双向链表节点结构体
typedef struct DuLNode
{
	int data;         // 数据域
	DuLNode* pre;     // 前驱指针
	DuLNode* next;    // 后继指针
}*DuLinkList;

// 初始化链表
int InitList(DuLinkList& L, int e)
{
	// 动态申请内存
	L = (DuLinkList)malloc(sizeof(DuLNode));
	if (!L)
	{
		// 内存申请失败，退出程序
		exit(0);
	}
	// 将pre指针设为NULL，next指针指向自己，表示初始化一个空链表
	L->pre = NULL;
	L->next = L;
	return 1;
}

// 向链表中插入元素
int ListInsert_DL(DuLinkList& L, int e)
{
	// 动态申请内存
	DuLinkList p;
	p = (DuLinkList)malloc(sizeof(DuLNode));
	if (!p)
		return 0;  // 内存申请失败，返回0
	p->data = e;  // 设置节点数据域为e
	p->next = L->next;  // 将新节点的next指针指向头节点的下一个节点
	L->next = p;  // 将头节点的next指针指向新节点
	return 1;
}

// 将单向循环链表转换为双向循环链表
int ListCirToDu(DuLinkList& L)
{
	DuLinkList p, q;
	q = L;  // q指针指向头节点
	p = L->next;  // p指针指向头节点的下一个节点
	while (p != L) {
		p->pre = q;  // 设置p节点的pre指针为q
		q = p;  // q向后移动
		p = p->next;  // p向后移动
	}
	if (p == L) p->pre = q;  // 当p回到头节点时，设置头节点的pre指针为链表的最后一个节点
	return 1;
}

int main()
{
	DuLinkList L;
	int n, e;
	cout << "请输入节点数量：";
	cin >> n;

	// 初始化链表
	if (!InitList(L, 0)) {
		cout << "初始化链表失败！" << endl;
		return -1;
	}

	// 向链表中插入元素
	for (int i = 0; i < n; i++) {
		cout << "请输入第 " << i + 1 << " 个元素：";
		cin >> e;
		if (!ListInsert_DL(L, e)) {
			cout << "插入元素失败！" << endl;
			return -1;
		}
	}

	// 将单向循环链表转换为双向循环链表
	ListCirToDu(L);

	// 打印链表中的元素
	DuLinkList p = L->next;
	while (p != L) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;

	return 0;
}