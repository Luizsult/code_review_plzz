#include <iostream>
#include <string>
#include "expression_evaluator.h"

int main() {
  std::cout << "Введите выражение -> ";
  std::string expression;
  std::getline(std::cin, expression);

  try {
    size_t pos = 0;
    int result = EvaluateExpression(expression, pos);
    if (pos != expression.length()) {
      throw std::invalid_argument("Unexpected character at position " + std::to_string(pos));
    }
    std::cout << "Результат -> " << result << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
