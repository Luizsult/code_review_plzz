/**
 * @file expression_tree.h
 * @brief Заголовочный файл для операций с деревьями выражений
 * 
 * Этот файл содержит объявление структуры TreeNode и функций
 * для работы с деревьями выражений в префиксной записи.
 */

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

/**
 * @brief Структура, представляющая узел в дереве выражений
 */
struct TreeNode {
    int value;          
    TreeNode* left;     
    TreeNode* right;    

    /**
     * @brief Конструктор для TreeNode
     * @param val Значение для хранения в узле
     */
    explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Читает префиксное выражение из файла и строит дерево выражений
 * @param filename Имя файла, содержащего префиксное выражение
 * @return Указатель на корень построенного дерева
 * @throws std::runtime_error Если файл не может быть открыт или выражение неверно
 */
TreeNode* build_expression_tree(const char* filename);

/**
 * @brief Удаляет операции возведения в степень из дерева, заменяя их вычисленными значениями
 * @param root Указатель на корень дерева для модификации
 */
void remove_exponentiation(TreeNode* root);

/**
 * @brief Удаляет дерево выражений и освобождает память
 * @param root Указатель на корень дерева для удаления
 */
void delete_tree(TreeNode* root);

#endif // EXPRESSION_TREE_H
