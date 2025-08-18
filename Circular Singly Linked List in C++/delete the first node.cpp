#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node** head, int value) {
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
}

void deleteFirst(Node** head) {
    if (*head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = *head;

    if (temp->next == *head) {
        delete temp;
        *head = nullptr;
        return;
    }

    Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    last->next = (*head)->next;
    *head = (*head)->next;

    delete temp;
}

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

    cout << "Original List:\n";
    display(head);

    cout << "\nAfter deleting first node:\n";
    deleteFirst(&head);
    display(head);

    return 0;
}

// Original List:
// 10 -> 20 -> 30 -> (head)

// After deleting first node:
// 20 -> 30 -> (head)


