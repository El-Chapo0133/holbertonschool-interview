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
 * heapify_from_root - heapify a heap tree from root
 * @heap: heap
 *
 * Return: void
 */
void heapify_from_root(heap_t *heap)
{
	binary_tree_t *node, *child;
	void *temp = NULL;

	node = heap->root;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n < node->right->n ?
				node->left : node->right;
		if (node->n < child->n)
			break;
		temp = node->data;
		node->data = child->data;
		child->data = temp;
		node = child;
	}
}

/**
 * heap_extract - extracts the root value of a Min Binary Heap
 * @heap: heap
 *
 * Return: 0 on failure 1 on success
 */
int *heap_extract(heap_t *heap)
{
	binary_tree_node_t *node;
	size_t bit;
	void *data;

	if (!heap || !heap->root)
		return (NULL);

	data = heap->root->n;
	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size = 0;
		return (data);
	}

	for (bit = 1; bit <= heap->size; bit <<= 1)
		;
	bit >>= 2;
	for (node = heap->root; bit > 0; bit >>= 1)
		node = heap->size & bit ? node->right : node->left;
	heap->root->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	heap->size--;
	free(node);
	heapify_from_root(heap);
	return (data);
}
