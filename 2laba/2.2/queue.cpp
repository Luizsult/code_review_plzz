#include "queue.h"
#include <iostream>

PQueue::~PQueue() {
    while (front_ != nullptr) {
        PNode* temp = front_;
        front_ = front_->next;
        delete temp;
    }
    last_ = nullptr;
}

void PQueue::Enqueue(int value) {
    PNode* newNode = new PNode{value, nullptr};
    
    if (last_ != nullptr) {
        last_->next = newNode;
    } else {
        front_ = newNode;  
    }
    last_ = newNode;
}

int PQueue::Dequeue() {
    if (IsEmpty()) {
        throw std::runtime_error("Ошибка: попытка извлечения из пустой очереди");
    }

    PNode* temp = front_;
    int value = temp->data;
    front_ = front_->next;
    
    if (front_ == nullptr) {
        last_ = nullptr;  // Если очередь стала пустой
    }
    
    delete temp;
    return value;
}
