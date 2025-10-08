#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;      
    Node* next;    
    Node(int value);
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    void Add(int value);                    
    void Remove(int value);                 
    void Print() const;                     
    void Clear();                           
    Node* GetLastNode() const;              
    bool IsEmpty() const;                   
    
    friend void InsertBeforeEverySecond(LinkedList& list, int M);

private:
    void InsertBeforeEverySecond(int M);
    Node* head_; 
};

void InsertBeforeEverySecond(LinkedList& list, int M);

#endif  
