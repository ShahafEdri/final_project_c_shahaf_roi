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

typedef struct deviceTree {
	device data;
	struct deviceTree* right, * left, * parent;
}deviceTree;

//typedef tree deviceTree;

/*create a new node*/
deviceTree* device_create_node(deviceTree* parent, device data);

/*insert a new node into the BST using iterative method*/
void device_insert_iterative(deviceTree** root, device data);

/*insert a new node into the BST using recursive method*/
void device_insert_recursive(deviceTree** root, deviceTree* parent, device data);

void device_print_preorder(deviceTree* root);

void device_print_inorder(deviceTree* root);

void device_print_postorder(deviceTree* root);

void device_deltree(deviceTree** root);

deviceTree* device_search(deviceTree* root, device data);

deviceTree* device_min_value(deviceTree* node, int* height);

deviceTree* device_max_value(deviceTree* node, int* height);

/*delete a node in the BST*/
deviceTree* device_delete_node(deviceTree* root, device data);

// Function to print binary tree in 2D
// It does reverse inorder
void device_print_tree(deviceTree* root, int space);

void device_save_tree_to_file(deviceTree* root, FILE* ifPtr);
