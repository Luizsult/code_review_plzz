#include "list_operations.h"

#include <iostream>
#include <stdexcept>

int main() {
    try {
        std::list<int> list1;
        std::list<int> list2;

        int size1, size2;
        std::cout << "Введите размер первого списка (нечетное число): ";
        if (!(std::cin >> size1) || size1 <= 0 || size1 % 2 != 1) {
            throw std::invalid_argument("Размер первого списка должен быть положительным нечетным числом");
        }

        std::cout << "Введите размер второго списка: ";
        if (!(std::cin >> size2) || size2 < 0) {
            throw std::invalid_argument("Размер второго списка должен быть неотрицательным");
        }

        std::cout << "\nВыберите метод ввода для первого списка:\n"
                  << "1) С клавиатуры\n"
                  << "2) Случайные числа\n"
                  << "3) Из файла\n"
                  << "Ваш выбор: ";
        
        int choice;
        if (!(std::cin >> choice) || choice < 1 || choice > 3) {
            throw std::invalid_argument("Неверный выбор метода ввода");
        }

        InputMethod method = static_cast<InputMethod>(choice - 1);
        std::string filename;
        if (method == InputMethod::kFile) {
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
        }

        InputList(list1, size1, method, filename);

        std::cout << "\nВыберите метод ввода для второго списка:\n"
                  << "1) С клавиатуры\n"
                  << "2) Случайные числа\n"
                  << "3) Из файла\n"
                  << "Ваш выбор: ";
        
        if (!(std::cin >> choice) || choice < 1 || choice > 3) {
            throw std::invalid_argument("Неверный выбор метода ввода");
        }

        method = static_cast<InputMethod>(choice - 1);
        if (method == InputMethod::kFile) {
            std::cout << "Введите имя файла: ";
            std::cin >> filename;
        }

        InputList(list2, size2, method, filename);

        std::cout << "\nИсходные списки:\n";
        std::cout << "L1: ";
        PrintList(list1);
        std::cout << "L2: ";
        PrintList(list2);

        MoveMiddleToOtherList(list1, list2);

        std::cout << "\nИзмененные списки:\n";
        std::cout << "L1: ";
        PrintList(list1);
        std::cout << "L2: ";
        PrintList(list2);

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
