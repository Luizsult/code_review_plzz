#include "linked_list.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr) {}

LinkedList::LinkedList() : head_(nullptr) {}

LinkedList::~LinkedList() {
    Clear();
}

void LinkedList::Add(int value) {
    Node* new_node = new Node(value);
    
    if (head_ == nullptr) {
        head_ = new_node;
    } else {
        Node* current = head_;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void LinkedList::Remove(int value) {
    if (head_ == nullptr) {
        return;
    }
    
    if (head_->data == value) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        return;
    }
    
    Node* current = head_;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }
    
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void LinkedList::Print() const {
    Node* current = head_;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void LinkedList::Clear() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}

Node* LinkedList::GetLastNode() const {
    if (head_ == nullptr) {
        return nullptr;
    }
    
    Node* current = head_;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

bool LinkedList::IsEmpty() const {
    return head_ == nullptr;
}

void LinkedList::InsertBeforeEverySecond(int M) {
    if (head_ == nullptr || head_->next == nullptr) {
        return;  // Список пуст или содержит один элемент
    }
    
    Node* current = head_;
    int count = 1;
    
    while (current != nullptr && current->next != nullptr) {
        if (count % 2 == 1) {
            Node* new_node = new Node(M);
            new_node->next = current->next;
            current->next = new_node;
            current = new_node->next;
        } else {
            current = current->next;
        }
        count++;
    }
}

void InsertBeforeEverySecond(LinkedList& list, int M) {
    list.InsertBeforeEverySecond(M);
}
