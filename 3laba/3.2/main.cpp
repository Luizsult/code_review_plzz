/**
 * @file main.cpp
 * @brief Главная программа для обработки дерева выражений
 * 
 * Этот файл содержит главную функцию, демонстрирующую операции с деревом выражений.
 */

#include "expression_tree.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Использование: " << argv[0] << " <имя_файла>" << endl;
        return 1;
    }

    try {
        TreeNode* root = build_expression_tree(argv[1]);
        remove_exponentiation(root);

        cout << "Дерево выражений успешно обработано." << endl;

        delete_tree(root);
    } catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
