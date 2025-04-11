#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node* next;
};

// ����ڵ㵽�����ĩβ
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

// ɾ��A��ͬʱ������B��C��Ԫ��
Node* deleteCommonElements(Node* A, Node* B, Node* C) 
{
    if (A == nullptr) 
    {
        return nullptr; // ���AΪ�գ�ֱ�ӷ���
    }

    int valueA = A->data;
    bool existsInB = false;
    bool existsInC = false;

    // ��鵱ǰԪ���Ƿ������B��C��
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

// ��ӡ������
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

    cout << "����A: ";
    printList(A);
    cout << "����B: ";
    printList(B);
    cout << "����C: ";
    printList(C);

    A = deleteCommonElements(A, B, C);

    cout << "ɾ���������A: ";
    printList(A);

    // �ͷ�A��B��C����ڵ���ڴ�
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
