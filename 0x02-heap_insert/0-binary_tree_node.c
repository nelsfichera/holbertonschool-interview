#include "binary_trees.h"

/**
* binary_tree_node - creates node on binary tree
* @parent: pointer to parent of the node to be created
* @value: the value to assign to the new node
* Return: returns pointer on success, null on failure
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new;

    new = malloc(sizeof(binary_tree_t));
    if (new == NULL) {
        return (NULL);
    }
    if (parent == NULL) {
        new->parent = NULL;
    }
    else {
        new->parent = NULL;
    }
    new->right = NULL;
    new->left = NULL;
    new->n = value;
    return(new);
}
