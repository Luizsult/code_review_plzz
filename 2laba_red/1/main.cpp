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

#include <iostream>
#include <Windows.h>
#include "stack.h"

int main() {
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Stack stack;
    int count, number;

    std::cout << "Сколько чисел вы хотите добавить в стек? ";
    std::cin >> count;

    for (int i = 0; i < count; i++) {
        std::cout << "Введите число " << i + 1 << ": ";
        std::cin >> number;
        stack.Push(number);
    }

    stack.ShowTopAddress();
    std::cout << "Элементы в стеке: ";
    stack.Show();

    int value_to_add;
    std::cout << "Введите значение D для добавления в стек: ";
    std::cin >> value_to_add;

    // Сохраняем адрес текущей вершины перед добавлением
    stack.ShowTopAddress();
    
    stack.Push(value_to_add);

    std::cout << "Элементы в новом стеке: ";
    stack.Show();
    
    stack.ShowTopAddress();

    if (!stack.IsEmpty()) {
        std::cout << "Значение новой вершины: " << stack.Top() << std::endl;
    } else {
        std::cout << "Стек пуст!" << std::endl;
    }

    std::cout << "Дружественный вывод стека: " << stack << std::endl;

    return 0;
}
