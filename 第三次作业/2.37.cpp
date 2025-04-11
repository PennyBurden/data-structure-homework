#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// �����½ڵ�
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// ��ӽڵ㵽�����ĩβ
void append(Node** head, int data) {
    if (*head == NULL) {
        *head = newNode(data);
        return;
    }

    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }

    Node* node = newNode(data);
    last->next = node;
    node->prev = last;
}

// ��ӡ����
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void rearrange(Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return;
    }

    Node* oddNode = head;
    Node* evenNode = head->next;
    Node* evenHead = evenNode;

    while (evenNode != NULL && evenNode->next != NULL) {
        oddNode->next = oddNode->next->next;
        oddNode = oddNode->next;

        evenNode->next = evenNode->next->next;
        evenNode = evenNode->next;
    }

    oddNode->next = evenHead;
    if (evenNode != NULL) {
        evenNode->next = NULL;
    }
}

int main() {
    // ��������ʼ������
    Node* head = NULL;
    for (int i = 1; i <= 100; i++) {
        append(&head, i);
    }

    cout << "ԭ�ȵ�����: ";
    printList(head);

    // ���� rearrange(head) ����������������
    rearrange(head);

    cout << "����������: ";
    // ��ӡ��������֤���
    printList(head);

    return 0;
}