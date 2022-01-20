#include "binary_trees.h"
/**
 * heap_extract - extracts the root node:
 * @root: binary tree
 * Return: int
 */
int heap_extract(heap_t **root)
{
heap_t *leaf, *Element;
int rootValue;
	if ((*root) == NULL)
		return (0);
	rootValue = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free((*root));
		*root = NULL;
		return (rootValue);
	}
	leaf = find_leaf((*root));
	if (leaf == NULL)
		return (0);
	Element = (*root);
	if (Element->left)
	{
		Element->left->parent = leaf;
		leaf->left = Element->left;
	}
	if (Element->right)
	{
		Element->right->parent = leaf;
		leaf->right = Element->right;
	}
	if (leaf->parent->left && leaf->parent->left == leaf)
		leaf->parent->left = NULL;
	else if (leaf->parent->right && leaf->parent->right == leaf)
		leaf->parent->right = NULL;
	leaf->parent = Element->parent;
	(*root) = leaf;
	free(Element);
	siftDown(root);
	return (rootValue);
}
/**
 * tree_depth - Calculate the depth of the heap
 * @root: First element in the heap.
 * Return: returns the depth of the heap.
 **/
int tree_depth(heap_t *root)
{
int left = 0;
int right = 0;
if (root == NULL)
return (0);
left = tree_depth(root->left);
right = tree_depth(root->right);
if (left > right)
return (left + 1);
else
return (right + 1);
}

/**
 * find_leaf - Finds last element in the heap.
 * @root: First element in the heap.
 * Return: return the last element.
 **/
heap_t *find_leaf(heap_t *root)
{
if (root == NULL)
return (NULL);
if (!root->right && !root->left)
return (root);
if (tree_depth(root->left) > tree_depth(root->right))
return (find_leaf(root->left));
if (tree_depth(root->right) > tree_depth(root->left))
return (find_leaf(root->right));
return (find_leaf(root->right));
}
/**
 * swap_nodes - Swap elements values
 * @parent: First element for swap
 * @child: Second element for swap
 **/
void swap_nodes(heap_t *parent, heap_t *child)
{
int Element = child->n;
child->n = parent->n;
parent->n = Element;
}
/**
 * siftDown -Repair the heap
 * @parent: First element of the heap
 **/
void siftDown(heap_t **parent)
{
heap_t *target = (*parent);
while ((target->left && target->n < target->left->n) ||
(target->right && target->n < target->right->n))
{
if (target->right && target->left)
target = target->left->n > target->right->n ? target->left : target->right;
if (target->right && target->right->n > target->n)
target = target->right;
else if (target->left && target->left->n > target->n)
target = target->left;
swap_nodes(target->parent, target);
}
}
