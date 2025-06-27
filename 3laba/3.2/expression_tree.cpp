/**
 * @file expression_tree.cpp
 * @brief Implementation of expression tree operations
 * 
 * This file contains the implementation of functions for working with prefix expression trees.
 */

#include "expression_tree.h"
#include <fstream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cmath>

using namespace std;

/**
 * @brief Helper function to check if a value represents an operation
 * @param val Value to check
 * @return True if the value is an operation code, false otherwise
 */
bool is_operation(int val) {
    return val >= -6 && val <= -1;
}

/**
 * @brief Helper function to read the next token from the input stream
 * @param iss Input string stream
 * @return The next token as an integer
 * @throws std::runtime_error If token is invalid
 */
int read_next_token(istringstream& iss) {
    string token;
    if (!(iss >> token)) {
        throw runtime_error("Unexpected end of expression");
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
            throw runtime_error("Operand out of range (0-9): " + token);
        }
        return num;
    } catch (const invalid_argument&) {
        throw runtime_error("Invalid token: " + token);
    } catch (const out_of_range&) {
        throw runtime_error("Operand out of range (0-9): " + token);
    }
}

TreeNode* build_expression_tree(const char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + string(filename));
    }

    string expression;
    getline(file, file);
    istringstream iss(expression);

    stack<TreeNode*> node_stack;
    TreeNode* root = nullptr;

    try {
        // We'll process tokens in reverse order for easier stack processing
        vector<int> tokens;
        while (iss) {
            tokens.push_back(read_next_token(iss));
        }

        for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) {
            int val = *it;
            TreeNode* node = new TreeNode(val);

            if (is_operation(val)) {
                if (node_stack.size() < 2) {
                    throw runtime_error("Not enough operands for operation");
                }
                node->left = node_stack.top();
                node_stack.pop();
                node->right = node_stack.top();
                node_stack.pop();
            }

            node_stack.push(node);
        }

        if (node_stack.size() != 1) {
            throw runtime_error("Invalid expression format");
        }

        root = node_stack.top();
    } catch (const exception& e) {
        // Clean up any allocated nodes before re-throwing
        while (!node_stack.empty()) {
            delete node_stack.top();
            node_stack.pop();
        }
        throw;
    }

    return root;
}

/**
 * @brief Helper function to evaluate a subtree and replace it with a value node
 * @param node Pointer to the root of the subtree to evaluate
 */
void evaluate_and_replace(TreeNode* node) {
    if (!node || !is_operation(node->value)) return;

    // First process children recursively
    evaluate_and_replace(node->left);
    evaluate_and_replace(node->right);

    if (node->value == -6) {  // Exponentiation operation
        if (!node->left || !node->right) {
            throw runtime_error("Invalid exponentiation operation");
        }

        int base = node->left->value;
        int exponent = node->right->value;
        int result = static_cast<int>(pow(base, exponent));

        // Replace this operation node with a value node
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
