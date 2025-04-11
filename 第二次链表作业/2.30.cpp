#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

// 插入节点到链表的末尾
void insertNodeAtEnd(Node*& head, int value) 
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else 
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 删除A中同时存在于B和C的元素
Node* deleteCommonElements(Node* A, Node* B, Node* C) 
{
    if (A == nullptr) 
    {
        return nullptr; // 如果A为空，直接返回
    }

    int valueA = A->data;
    bool existsInB = false;
    bool existsInC = false;

    // 检查当前元素是否存在于B和C中
    Node* currentB = B;
    while (currentB != nullptr) 
    {
        if (currentB->data == valueA) 
        {
            existsInB = true;
            break;
        }
        currentB = currentB->next;
    }

    Node* currentC = C;
    while (currentC != nullptr) 
    {
        if (currentC->data == valueA) 
        {
            existsInC = true;
            break;
        }
        currentC = currentC->next;
    }

    Node* nextNode = A->next;

    if (!existsInB || !existsInC)
    {
        A->next = deleteCommonElements(nextNode, B, C);
        return A;
    }
    else 
    {
        delete A;
        return deleteCommonElements(nextNode, B, C);
    }
}

// 打印单链表
void printList(Node* head)
{
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node* A = nullptr;
    insertNodeAtEnd(A, 1);
    insertNodeAtEnd(A, 6);
    insertNodeAtEnd(A, 4);
    insertNodeAtEnd(A, 2);
    insertNodeAtEnd(A, 8);
    insertNodeAtEnd(A, 3);

    Node* B = nullptr;
    insertNodeAtEnd(B, 2);
    insertNodeAtEnd(B, 4);
    insertNodeAtEnd(B, 5);
    insertNodeAtEnd(B, 3);
    insertNodeAtEnd(B, 10);
    insertNodeAtEnd(B, 6);

    Node* C = nullptr;
    insertNodeAtEnd(C, 3);
    insertNodeAtEnd(C, 5);
    insertNodeAtEnd(C, 6);

    cout << "链表A: ";
    printList(A);
    cout << "链表B: ";
    printList(B);
    cout << "链表C: ";
    printList(C);

    A = deleteCommonElements(A, B, C);

    cout << "删除后的链表A: ";
    printList(A);

    // 释放A、B和C链表节点的内存
    while (A != nullptr) {
        Node* temp = A;
        A = A->next;
        delete temp;
    }
    while (B != nullptr)
    {
        Node* temp = B;
        B = B->next;
        delete temp;
    }
    while (C != nullptr)
    {
        Node* temp = C;
        C = C->next;
        delete temp;
    }

    return 0;
}
