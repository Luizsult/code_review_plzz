/* Продолжение задания №5: Перемещение среднего элемента из списка L1 с нечётным количеством элементов 
в конец списка L2 с помощью одного вызова функции splice */

#ifndef LIST_PROCESSOR_H
#define LIST_PROCESSOR_H

#include <list>
#include <iostream>

struct InputData {
    int n1;
    int n2;
};

class ListProcessor {
public:
    ListProcessor();
    
    void Run();
    
    friend std::ostream& operator<<(std::ostream& os, const ListProcessor& processor);
    friend std::istream& operator>>(std::istream& is, ListProcessor& processor);

private:
    void InputFromKeyboard(std::list<int>& container, int size);
    void InputFromRandom(std::list<int>& container, int size);
    void InputFromFile(std::list<int>& container, int size);
    
    void InputData(std::list<int>& container, int size);
    void PrintList(const std::list<int>& container) const;
    void MoveMiddleElement();
    
    bool ValidateInput() const;
    
    std::list<int> L1_;
    std::list<int> L2_;
    InputData input_data_;
};

std::ostream& operator<<(std::ostream& os, const ListProcessor& processor);
std::istream& operator>>(std::istream& is, ListProcessor& processor);

#endif 
