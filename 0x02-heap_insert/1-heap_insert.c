#include "binary_trees.h"
/**
 * heap_insert_aux - inserts a value into a max binary heap
 * @root: double pointer to the root node of The Heap
 * @value: value stored in the inserted node 
 *
 * Return: pointer to the inserted node on success, null on failure
 */

heap_t *heap_insert_aux(heap_t **root, int value, int lvl, int max)
{
	heap_t *new, *head;

	head = *root;
	if (lvl == max) {
		while (head->parent !=NULL) {
			head = head->parent;
		}
		new = heap_insert_aux(&head->right, value, lvl + 1, max);
		return (new);
	}
	if (head->left == NULL) {
		new = malloc(sizeof(heap_t));
		if (new == NULL) {
			return (NULL);
		}
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		head->left = new;
		new->parent = head;
		while (head != NULL && new->n > head->n) {
			value = head->n;
			head->n = new->n;
			new = head;
			head = head->parent;
		}
	} else if (head->right == NULL) {
		new = malloc(sizeof(heap_t));
		if (new == NULL) {
			return (NULL);
		}
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		head->right = new;
		new->parent = head;
		while (head != NULL && new->n > head->n) {
			value = head->n;
			head->n = new->n;
			new->n = value;
			new = head;
			head = head->parent;
		}
		} else {
			new = heap_insert_aux(&head->left, value, lvl + 1, max);
		}
		return (new);
}

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *head;
	int max = 0;

	if (*root == NULL) {
		new = malloc(sizeof(heap_t));
		if (new == NULL) {
			return (NULL);
		}
		new->right = NULL;
		new->left = NULL;
		new->n = value;
		*root = new;
		return (*root);
	}
	head = *root;

	while (head->right != NULL) {
		head = head->right;
		max++;
	}
	head = *root;
	new = heap_insert_aux(root, value, 0, max + 1);
	return (new);
}
