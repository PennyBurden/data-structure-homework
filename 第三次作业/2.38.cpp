#include<iostream>
using namespace std;
// ��������ṹ�壬����������ǰ��������Լ�Ƶ����
struct Node {
    int data;
    int freq;
    Node* next;
    Node* prev;
};
// �����µĽڵ�
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->freq = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
// ��˫��ѭ����������ӽڵ�
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
// ����Locate����
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
        return head;  // ����������Ҳ���x��ֱ�ӷ���ͷ�ڵ�
    }
    // �ҵ�Ŀ��ڵ㣬������Ƶ�ȵ�����λ��
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
// ��ӡ����
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
    // ��������ʼ������
    Node* head = NULL;
    for (int i = 1; i <= 50; i++) {
        append(&head, i);
    }

    cout << "ԭʼ����: ";
    printList(head);

    // ����Locate����
    cout << "������Ҫlocate��������" << endl;
    int n;
    cin >> n;
    int a[1000];
    cout << "������Ҫlocate������" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        head = Locate(head, i);
    }
   
    

    cout << "�����������: ";
    printList(head);

    return 0;
}