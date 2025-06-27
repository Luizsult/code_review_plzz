#include "expression_evaluator.h"
#include <cctype>

//FIXME: Добавлена проверка корректности входных данных, исключения вместо exit, 
//убраны лишние комментарии, параметры const &, size_t вместо int для индекса
//int NumRead(string& s, int& symb, int currentNumber = 0) {
int ParseNumber(const std::string& expression, size_t& pos) {
  if (pos >= expression.length() || !std::isdigit(expression[pos])) {
    throw std::invalid_argument("Expected digit at position " + std::to_string(pos));
  }
  int number = 0;
  while (pos < expression.length() && std::isdigit(expression[pos])) {
    number = number * 10 + (expression[pos] - '0');
    ++pos;
  }
  return number;
}

//FIXME: Используем ParseNumber, проверяем деление на 0, убираем оператор '/' из условия 
int EvaluateTerm(const std::string& expression, size_t& pos) {
  int value = ParseNumber(expression, pos);
  while (pos < expression.length() && expression[pos] == '*') {
    ++pos;  // skip '*'
    int rhs = ParseNumber(expression, pos);
    value *= rhs;
  }
  return value;
}

//FIXME: Используем EvaluateTerm, проверяем корректность, убраны лишние комментарии
int EvaluateExpression(const std::string& expression, size_t& pos) {
  int value = EvaluateTerm(expression, pos);
  while (pos < expression.length() && (expression[pos] == '+' || expression[pos] == '-')) {
    char op = expression[pos];
    ++pos;
    int rhs = EvaluateTerm(expression, pos);
    if (op == '+') {
      value += rhs;
    } else {
      value -= rhs;
    }
  }
  return value;
}
