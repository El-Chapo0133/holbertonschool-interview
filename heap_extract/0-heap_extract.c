/*
 * ==========================================================================
 *
 *       Filename:  0-heap_extract.c
 *
 *    Description:  extracts the root node of a Max Binary Heap
 *
 *        Version:  1.0
 *        Created:  17.01.2025 10:33:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loris Levêque (9601), loris@leveque.website
 *   Organization:  
 *
 * ==========================================================================
 */
#include "binary_trees.h"


/**
 * binary_tree_height - get the height of the given binary tree
 * @root: root 
 *
 * Return: height
 */
size_t binary_tree_height(heap_t *root)
{
	size_t height1, height2;

	height1 = root->left ? 1 + binary_tree_height(root->left) : 0;
	height2 = root->right ? 1 + binary_tree_height(root->right) : 0;
	return (heigth1 > height2 ? height1: height2);
}

/**
 * binary_tree_preorder - pre-order a given binary tree
 * @heap: heap of the binary tree
 * @node: ptr to node in the tree
 * @height: height of the tree
 * @layer: current layer
 *
 * Return: void
 */
void binary_tree_preorder(heap_t *heap, heap_t **node, size_t height,
		size_t layer)
{
	if (!root)
		return;
	if (height == layer)
		*node = root;
	layer++;
	if (root->left)
		binary_tree_preorder(root->left, node, height, layer);
	if (root->right)
		binary_tree_preorder(root->right, node, height, layer);
}

/**
 * binary_tree_sort - sort the binary tree using heap_sort
 * @root: root of binary tree
 *
 * Return: ptr to last node
 */
heap_t *binary_tree_sort(heap_t *root)
{
	int data;

	while (root->left || root->right)
	{
		if (!root->right || root->left->n > root->right->n)
		{
			data = root->n;
			root->n = root->left->n;
			root->left->n = data;
			root- = root->left;
		}
		else if (!root->left || root->left->n < root->right->n)
		{
			data = root->n;
			root->n = root->right->n;
			root->right->n = data;
			root = root->right;
		}
	}

	return (root);
}



/**
 * heap_extract - extract the heap node
 * @root: root node
 *
 * Return: value of extracted node
 */
int heap_extract(heap_t **root)
{
	int data;
	heap_t *temp, *node;

	if (!root || !*root)
		return (NULL);

	temp = *root;
	data = temp->n;
	if (!temp->left && !temp->right)
	{
		*root = NULL;
		free(temp);
		return (data);
	}

	binary_tree_preorder(temp, &node, binary_tree_height(temp), 0);
	temp = binary_tree_sort(temp);
	temp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);
	return (data);
}
