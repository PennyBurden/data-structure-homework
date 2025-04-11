#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
};
Node* createNode(int val, Node* nextNode = nullptr)
{
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nextNode;
    return newNode;
}

Node* merge_ordered_lists(Node* A, Node* B) 
{
    Node* C = nullptr;
    Node* tail = nullptr;

    while (A && B) 
    {
        if (A->data > B->data) 
        {
            if (!C) 
            {
                C = tail = createNode(B->data);
            }
            else 
            {
                tail->next = createNode(B->data);
                tail = tail->next;
            }
            B = B->next;
        }
        else if (A->data < B->data) 
        {
            if (!C) 
            {
                C = tail = createNode(A->data);
            }
            else 
            {
                tail->next = createNode(A->data);
                tail = tail->next;
            }
            A = A->next;
        }
        else 
        {
            if (!C) 
            {
                C = tail = createNode(A->data);
            }
            else 
            {
                tail->next = createNode(A->data);
                tail = tail->next;
            }
            A = A->next;
            B = B->next;
        }
    }

    while (A) 
    {
        if (!C) 
        {
            C = tail = createNode(A->data);
        }
        else 
        {
            tail->next = createNode(A->data);
            tail = tail->next;
        }
        A = A->next;
    }

    while (B) 
    {
        if (!C) 
        {
            C = tail = createNode(B->data);
        }
        else 
        {
            tail->next = createNode(B->data);
            tail = tail->next;
        }
        B = B->next;
    }

    return C;
}

void print_list(Node* head) 
{
    while (head) 
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() 
{
    Node* A = createNode(10);
    A->next = createNode(7);
    A->next->next = createNode(5);
    A->next->next->next = createNode(3);

    Node* B = createNode(9);
    B->next = createNode(6);
    B->next->next = createNode(4);
    B->next->next->next = createNode(2);

    Node* C = merge_ordered_lists(A, B);

    cout << "Merged List C: ";
    print_list(C);

    return 0;
}
