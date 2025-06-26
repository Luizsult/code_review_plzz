#include "linked_list.h"
#include <iostream>

void LinkedList::add(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::insertBeforeEverySecond(int M) {
    if (isEmpty() || head->next == nullptr) {
        return;
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr && current->next != nullptr) {
        if (count % 2 == 1) {
            Node* newNode = new Node(M);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        } else {
            current = current->next;
        }
        count++;
    }
}

void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* LinkedList::getLastNode() const {
    if (isEmpty()) {
        return nullptr;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

void LinkedList::clearList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void insertBeforeEverySecond(LinkedList& list, int M) {
    list.insertBeforeEverySecond(M);
}
