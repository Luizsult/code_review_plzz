/* Продолжение задания №2: Реализация очереди на указателях с функциями добавления и извлечения элементов, 
  выводя адреса начала и конца после извлечения пяти элементов */

#include <iostream>
#include "queue.h"

int main() {
    TQueue queue;
    int n;
    
    std::cout << "Введите количество элементов для добавления в очередь (не менее 5): ";
    std::cin >> n;
    
    if (n < 5) {
        std::cout << "Ошибка: количество элементов должно быть не менее 5" << std::endl;
        return 1;
    }
    
    std::cout << "Введите " << n << " чисел:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        queue.Enqueue(value);
    }
    
    std::cout << "\nИсходная очередь:" << std::endl;
    queue.Print();
    
    std::cout << "\nИзвлеченные элементы: ";
    for (int i = 0; i < 5; ++i) {
        if (!queue.IsEmpty()) {
            int value = queue.Dequeue();
            std::cout << value << " ";
        } else {
            std::cout << "Очередь пуста. ";
            break;
        }
    }
    std::cout << std::endl;
    
    std::cout << "\nРезультирующая очередь:" << std::endl;
    queue.Print();
    
    PNode* front_ptr = queue.GetFront();
    PNode* last_ptr = queue.GetLast();
    
    if (front_ptr != nullptr) {
        std::cout << "Адрес начала очереди: " << front_ptr 
                  << ", Значение: " << front_ptr->data << std::endl;
    } else {
        std::cout << "Очередь пуста, адрес начала: nullptr" << std::endl;
    }
    
    if (last_ptr != nullptr) {
        std::cout << "Адрес конца очереди: " << last_ptr 
                  << ", Значение: " << last_ptr->data << std::endl;
    } else {
        std::cout << "Очередь пуста, адрес конца: nullptr" << std::endl;
    }
    
    return 0;
}
