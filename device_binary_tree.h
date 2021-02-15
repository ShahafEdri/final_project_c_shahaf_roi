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
#include <stdbool.h>
#include "Header.h"

#define COUNT 10

typedef struct deviceTree {
	device item;
	struct deviceTree* right, * left, * parent;
}deviceTree;



/*create a new node*/
deviceTree* device_create_node(deviceTree* parent, device item);

/*insert a new node into the BST using iterative method*/
void device_insert_iterative(deviceTree** root, device item);

/*insert a new node into the BST using recursive method*/
void device_insert_recursive(deviceTree** root, deviceTree* parent, device item);

void device_print_preorder(deviceTree* root);

void device_print_inorder(deviceTree* root);

void device_print_postorder(deviceTree* root);

void device_print_all_items(device* root);

void device_deltree(deviceTree** root);

deviceTree* device_searchByBST(deviceTree* root, int serial);

void searchDeviceBySerialNum(deviceTree* root, int serial, enumSearchTypes searchFlag);

void searchDeviceByBrand(deviceTree* root, char* brand);

void searchDeviceByCompany(deviceTree* root, char* company);

void searchDeviceByPrice(deviceTree* root, float price, enumSearchTypes searchFlag);

void searchByStock(deviceTree* root, bool isInStock);

void searchByDate(deviceTree* root, char* date, enumSearchTypes searchFlag);

deviceTree* device_min_value(deviceTree* node, int* height);

deviceTree* device_max_value(deviceTree* node, int* height);

/*delete a node in the BST*/
deviceTree* device_delete_node(deviceTree* root, device item);

// Function to print binary tree in 2D
// It does reverse inorder
void device_print_tree(deviceTree* root, int space);

void device_save_tree_to_file(deviceTree* root, FILE* ifPtr);
