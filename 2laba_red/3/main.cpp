/* Продолжение задания №3: Вставка значения M перед каждым вторым элементом односвязного списка 
    и возвращение указателя на последний элемент модифицированного списка */

#include "linked_list.h"
#include <iostream>

int main() {
    LinkedList list;
    int n, value, M;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;
    
    std::cout << "Введите элементы списка: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        list.Add(value);
    }

    std::cout << "Исходный список: ";
    list.Print();

    std::cout << "Введите значение M для вставки: ";
    std::cin >> M;

    InsertBeforeEverySecond(list, M);

    std::cout << "Список после вставки: ";
    list.Print();

    Node* last_node = list.GetLastNode();
    if (last_node != nullptr) {
        std::cout << "Указатель на последний элемент списка: " << last_node << std::endl;
        std::cout << "Значение последнего элемента: " << last_node->data << std::endl;
    } else {
        std::cout << "Список пуст." << std::endl;
    }

    list.Clear();

    std::cout << "Проверка списка после очистки: ";
    list.Print();

    return 0;
}
