#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <stdexcept>
#include <string>

class Node {
 public:
  int value;
  Node* next;
  Node* prev;

  explicit Node(int val) : value(val), next(nullptr), prev(nullptr) {}
};

class CircularLinkedList {
 public:
  CircularLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
  ~CircularLinkedList();

  void Append(int value);
  void RemoveNodesWithEqualNeighbors();
  void Display() const;
  void Clear();
  bool IsEmpty() const { return size_ == 0; }
  int size() const { return size_; }
  Node* last_node() const { return tail_; }

 private:
  Node* head_;
  Node* tail_;
  int size_;

  void ValidateList() const;
};

#endif  
