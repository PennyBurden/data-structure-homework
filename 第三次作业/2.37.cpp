#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// 创建新节点
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// 添加节点到链表的末尾
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

// 打印链表
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
    // 创建并初始化链表
    Node* head = NULL;
    for (int i = 1; i <= 100; i++) {
        append(&head, i);
    }

    cout << "原先的链表: ";
    printList(head);

    // 调用 rearrange(head) 进行链表重新排序
    rearrange(head);

    cout << "重新排序后的: ";
    // 打印链表以验证结果
    printList(head);

    return 0;
}