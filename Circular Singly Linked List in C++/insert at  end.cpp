#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at the end
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

// Display the circular list
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

    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    cout << "Circular Singly Linked List:\n";
    display(head);

    return 0;
}
