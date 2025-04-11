#include<iostream>
using namespace std;
// 定义链表结构体，包含数据域、前驱、后继以及频度域
struct Node {
    int data;
    int freq;
    Node* next;
    Node* prev;
};
// 创建新的节点
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->freq = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
// 向双向循环链表中添加节点
void append(Node** head, int data) 
{
    Node* node = newNode(data);
    if (*head == NULL) 
    {
        *head = node;
        node->next = node;
        node->prev = node;
    }
    else 
    {
        Node* last = (*head)->prev;
        last->next = node;
        node->prev = last;
        node->next = *head;
        (*head)->prev = node;
    }
}
// 定义Locate函数
Node* Locate(Node* head, int x) {
    Node* node = head;
    Node* target = NULL;
    do {
        if (node->data == x) {
            node->freq += 1;
            target = node;
            break;
        }
        node = node->next;
    } while (node != head);

    if (target == NULL) {
        return head;  // 如果链表中找不到x，直接返回头节点
    }
    // 找到目标节点，根据其频度调整其位置
    while (target != head && target->prev->freq < target->freq) {
        Node* prev = target->prev;
        Node* next = target->next;

        prev->next = next;
        next->prev = prev;

        target->prev = prev->prev;
        target->next = prev;

        prev->prev->next = target;
        prev->prev = target;

        if (head == prev) {
            head = target;
        }
    }
    return head;
}
// 打印链表
void printList(Node* head) {
    Node* node = head;
    do {
        cout << node->data << "(" << node->freq << ") ";
        node = node->next;
    } while (node != head);
    cout << endl;
}
int main()
{
    // 创建并初始化链表
    Node* head = NULL;
    for (int i = 1; i <= 50; i++) {
        append(&head, i);
    }

    cout << "原始链表: ";
    printList(head);

    // 调用Locate操作
    cout << "输入你要locate几个数字" << endl;
    int n;
    cin >> n;
    int a[1000];
    cout << "输入你要locate的数字" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        head = Locate(head, i);
    }
   
    

    cout << "调整后的链表: ";
    printList(head);

    return 0;
}