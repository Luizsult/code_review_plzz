/* Продолжение задания №2: Реализация очереди на указателях 
  с функциями добавления и извлечения элементов, 
  выводя адреса начала и конца после извлечения пяти элементов */

#ifndef QUEUE_H
#define QUEUE_H

struct PNode {
    int data;
    PNode* next;
};

class TQueue {
 public:
    TQueue();
    ~TQueue();
    
    void Enqueue(int value);  
    int Dequeue();            
    bool IsEmpty() const;     
    void Print() const;       
    PNode* GetFront() const;  
    PNode* GetLast() const;  

 private:
    PNode* front_;  
    PNode* last_;  
    
    void Clear();
};

#endif  // QUEUE_H
