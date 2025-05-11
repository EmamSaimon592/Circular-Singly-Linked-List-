#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at end
void insertEnd(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (*head == nullptr) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Delete first node
void deleteFirst(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    if (temp->next == *head) {
        delete temp;
        *head = nullptr;
        return;
    }

    Node* last = *head;
    while (last->next != *head)
        last = last->next;

    last->next = temp->next;
    *head = temp->next;
    delete temp;
}

// Delete last node
void deleteLast(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    if (temp->next == *head) {
        delete temp;
        *head = nullptr;
        return;
    }

    Node* prev = nullptr;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    delete temp;
}

// Display list
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

    cout << "Original List:\n";
    display(head);

    deleteLast(&head);
    cout << "\nAfter deleting last node:\n";
    display(head);

    deleteFirst(&head);
    cout << "\nAfter deleting first node:\n";
    display(head);

    return 0;
}
