/* Продолжение задания №2: Реализация очереди на указателях с функциями добавления и извлечения элементов, 
  выводя адреса начала и конца после извлечения пяти элементов */

#include "queue.h"
#include <iostream>

TQueue::TQueue() : front_(nullptr), last_(nullptr) {}

TQueue::~TQueue() {
    Clear();
}

void TQueue::Enqueue(int value) {
    PNode* new_node = new PNode{value, nullptr};
    
    if (last_ != nullptr) {
        last_->next = new_node;
    } else {
        front_ = new_node;  
    }
    last_ = new_node;
}

int TQueue::Dequeue() {
    if (IsEmpty()) {
        throw std::runtime_error("Ошибка: попытка извлечения из пустой очереди");
    }
    
    PNode* temp = front_;
    int value = temp->data;
    front_ = front_->next;
    
    if (front_ == nullptr) {
        last_ = nullptr; 
    }
    
    delete temp;
    return value;
}

bool TQueue::IsEmpty() const {
    return front_ == nullptr;
}

void TQueue::Print() const {
    PNode* current = front_;
    std::cout << "Очередь: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

PNode* TQueue::GetFront() const {
    return front_;
}

PNode* TQueue::GetLast() const {
    return last_;
}

void TQueue::Clear() {
    while (!IsEmpty()) {
        Dequeue();
    }
}
