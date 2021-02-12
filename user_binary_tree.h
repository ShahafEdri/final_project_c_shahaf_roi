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

#define isNegative(X) 0 > X
#define isPositive(X) 0 < X
#define isZero(X) 0 == X


typedef struct userTree {
	user info;
	struct userTree* right, * left, * parent;
}userTree;

//typedef userTree userTree;

/*create a new node*/
userTree* user_create_node(userTree* parent, user info);

/*insert a new node into the BST using iterative method*/
void user_insert_iterative(userTree** root, user info);

/*insert a new node into the BST using recursive method*/
void user_insert_recursive(userTree** root, userTree* parent, user info);

void user_print_preorder(userTree* root);

void user_print_inorder(userTree* root);

void user_print_postorder(userTree* root);

void user_deltree(userTree** root);

userTree* user_search(userTree* root, user info);

userTree* user_min_value(userTree* node, int* height);

userTree* user_max_value(userTree* node, int* height);

/*delete a node in the BST*/
userTree* user_delete_node(userTree* root, user info);

// Function to print binary tree in 2D
// It does reverse inorder
void user_print_tree(userTree* root, int space);

void user_save_tree_to_file(userTree* root, FILE* wfPtr);