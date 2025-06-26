#include "list_operations.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

void InputList(std::list<int>& list, int size, InputMethod method,
               const std::string& filename) {
    if (size < 0) {
        throw std::invalid_argument("Размер списка не может быть отрицательным");
    }

    list.clear();

    switch (method) {
        case InputMethod::kKeyboard: {
            std::cout << "Введите " << size << " элементов:" << std::endl;
            for (int i = 0; i < size; ++i) {
                int value;
                std::cout << "Элемент " << i + 1 << ": ";
                if (!(std::cin >> value)) {
                    throw std::runtime_error("Ошибка ввода данных");
                }
                list.push_back(value);
            }
            break;
        }
        case InputMethod::kRandom: {
            std::srand(std::time(0));
            for (int i = 0; i < size; ++i) {
                list.push_back(std::rand() % 101 - 50);
            }
            break;
        }
        case InputMethod::kFile: {
            std::ifstream file(filename);
            if (!file.is_open()) {
                throw std::runtime_error("Не удалось открыть файл: " + filename);
            }
            for (int i = 0; i < size; ++i) {
                int value;
                if (!(file >> value)) {
                    throw std::runtime_error("Ошибка чтения из файла или недостаточно данных");
                }
                list.push_back(value);
            }
            break;
        }
        default:
            throw std::invalid_argument("Неизвестный метод ввода");
    }
}

void PrintList(const std::list<int>& list) {
    for (const auto& item : list) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void MoveMiddleToOtherList(std::list<int>& source, std::list<int>& destination) {
    if (source.size() % 2 != 1) {
        throw std::invalid_argument("Исходный список должен иметь нечетный размер");
    }

    auto middle = source.begin();
    std::advance(middle, source.size() / 2);
    destination.splice(destination.end(), source, middle);
}
