#pragma once
/************************************************************************
*	C Binary-Search-Tree (or BST in short)								*
*	with left, right & parent pointers									*
*																		*
*   Implemention include:												*
*		a. Insert (iterative & recursive)								*
*		b. Search														*
*		c. Get min & max value											*
*		c. Delete node (with best successor selection)					*
*		d. Preorder, Inorder, Postorder prints							*
*		e. 2D tree print												*
*		f. Delete tree													*
*																		*
*	The code was written by Shimon Aviram,								*
*	Based on the following references:									*
*	https://www.thegeekstuff.com/2013/02/c-binary-tree/					*
*	http://www.zentut.com/c-tutorial/c-binary-search-tree/				*
*	https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/		*
************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include "Header.h"

#define COUNT 10

typedef user tree_type;

typedef struct tree {
	tree_type data;
	struct tree* right, * left, * parent;
}tree;

/*create a new node*/
tree* create_node(tree* parent, tree_type data);

/*insert a new node into the BST using iterative method*/
void insert_iterative(tree** root, tree_type data);

/*insert a new node into the BST using recursive method*/
void insert_recursive(tree** root, tree* parent, tree_type data);

void print_preorder(tree* root);

void print_inorder(tree* root);

void print_postorder(tree* root);

void deltree(tree** root);

tree* search(tree* root, tree_type data);

tree* min_value(tree* node, int* height);

/*delete a node in the BST*/
tree* delete_node(tree* root, tree_type data);

// Function to print binary tree in 2D
// It does reverse inorder
void print_tree(tree* root, int space);
