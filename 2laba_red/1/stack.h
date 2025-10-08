/* Продолжение задания №1: Реализация стека на связном списке, 
позволяя добавлять элементы и отслеживать адреса памяти вершин стека.*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Node {
    int data;       
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
public:
    Stack();
    ~Stack();

    void Push(int value);
    void Pop();
    int Top() const;
    bool IsEmpty() const;
    void Show() const;
    void ShowTopAddress() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack);

private:
    Node* top_; 
    void Clear();
};

#endif  
