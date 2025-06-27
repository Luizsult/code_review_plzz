#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>

namespace exprtree {

// Коды операций
enum OperationCode {
  kAdd = -1,
  kSubtract = -2,
  kMultiply = -3,
  kDivide = -4,
  kModulo = -5,
  kPower = -6,
};

// Узел дерева выражения
struct Node {
  int value;  // Если >= 0: операнд (0..9), если < 0: операция (-1..-6)
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  explicit Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для вычисления степени с целочисленным возведением
int IntPow(int base, int exp) {
  if (exp < 0) {
    throw std::invalid_argument("Negative exponent not supported");
  }
  int result = 1;
  while (exp > 0) {
    if (exp & 1) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }
  return result;
}

// Функция вычисления значения поддерева (без операций ^, т.к. они будут заменены)
int EvaluateTree(const Node* node) {
  if (!node) {
    throw std::invalid_argument("Null node in EvaluateTree");
  }
  if (node->value >= 0) {
    // Операнд
    return node->value;
  }
  // Операция
  int left_val = EvaluateTree(node->left.get());
  int right_val = EvaluateTree(node->right.get());
  switch (node->value) {
    case kAdd:
      return left_val + right_val;
    case kSubtract:
      return left_val - right_val;
    case kMultiply:
      return left_val * right_val;
    case kDivide:
      if (right_val == 0) {
        throw std::domain_error("Division by zero");
      }
      return left_val / right_val;
    case kModulo:
      if (right_val == 0) {
        throw std::domain_error("Modulo by zero");
      }
      return left_val % right_val;
    case kPower:
      // Возведение в степень не должно встречаться после преобразования,
      // но на всякий случай можно вычислить.
      return IntPow(left_val, right_val);
    default:
      throw std::logic_error("Unknown operation code");
  }
}

// Функция преобразования символа операции в код
int OpCharToCode(char op) {
  switch (op) {
    case '+':
      return kAdd;
    case '-':
      return kSubtract;
    case '*':
      return kMultiply;
    case '/':
      return kDivide;
    case '%':
      return kModulo;
    case '^':
      return kPower;
    default:
      throw std::invalid_argument("Unknown operation character");
  }
}

// Парсинг префиксного выражения из потока
// Возвращает уникальный указатель на корень построенного поддерева
std::unique_ptr<Node> ParseExpression(std::istringstream* iss) {
  std::string token;
  if (!(*iss >> token)) {
    throw std::runtime_error("Unexpected end of expression");
  }
  if (token.size() == 1 && std::isdigit(token[0])) {
    // Операнд (0..9)
    int val = token[0] - '0';
    return std::make_unique<Node>(val);
  }
  if (token.size() == 1 && std::string("+-*/%^").find(token[0]) != std::string::npos) {
    int op_code = OpCharToCode(token[0]);
    auto left = ParseExpression(iss);
    auto right = ParseExpression(iss);
    auto node = std::make_unique<Node>(op_code);
    node->left = std::move(left);
    node->right = std::move(right);
    return node;
  }
  throw std::invalid_argument("Invalid token in expression: " + token);
}

// Рекурсивно преобразует дерево: заменяет поддеревья с операцией ^ на значение поддерева
// Возвращает уникальный указатель на преобразованное поддерево
std::unique_ptr<Node> RemovePowerOperations(std::unique_ptr<Node> node) {
  if (!node) {
    return nullptr;
  }
  if (node->value >= 0) {
    // Операнд
    return node;
  }
  // Сначала преобразуем детей
  node->left = RemovePowerOperations(std::move(node->left));
  node->right = RemovePowerOperations(std::move(node->right));
  if (node->value == kPower) {
    // Вычисляем значение поддерева и заменяем на операнд
    int val = EvaluateTree(node.get());
    return std::make_unique<Node>(val);
  }
  return node;
}

// Функция чтения выражения из файла и построения дерева
std::unique_ptr<Node> BuildTreeFromFile(const std::string& filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Cannot open file: " + filename);
  }
  std::string line;
  std::getline(file, line);
  std::istringstream iss(line);
  return ParseExpression(&iss);
}

// Вспомогательная функция для вывода дерева (для отладки)
void PrintTree(const Node* node, int depth = 0) {
  if (!node) {
    return;
  }
  for (int i = 0; i < depth; ++i) {
    std::cout << "  ";
  }
  if (node->value >= 0) {
    std::cout << node->value << "\n";
  } else {
    std::cout << node->value << "\n";
    PrintTree(node->left.get(), depth + 1);
    PrintTree(node->right.get(), depth + 1);
  }
}

}  // namespace exprtree

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " filename\n";
    return 1;
  }
  try {
    std::unique_ptr<exprtree::Node> root = exprtree::BuildTreeFromFile(argv[1]);
    root = exprtree::RemovePowerOperations(std::move(root));
    // Вывод указателя на корень (адрес)
    std::cout << "Root node address: " << root.get() << "\n";
    // Для проверки можно вывести дерево (раскомментировать)
    // exprtree::PrintTree(root.get());
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  return 0;
}
