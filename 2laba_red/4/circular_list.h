/* Продолжение задачи №4: Удаление из циклического двусвязного списка всех элементов, 
  у которых левый и правый соседи имеют одинаковые значения, и возвращение ссылки на последний элемент полученного списка */

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

struct Node {
    int value;
    Node* next;
    Node* prev;
    explicit Node(int val);
};

class CircularList {
 public:
    CircularList();
    ~CircularList();
    
    void AddLast(int value);
    void RemoveMatchingNeighbors();
    void Show() const;
    void Clear();
    bool IsEmpty() const;
    Node* GetTail() const;

 private:
    Node* head_;
    Node* tail_;
    void RemoveNode(Node* node);
};

#endif  
