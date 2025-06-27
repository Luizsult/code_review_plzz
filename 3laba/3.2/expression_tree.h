/**
 * @file expression_tree.h
 * @brief Header file for expression tree operations
 * 
 * This file contains the declaration of the TreeNode structure and functions
 * for working with prefix expression trees.
 */

#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

/**
 * @brief Structure representing a node in the expression tree
 */
struct TreeNode {
    int value;          ///< Value of the node (operand or encoded operation)
    TreeNode* left;     ///< Pointer to the left child
    TreeNode* right;    ///< Pointer to the right child

    /**
     * @brief Constructor for TreeNode
     * @param val Value to store in the node
     */
    explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Reads a prefix expression from a file and builds an expression tree
 * @param filename Name of the file containing the prefix expression
 * @return Pointer to the root of the built tree
 * @throws std::runtime_error If file cannot be opened or expression is invalid
 */
TreeNode* build_expression_tree(const char* filename);

/**
 * @brief Removes exponentiation operations from the tree by replacing them with their computed values
 * @param root Pointer to the root of the tree to modify
 */
void remove_exponentiation(TreeNode* root);

/**
 * @brief Deletes the expression tree and frees memory
 * @param root Pointer to the root of the tree to delete
 */
void delete_tree(TreeNode* root);

#endif // EXPRESSION_TREE_H
