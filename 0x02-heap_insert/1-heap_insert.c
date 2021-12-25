#include "binary_trees.h"
/**
 * heap_complete_aux - gets the height of the left most branch
 * @node: the root node of the tree to find the height
 * Return: height of binary if complete, 0 on failure
 */

int heap_complete_aux(heap_t *node)
{
	int height = 0;

	while (node)
	{
		height++;
		node = node->left;
	}
	return (height);
}

/**
 * heap_to_array - Arranges nodes of a binary tree in an array
 * @node: A binary tree (root) node
 * @array: The array in which to place pointers to the nodes
 * @index: The index of the current node
 */
void heap_to_array(heap_t *node, heap_t **array, int index)
{
	int index_left = index * 2 + 1;
	int index_right = index * 2 + 2;

	if (!node)
		return;
	array[index] = node;
	heap_to_array(node->left, array, index_left);
	heap_to_array(node->right, array, index_right);
}
/**
 * heap_insert - Insert a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *insert = NULL, *parent = NULL;
	heap_t **node_array = NULL;
	int height = 0, max = 0, scout = 0;

	if (!root)
		return (NULL);
	if (!*root)
	{
		insert = binary_tree_node(*root, value);
		*root = insert;
		return (insert);
	}
	height = heap_complete_aux(*root);
	max = (1 << height) - 1;
	node_array = (heap_t **)calloc(max, sizeof(heap_t *));
	if (!node_array)
		return (NULL);
	heap_to_array(*root, node_array, 0);
	for (; scout < max && node_array[scout]; scout++)
		scout += 0;

	parent = node_array[(scout - (2 - scout % 2)) /2];
	insert = binary_tree_node(parent, value);
	if (!insert)
		return (NULL);
	if (scout % 2)
		parent->left = insert;
	else
		parent->right = insert;
	while (parent && value >= parent->n)
	{
		insert->n = parent->n;
		parent->n = value;
		insert = parent;
		parent = parent->parent;
	}
	return (insert);
}
