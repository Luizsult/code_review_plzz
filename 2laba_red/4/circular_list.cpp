/* Продолжение задачи №4: Удаление из циклического двусвязного списка всех элементов, 
  у которых левый и правый соседи имеют одинаковые значения, и возвращение ссылки на последний элемент полученного списка */

#include "circular_list.h"
#include <iostream>

Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {}

CircularList::CircularList() : head_(nullptr), tail_(nullptr) {}

CircularList::~CircularList() {
    Clear();
}

void CircularList::AddLast(int value) {
    Node* new_node = new Node(value);
    
    if (tail_ == nullptr) {
        head_ = new_node;
        tail_ = new_node;
        new_node->next = new_node;
        new_node->prev = new_node;
    } else {
        new_node->prev = tail_;
        new_node->next = head_;
        tail_->next = new_node;
        head_->prev = new_node;
        tail_ = new_node;
    }
}

void CircularList::RemoveMatchingNeighbors() {
    if (head_ == nullptr || head_->next == head_) {
        return;  
    }
    
    Node* current = head_;
    bool made_changes = true;
    
    while (made_changes) {
        made_changes = false;
        Node* start = current;
        
        do {
            Node* next_node = current->next;
            
            if (current->prev->value == current->next->value) {
                RemoveNode(current);
                made_changes = true;
                
                if (head_ == nullptr) {
                    break;  // Список стал пустым
                }
            }
            
            current = next_node;
        } while (current != start && head_ != nullptr);
        
        if (head_ == nullptr) {
            break;
        }
    }
}

void CircularList::Show() const {
    if (head_ == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }
    
    Node* current = head_;
    do {
        std::cout << current->value << " ";
        current = current->next;
    } while (current != head_);
    std::cout << std::endl;
}

void CircularList::Clear() {
    if (head_ == nullptr) {
        return;
    }
    
    Node* current = head_;
    do {
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != head_);
    
    head_ = nullptr;
    tail_ = nullptr;
}

bool CircularList::IsEmpty() const {
    return head_ == nullptr;
}

Node* CircularList::GetTail() const {
    return tail_;
}

void CircularList::RemoveNode(Node* node) {
    if (node == nullptr) {
        return;
    }
    
    if (node->next == node) {
        delete node;
        head_ = nullptr;
        tail_ = nullptr;
        return;
    }
    
    node->prev->next = node->next;
    node->next->prev = node->prev;
    
    if (node == head_) {
        head_ = node->next;
    }
    if (node == tail_) {
        tail_ = node->prev;
    }
    
    delete node;
}
