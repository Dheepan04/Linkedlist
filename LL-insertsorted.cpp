#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SortedLinkedList {
public:
    Node* head;

    SortedLinkedList() : head(nullptr) {}

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void sortedInsert(int x) {
        Node* newnode = new Node(x);
        if (head == nullptr || x < head->data) {
            newnode->next = head;
            head = newnode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data < x) {
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
};

int main() {
    SortedLinkedList list;

    int A[] = {1, 3, 5, 7, 8};
    for (int i = 0; i < 5; i++) {
        list.sortedInsert(A[i]);
    }

    cout << "Original Linked List: ";
    list.display();

    int elementToInsert;
    cout << "Enter the element to insert in the sorted list: ";
    cin >> elementToInsert;
    list.sortedInsert(elementToInsert);

    cout << "Updated Sorted Linked List: ";
    list.display();

    return 0;
}