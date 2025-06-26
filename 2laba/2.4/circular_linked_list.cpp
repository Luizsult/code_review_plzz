#include "circular_linked_list.h"
#include <iostream>

CircularLinkedList::~CircularLinkedList() {
  Clear();
}

void CircularLinkedList::ValidateList() const {
  if ((head_ == nullptr) != (tail_ == nullptr)) {
    throw std::logic_error("Invalid list state: head/tail mismatch");
  }
  if ((head_ != nullptr) && (head_->prev != tail_)) {
    throw std::logic_error("Invalid list: head prev not pointing to tail");
  }
  if ((tail_ != nullptr) && (tail_->next != head_)) {
    throw std::logic_error("Invalid list: tail next not pointing to head");
  }
}

void CircularLinkedList::Append(int value) {
  Node* new_node = new Node(value);
  
  if (IsEmpty()) {
    head_ = tail_ = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
  } else {
    new_node->prev = tail_;
    new_node->next = head_;
    tail_->next = new_node;
    head_->prev = new_node;
    tail_ = new_node;
  }
  size_++;
  ValidateList();
}

void CircularLinkedList::RemoveNodesWithEqualNeighbors() {
  if (IsEmpty()) return;
  ValidateList();

  Node* current = head_;
  bool modified = false;

  do {
    Node* next_node = current->next;
    
    if (current->prev->value == current->next->value && 
        current->prev != current->next) {
      if (size_ == 1) {
        delete current;
        head_ = tail_ = nullptr;
        size_ = 0;
        return;
      }

      current->prev->next = current->next;
      current->next->prev = current->prev;

      if (current == head_) {
        head_ = current->next;
      }
      if (current == tail_) {
        tail_ = current->prev;
      }

      delete current;
      size_--;
      modified = true;
    }
    current = next_node;
  } while (current != head_ && !IsEmpty());

  if (modified) {
    ValidateList();
  }
}

void CircularLinkedList::Display() const {
  if (IsEmpty()) {
    std::cout << "List is empty\n";
    return;
  }

  Node* current = head_;
  do {
    std::cout << current->value << " ";
    current = current->next;
  } while (current != head_);
  std::cout << "\n";
}

void CircularLinkedList::Clear() {
  if (IsEmpty()) return;

  Node* current = head_;
  do {
    Node* temp = current;
    current = current->next;
    delete temp;
  } while (current != head_);

  head_ = tail_ = nullptr;
  size_ = 0;
}
