/*Дано число D и указатель P1 на вершину непустого стека. 
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов - 
добавления/удаления/вывода элементов. 
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

#include "stack.h"
#include <iostream>
#include <limits>
#include <windows.h>

int SafeInputInt(const std::string& prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка ввода. Пожалуйста, введите целое число." << std::endl;
  }
  return value;
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  try {
    Stack stack;
    int n = SafeInputInt("Сколько чисел вы хотите добавить в стек? ");
    if (n < 0) {
      throw std::invalid_argument("Количество элементов не может быть отрицательным");
    }

    for (int i = 0; i < n; ++i) {
      int value = SafeInputInt("Введите число " + std::to_string(i + 1) + ": ");
      stack.Push(value);
    }

    std::cout << "Адрес текущей вершины стека: " << stack.GetTopAddress() << std::endl;
    std::cout << "Элементы в стеке: ";
    stack.Show();

    int d = SafeInputInt("Введите значение D для добавления в стек: ");
    Node* new_top = stack.Push(d);
    std::cout << "Элементы в новом стеке: ";
    stack.Show();
    std::cout << "Адрес новой вершины стека: " << new_top << std::endl;

    if (!stack.IsEmpty()) {
      std::cout << "Значение новой вершины: " << stack.GetTopValue() << std::endl;
    }
  } catch (const std::exception& e) {
    std::cerr << "Произошла ошибка: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
