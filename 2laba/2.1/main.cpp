#include "stack.h"
#include <iostream>
#include <limits>
#include <windows.h>

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  try {
    Stack stack;
    int n;
    
    std::cout << "Сколько чисел вы хотите добавить в стек? ";
    if (!(std::cin >> n) || n < 0) {
      throw std::invalid_argument("Ошибка: количество элементов должно быть неотрицательным числом");
    }

    for (int i = 0; i < n; ++i) {
      int value;
      std::cout << "Введите число " << (i + 1) << ": ";
      if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::invalid_argument("Ошибка: введено некорректное число");
      }
      stack.Push(value);
    }

    std::cout << "Адрес текущей вершины стека: " << stack.GetTopAddress() << std::endl;
    std::cout << "Элементы в стеке: ";
    stack.Show();

    int d;
    std::cout << "Введите значение D для добавления в стек: ";
    if (!(std::cin >> d)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw std::invalid_argument("Ошибка: введено некорректное число");
    }

    Node* new_top = stack.Push(d);
    std::cout << "Элементы в новом стеке: ";
    stack.Show();
    std::cout << "Адрес новой вершины стека: " << new_top << std::endl;

    if (!stack.IsEmpty()) {
      std::cout << "Значение новой вершины: " << stack.GetTopValue() << std::endl;
    } else {
      std::cout << "Стек пуст!" << std::endl;
    }

  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
