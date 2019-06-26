#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
} tree;

tree * createTree()
{
	tree *t;
	t = (tree *) malloc(sizeof(tree));
	t->data = -1;
	t->left = NULL;
	t->right = NULL;
	return t;
}