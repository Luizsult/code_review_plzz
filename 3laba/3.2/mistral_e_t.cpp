#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>
#include <cmath>
#include <cctype>

// Узел дерева
struct TreeNode {
    int value;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция для построения дерева из префиксного выражения
std::unique_ptr<TreeNode> BuildTree(const std::vector<std::string>& tokens, int& index) {
    if (index >= tokens.size()) {
        return nullptr;
    }

    std::string token = tokens[index++];
    int value;

    if (token == "+") {
        value = -1;
    } else if (token == "-") {
        value = -2;
    } else if (token == "*") {
        value = -3;
    } else if (token == "/") {
        value = -4;
    } else if (token == "%") {
        value = -5;
    } else if (token == "^") {
        value = -6;
    } else {
        value = std::stoi(token);
    }

    auto node = std::make_unique<TreeNode>(value);
    if (value < 0) { // Если это операция, то у нее должны быть операнды
        node->left = BuildTree(tokens, index);
        node->right = BuildTree(tokens, index);
    }

    return node;
}

// Функция для вычисления значения поддерева
int EvaluateSubtree(const TreeNode* node) {
    if (!node) {
        return 0;
    }

    if (node->value >= 0) {
        return node->value;
    }

    int left_val = EvaluateSubtree(node->left.get());
    int right_val = EvaluateSubtree(node->right.get());

    switch (node->value) {
        case -1: return left_val + right_val;
        case -2: return left_val - right_val;
        case -3: return left_val * right_val;
        case -4: return left_val / right_val;
        case -5: return left_val % right_val;
        case -6: return static_cast<int>(std::pow(left_val, right_val));
        default: return 0;
    }
}

// Функция для преобразования дерева
void TransformTree(std::unique_ptr<TreeNode>& node) {
    if (!node) {
        return;
    }

    if (node->value == -6) { // Если операция возведения в степень
        int value = EvaluateSubtree(node.get());
        node = std::make_unique<TreeNode>(value);
    } else {
        TransformTree(node->left);
        TransformTree(node->right);
    }
}

// Функция для вывода дерева (для проверки)
void PrintTree(const TreeNode* node) {
    if (!node) {
        return;
    }

    std::cout << node->value << " ";
    PrintTree(node->left.get());
    PrintTree(node->right.get());
}

int main() {
    std::ifstream file("filename");
    if (!file.is_open()) {
        std::cerr << "Unable to open file";
        return 1;
    }

    std::vector<std::string> tokens;
    std::string token;
    while (file >> token) {
        tokens.push_back(token);
    }

    int index = 0;
    auto root = BuildTree(tokens, index);

    TransformTree(root);

    std::cout << "Root of the transformed tree: " << root.get() << std::endl;

    return 0;
}
