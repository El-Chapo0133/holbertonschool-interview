/*
 * ==========================================================================
 *
 *       Filename:  binary_trees.h
 *
 *    Description:  binary tree header file
 *
 *        Version:  1.0
 *        Created:  17.01.2025 10:33:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */

#ifndef H_BINARY_TREE
#define H_BINARY_TREE

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);

#endif
