#include "linked_list.h"
#include <iostream>
#include <limits>

int main() {
    LinkedList list;
    try {
        int n;
        std::cout << "Введите количество элементов в списке: ";
        if (!(std::cin >> n) || n < 0) {
            throw std::invalid_argument("Неверное количество элементов");
        }

        std::cout << "Введите элементы списка: ";
        for (int i = 0; i < n; ++i) {
            int value;
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw std::invalid_argument("Неверный формат элемента списка");
            }
            list.add(value);
        }

        int M;
        std::cout << "Введите значение M для вставки: ";
        if (!(std::cin >> M)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Неверный формат значения M");
        }

        insertBeforeEverySecond(list, M);

        std::cout << "Список после вставки: ";
        list.print();

        Node* lastNode = list.getLastNode();
        if (lastNode != nullptr) {
            std::cout << "Указатель на последний элемент списка: " << lastNode << "\n";
            std::cout << "Значение последнего элемента: " << lastNode->data << "\n";
        } else {
            std::cout << "Список пуст.\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
