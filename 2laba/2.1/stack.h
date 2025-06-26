#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

class Node {
 public:
  int data;      
  Node* next;    

  explicit Node(int d) : data(d), next(nullptr) {}
};

class Stack {
 public:
  Stack() : top_(nullptr) {}
  ~Stack();

  Stack(const Stack&) = delete;
  Stack& operator=(const Stack&) = delete;

  Node* Push(int value);

  void Show() const;

  Node* GetTopAddress() const { return top_; }

  int GetTopValue() const;

  bool IsEmpty() const { return top_ == nullptr; }

 private:
  Node* top_;  
};

#endif  
