#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at the end of the list
void insertEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (*head == nullptr) {
        newNode->next = newNode; // First node points to itself
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
}

// Insert at the beginning of the list
void insertBeginning(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (*head == nullptr) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = *head;
    *head = newNode;
}

// Insert after a given node
void insertAfter(Node* prevNode, int value) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be NULL\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Display the list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(head)\n";
}

int main() {
    Node* head = nullptr;

    // Test insertions
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertBeginning(&head, 5);
    insertAfter(head->next, 15); // Insert 15 after 10

    cout << "Circular Singly Linked List:\n";
    display(head);

    return 0;
}
