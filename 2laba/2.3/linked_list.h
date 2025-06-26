#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdexcept>
#include <string>

class Node {
public:
    int data;
    Node* next;
    explicit Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { clearList(); }

    void add(int value);

    void insertBeforeEverySecond(int M);

    void print() const;

    Node* getLastNode() const;

    void clearList();

    friend void insertBeforeEverySecond(LinkedList& list, int M);

private:
    Node* head;

    bool isEmpty() const { return head == nullptr; }
};

void insertBeforeEverySecond(LinkedList& list, int M);

#endif 
