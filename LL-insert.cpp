#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createLinkedList(int A[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = A[i];
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void insertFront(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertAtPos(Node*& head, int pos, int x) {
    if (pos < 0) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;

    if (pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int count = 0;

    while (current != nullptr && count < pos - 1) {
        current = current->next;
        count++;
    }

    if (current == nullptr) {
        cout << "Out of bounds" << endl;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int A[] = {10, 20, 30, 40, 50};
    int position, element;

    Node* head = createLinkedList(A, 5);

    cout << "Original linked list is: ";
    display(head);

    cout << "Enter the element to insert: ";
    cin >> element;

    cout << "Enter the position (0-based index) to insert at: ";
    cin >> position;

    insertAtPos(head, position, element);

    cout << "Updated LinkedList: " << endl;
    display(head);

    insertFront(head, element);

    cout << "Updated LinkedList (after inserting at front): " << endl;
    display(head);

    return 0;
}
