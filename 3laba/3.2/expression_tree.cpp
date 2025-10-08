/**
 * @file expression_tree.cpp
 * @brief Реализация операций с деревом выражений
 * 
 * Этот файл содержит реализацию функций для работы с деревьями префиксных выражений.
 */

#include "expression_tree.h"
#include <fstream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cmath>

using namespace std;

/**
 * @brief Вспомогательная функция для проверки, представляет ли значение операцию
 * @param val Проверяемое значение
 * @return true если значение является кодом операции, false в противном случае
 */
bool is_operation(int val) {
    return val >= -6 && val <= -1;
}

/**
 * @brief Вспомогательная функция для чтения следующей лексемы из входного потока
 * @param iss Входной строковый поток
 * @return Следующая лексема в виде целого числа
 * @throws std::runtime_error Если лексема неверная
 */
int read_next_token(istringstream& iss) {
    string token;
    if (!(iss >> token)) {
        throw runtime_error("Неожиданный конец выражения");
    }

    if (token == "+") return -1;
    if (token == "-") return -2;
    if (token == "*") return -3;
    if (token == "/") return -4;
    if (token == "%") return -5;
    if (token == "^") return -6;

    try {
        int num = stoi(token);
        if (num < 0 || num > 9) {
            throw runtime_error("Операнд вне диапазона (0-9): " + token);
        }
        return num;
    } catch (const invalid_argument&) {
        throw runtime_error("Неверная лексема: " + token);
    } catch (const out_of_range&) {
        throw runtime_error("Операнд вне диапазона (0-9): " + token);
    }
}

TreeNode* build_expression_tree(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Не удалось открыть файл: " + string(filename));
    }

    string expression;
    getline(file, file);
    istringstream iss(expression);

    stack<TreeNode*> node_stack;
    TreeNode* root = nullptr;

    try {
        vector<int> tokens;
        while (iss) {
            tokens.push_back(read_next_token(iss));
        }

        for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
            int val = *it;
            TreeNode* node = new TreeNode(val);

            if (is_operation(val)) {
                if (node_stack.size() < 2) {
                    throw runtime_error("Недостаточно операндов для операции");
                }
                node->left = node_stack.top();
                node_stack.pop();
                node->right = node_stack.top();
                node_stack.pop();
            }

            node_stack.push(node);
        }

        if (node_stack.size() != 1) {
            throw runtime_error("Неверный формат выражения");
        }

        root = node_stack.top();
    } catch (const exception& e) {
        while (!node_stack.empty()) {
            delete node_stack.top();
            node_stack.pop();
        }
        throw;
    }

    return root;
}

/**
 * @brief Вспомогательная функция для вычисления поддерева и замены его узлом значения
 * @param node Указатель на корень поддерева для вычисления
 */
void evaluate_and_replace(TreeNode* node) {
    if (!node || !is_operation(node->value)) return;

    evaluate_and_replace(node->left);
    evaluate_and_replace(node->right);

    if (node->value == -6) { 
        if (!node->left || !node->right) {
            throw runtime_error("Неверная операция возведения в степень");
        }

        int base = node->left->value;
        int exponent = node->right->value;
        int result = static_cast<int>(pow(base, exponent));

        node->value = result;
        delete node->left;
        delete node->right;
        node->left = nullptr;
        node->right = nullptr;
    }
}

void remove_exponentiation(TreeNode* root) {
    if (!root) return;
    evaluate_and_replace(root);
}

void delete_tree(TreeNode* root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}
