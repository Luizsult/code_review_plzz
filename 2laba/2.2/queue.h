#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <string>

struct PNode {
    int data;
    PNode* next;
};

class PQueue {
public:
    PQueue() : front_(nullptr), last_(nullptr) {}
    ~PQueue();

    void Enqueue(int value);
    int Dequeue();
    
    bool IsEmpty() const { return front_ == nullptr; }
    PNode* front() const { return front_; }
    PNode* last() const { return last_; }

private:
    PNode* front_;  
    PNode* last_;   
};

#endif  
