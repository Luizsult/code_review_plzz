#include "stack.h"
#include <iostream>

Stack::~Stack() {
  while (top_ != nullptr) {
    Node* temp = top_;
    top_ = top_->next;
    delete temp;
  }
}

Node* Stack::Push(int value) {
  Node* new_node = new Node(value);
  new_node->next = top_;
  top_ = new_node;
  return top_;
}

void Stack::Show() const {
  Node* current = top_;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}

int Stack::GetTopValue() const {
  if (IsEmpty()) {
    throw std::runtime_error("Ошибка: попытка получить значение из пустого стека");
  }
  return top_->data;
}
