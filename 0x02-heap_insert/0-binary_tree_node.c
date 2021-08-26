#include "binary_trees.h"
/**
 * binary_tree_node- a function that creates a binary tree node
 *@value:  node to create value
 *@parent: is a pointer to the parent node of the node to create
 *Return: binary_tree_t
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = malloc(sizeof(binary_tree_t));
if (node == NULL)
{
return (0);
}
node->parent = parent;
node->n = value;
return (node);
}
