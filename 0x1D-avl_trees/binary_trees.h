#ifndef _BINARY_TREES_
#define _BINARY_TREES_

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <limits.h>

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
typedef struct binary_tree_s avl_t;

size_t get_height(const binary_tree_t *tree);
size_t rec_is_avl(const binary_tree_t *tree, int max, int min);
int binary_tree_is_avl(const binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif
