#include "binary_trees.h"
/**
 *
 *@parent is a pointer to the parent node of the node to create
 *
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