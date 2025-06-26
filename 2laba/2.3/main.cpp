#include "linked_list.h"
#include <iostream>
#include <limits>

int getValidatedInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: введите целое число.\n";
        }
    }
}

int main() {
    LinkedList list;
    try {
        int n = getValidatedInput("Введите количество элементов в списке: ");
        if (n < 0) {
            throw std::invalid_argument("Количество элементов не может быть отрицательным");
        }

        std::cout << "Введите элементы списка: ";
        for (int i = 0; i < n; ++i) {
            int value = getValidatedInput("");
            list.add(value);
        }

        int M = getValidatedInput("Введите значение M для вставки: ");
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
