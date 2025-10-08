/* Продолжение задания №1: Реализация стека на связном списке, 
позволяя добавлять элементы и отслеживать адреса памяти вершин стека.*/

#include "stack.h"
#include <iostream>

Stack::Stack() : top_(nullptr) {}

Stack::~Stack() {
    Clear();
}

void Stack::Push(int value) {
    Node* new_node = new Node(value);
    new_node->next = top_;
    top_ = new_node;
}

void Stack::Pop() {
    if (IsEmpty()) {
        std::cout << "Стек пуст! Удаление невозможно." << std::endl;
        return;
    }
    
    Node* temp = top_;
    top_ = top_->next;
    delete temp;
}

int Stack::Top() const {
    if (IsEmpty()) {
        std::cout << "Стек пуст!" << std::endl;
        return -1;  // Возвращаем значение по умолчанию для пустого стека
    }
    return top_->data;
}

bool Stack::IsEmpty() const {
    return top_ == nullptr;
}

void Stack::Show() const {
    Node* current = top_;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void Stack::ShowTopAddress() const {
    std::cout << "Адрес вершины стека: " << top_ << std::endl;
}

void Stack::Clear() {
    while (!IsEmpty()) {
        Pop();
    }
}

std::ostream& operator<<(std::ostream& os, const Stack& stack) {
    Node* current = stack.top_;
    while (current != nullptr) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}
