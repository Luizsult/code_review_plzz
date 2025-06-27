#include <fstream>
#include <iostream>
#include <memory>
#include <stack>
#include <stdexcept>
#include <string>

// Коды операций
const int kAddition = -1;
const int kSubtraction = -2;
const int kMultiplication = -3;
const int kDivision = -4;
const int kModulus = -5;
const int kExponentiation = -6;

// Узел дерева выражения
struct TreeNode {
  int value;
  std::unique_ptr<TreeNode> left;
  std::unique_ptr<TreeNode> right;

  explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для проверки, является ли токен операцией
bool IsOperator(int value) {
  return value == kAddition || value == kSubtraction || 
         value == kMultiplication || value == kDivision || 
         value == kModulus || value == kExponentiation;
}

// Функция для вычисления значения поддерева
int EvaluateSubtree(const std::unique_ptr<TreeNode>& node) {
  if (node == nullptr) {
    throw std::runtime_error("Attempt to evaluate null node");
  }

  if (!IsOperator(node->value)) {
    return node->value;
  }

  int left_val = EvaluateSubtree(node->left);
  int right_val = EvaluateSubtree(node->right);

  switch (node->value) {
    case kAddition: return left_val + right_val;
    case kSubtraction: return left_val - right_val;
    case kMultiplication: return left_val * right_val;
    case kDivision: 
      if (right_val == 0) throw std::runtime_error("Division by zero");
      return left_val / right_val;
    case kModulus:
      if (right_val == 0) throw std::runtime_error("Division by zero in modulus");
      return left_val % right_val;
    case kExponentiation: {
      if (right_val < 0) throw std::runtime_error("Negative exponent");
      int result = 1;
      for (int i = 0; i < right_val; ++i) {
        result *= left_val;
      }
      return result;
    }
    default:
      throw std::runtime_error("Unknown operator");
  }
}

// Функция для замены поддеревьев с возведением в степень их значениями
void ReplaceExponentiations(std::unique_ptr<TreeNode>* node_ptr) {
  if (node_ptr == nullptr || *node_ptr == nullptr) {
    return;
  }

  TreeNode* node = node_ptr->get();

  // Рекурсивно обрабатываем детей
  ReplaceExponentiations(&(node->left));
  ReplaceExponentiations(&(node->right));

  // Если текущий узел - возведение в степень
  if (node->value == kExponentiation) {
    int value = EvaluateSubtree(*node_ptr);
    *node_ptr = std::make_unique<TreeNode>(value);
  }
}

// Функция для построения дерева из префиксного выражения
std::unique_ptr<TreeNode> BuildExpressionTree(const std::string& expression) {
  std::stack<std::unique_ptr<TreeNode>*> stack;
  std::unique_ptr<TreeNode> root = nullptr;
  std::unique_ptr<TreeNode>* current = &root;

  for (size_t i = 0; i < expression.size(); ) {
    // Пропускаем пробелы
    if (expression[i] == ' ') {
      ++i;
      continue;
    }

    // Обрабатываем операторы
    if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
        expression[i] == '/' || expression[i] == '%' || expression[i] == '^') {
      int op_value;
      switch (expression[i]) {
        case '+': op_value = kAddition; break;
        case '-': op_value = kSubtraction; break;
        case '*': op_value = kMultiplication; break;
        case '/': op_value = kDivision; break;
        case '%': op_value = kModulus; break;
        case '^': op_value = kExponentiation; break;
        default: throw std::runtime_error("Unknown operator");
      }

      *current = std::make_unique<TreeNode>(op_value);
      stack.push(current);
      current = &((*current)->left);
      ++i;
    } 
    // Обрабатываем числа
    else if (isdigit(expression[i])) {
      int num = 0;
      while (i < expression.size() && isdigit(expression[i])) {
        num = num * 10 + (expression[i] - '0');
        ++i;
      }

      *current = std::make_unique<TreeNode>(num);
      
      if (stack.empty()) {
        break;  // Дерево построено
      }

      current = stack.top();
      stack.pop();
      current = &((*current)->right);
    } else {
      throw std::runtime_error("Invalid character in expression");
    }
  }

  return root;
}

// Функция для чтения выражения из файла
std::string ReadExpressionFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file");
  }

  std::string expression;
  std::getline(file, expression);
  return expression;
}

// Основная функция для выполнения задания
TreeNode* ProcessExpression(const std::string& filename) {
  // Читаем выражение из файла
  std::string expression = ReadExpressionFromFile(filename);

  // Строим дерево выражения
  std::unique_ptr<TreeNode> root = BuildExpressionTree(expression);

  // Заменяем возведения в степень их значениями
  ReplaceExponentiations(&root);

  // Возвращаем указатель на корень (передаем владение вызывающему)
  return root.release();
}

int main() {
  try {
    TreeNode* root = ProcessExpression("input.txt");
    delete root;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
