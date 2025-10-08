/* Продолжение задания №5: Перемещение среднего элемента из списка L1 с нечётным количеством элементов 
в конец списка L2 с помощью одного вызова функции splice */

#include "list_processor.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

ListProcessor::ListProcessor() {
    std::srand(std::time(0));
}

void ListProcessor::Run() {
    std::cin >> *this;
    
    if (!ValidateInput()) {
        throw std::invalid_argument("Invalid input data");
    }
    
    InputData(L1_, input_data_.n1);
    InputData(L2_, input_data_.n2);
    
    std::cout << "Изначальное содержимое списков:\n";
    std::cout << *this;
    
    MoveMiddleElement();
    
    std::cout << "Изменённое содержимое списков:\n";
    std::cout << *this;
}

void ListProcessor::InputData(std::list<int>& container, int size) {
    if (size <= 0) return;
    
    int choice;
    std::cout << "Выберите способ заполнения контейнера:\n";
    std::cout << "1) Ввод с клавиатуры\n";
    std::cout << "2) Ввод с помощью рандомайзера\n";
    std::cout << "3) Ввод данных из текстового файла\n";
    std::cin >> choice;
    
    switch (choice) {
        case 1:
            InputFromKeyboard(container, size);
            break;
        case 2:
            InputFromRandom(container, size);
            break;
        case 3:
            InputFromFile(container, size);
            break;
        default:
            throw std::invalid_argument("Invalid input method choice");
    }
}

void ListProcessor::InputFromKeyboard(std::list<int>& container, int size) {
    int value;
    for (int i = 0; i < size; ++i) {
        std::cout << "Введите " << i + 1 << " элемент: ";
        std::cin >> value;
        container.insert(container.end(), value);
    }
}

void ListProcessor::InputFromRandom(std::list<int>& container, int size) {
    for (int i = 0; i < size; ++i) {
        container.insert(container.end(), std::rand() % 101 - 50);
    }
}

void ListProcessor::InputFromFile(std::list<int>& container, int size) {
    std::ifstream file("a.txt", std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file a.txt");
    }
    
    int value;
    for (int i = 0; i < size && file >> value; ++i) {
        container.insert(container.end(), value);
    }
    file.close();
}

void ListProcessor::PrintList(const std::list<int>& container) const {
    for (std::list<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void ListProcessor::MoveMiddleElement() {
    if (L1_.empty()) return;
    
    std::list<int>::iterator middle_it = L1_.begin();
    std::advance(middle_it, L1_.size() / 2);
    
    L2_.splice(L2_.end(), L1_, middle_it);
}

bool ListProcessor::ValidateInput() const {
    return (input_data_.n1 > 0 && input_data_.n1 % 2 == 1 && 
            input_data_.n2 >= 0);
}

std::ostream& operator<<(std::ostream& os, const ListProcessor& processor) {
    os << "L1: ";
    for (std::list<int>::const_iterator it = processor.L1_.begin(); it != processor.L1_.end(); ++it) {
        os << *it << " ";
    }
    os << "\nL2: ";
    for (std::list<int>::const_iterator it = processor.L2_.begin(); it != processor.L2_.end(); ++it) {
        os << *it << " ";
    }
    os << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, ListProcessor& processor) {
    std::cout << "Введите размерность списка n1 (n1 - нечётное): ";
    is >> processor.input_data_.n1;
    std::cout << "Введите размерность списка n2 (n2 >= 0): ";
    is >> processor.input_data_.n2;
    return is;
}
