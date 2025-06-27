/**
 * @file main.cpp
 * @brief Main program for expression tree processing
 * 
 * This file contains the main function that demonstrates the expression tree operations.
 */

#include "expression_tree.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    try {
        TreeNode* root = build_expression_tree(argv[1]);
        remove_exponentiation(root);

        // Here you can use the modified tree as needed
        cout << "Expression tree processed successfully." << endl;

        delete_tree(root);
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
