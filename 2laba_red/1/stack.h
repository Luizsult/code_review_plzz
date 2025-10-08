/*Продолжение задания №1: Реализация стека

Дано число D и указатель P1 на вершину непустого стека. 
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

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
