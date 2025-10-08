/* Продолжение задачи №4: Удаление из циклического двусвязного списка всех элементов, 
  у которых левый и правый соседи имеют одинаковые значения, и возвращение ссылки на последний элемент полученного списка */

#include "circular_list.h"
#include <iostream>
#include <limits>

int main() {
    setlocale(LC_ALL, "Russian");
    CircularList list;
    int n, x;
    
    std::cout << "Введите количество чисел, которые необходимо записать в список: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Ошибка: количество элементов должно быть положительным." << std::endl;
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << "Введите " << i + 1 << " число: ";
        std::cin >> x;
        list.AddLast(x);
    }
    
    std::cout << "Исходный список: ";
    list.Show();
    
    list.RemoveMatchingNeighbors();
    
    std::cout << "Изменённый список: ";
    list.Show();
    
    Node* tail = list.GetTail();
    if (tail != nullptr) {
        std::cout << "Ссылка на последний элемент: " << tail->value << std::endl;
    } else {
        std::cout << "Список пуст, последнего элемента нет" << std::endl;
    }
    
    return 0;
}
