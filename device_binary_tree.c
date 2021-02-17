/*
Assigned by:
Shahaf Edri 206328593
*/
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
#include <string.h>
#include <ctype.h>
#include "Header.h"
#include "device_binary_tree.h"

/*create a new node*/
deviceTree* device_create_node(deviceTree* parent, device item)
{
	deviceTree* node = (deviceTree*)malloc(sizeof(deviceTree));
	if (!node)
	{
		printf("Not enough system memory is available for allocation!\n");
		exit(1);
	}
	node->item = item;
	node->parent = parent;
	node->left = node->right = NULL;
	return node;
}

/*insert a new node into the BST using iterative method*/
void device_insert_iterative(deviceTree** root, device item)
{
	//int data = user_data.id;
	if (!(*root))
	{
		*root = device_create_node(NULL, item);
	}
	else
	{
		deviceTree* cursor = *root;

		while (1)
		{
			if (item.sn < cursor->item.sn)
			{
				if (cursor->left)
					cursor = cursor->left;
				else
				{
					cursor->left = device_create_node(cursor, item);
					return;
				}
			}
			else if (item.sn > cursor->item.sn)
			{
				if (cursor->right)
					cursor = cursor->right;
				else
				{
					cursor->right = device_create_node(cursor, item);
					return;
				}
			}
			else //(data == cursor->data)
			{
				return;
			}
		}
	}
}

/*insert a new node into the BST using recursive method*/
void device_insert_recursive(deviceTree** root, deviceTree* parent, device item)
{
	if (!(*root))
	{
		deviceTree* temp = device_create_node(parent, item);
		*root = temp;
		return;
	}

	if (item.sn < (*root)->item.sn)
	{
		device_insert_recursive(&(*root)->left, *root, item);
	}
	else if (item.sn > (*root)->item.sn)
	{
		device_insert_recursive(&(*root)->right, *root, item);
	}
}

void device_print_preorder(deviceTree* root)
{
	if (root)
	{
		printf("%d ", root->item.sn);
		device_print_preorder(root->left);
		device_print_preorder(root->right);
	}

}

void device_print_inorder(deviceTree* root)
{
	if (root)
	{
		device_print_inorder(root->left);
		device_print_all_items(&(root->item), false);
		//printf("%d ", root->item.sn);
		device_print_inorder(root->right);
	}
}

void device_print_postorder(deviceTree* root)
{
	if (root)
	{
		device_print_postorder(root->left);
		device_print_postorder(root->right);
		printf("%d ", root->item.sn);
	}
}

void device_print_all_items(device* item, bool showHeader) {
	if (showHeader) {
		printf("%-15s%-15s%-15s%-10s%-10s%-15s\n",
			"S/N",
			"Brand",
			"Company",
			"Price",
			"Stock?", // if 1 then V else X
			"Date"
		);
	}
	printf("%09d      %-15s%-15s%-10.1f%-10s%-15s\n",
		item->sn,
		item->brand,
		item->company,
		item->price,
		item->stock ? "V" : "X", // if 1 then V else X
		item->date
	);
}

void device_deltree(deviceTree** root)
{
	if (*root)
	{
		device_deltree(&((*root)->left));
		device_deltree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

deviceTree* device_searchByBST(deviceTree* root, int serial)
{
	if (!root)
		return NULL;

	if (serial < root->item.sn)
		device_searchByBST(root->left, serial);
	else if (serial > root->item.sn)
		device_searchByBST(root->right, serial);
	else // if (serial == root->item.sn)
		return root;
}

void searchDeviceBySerialNum(deviceTree* root, int serial, enumSearchTypes searchFlag) { // preorder
	if (!root)
		return;

	switch (searchFlag)
	{
	case(e_equal):
		if (serial == root->item.sn)
			device_print_all_items(&root->item, false);
		break;
	case(e_forward_or_bigger):
		if (serial < root->item.sn)
			device_print_all_items(&root->item, false);
		break;
	case(e_backword_or_smaller):
		if (serial > root->item.sn)
			device_print_all_items(&root->item, false);
		break;
	}
	searchDeviceBySerialNum(root->left, serial, searchFlag);
	searchDeviceBySerialNum(root->right, serial, searchFlag);
}

void searchDeviceByBrand(deviceTree* root, char* brand) { // preorder
	if (!root)
		return;

	if (isZero(strcmp(brand, root->item.brand)))
		device_print_all_items(&root->item, false);
	searchDeviceByBrand(root->left, brand);
	searchDeviceByBrand(root->right, brand);
}


void searchDeviceByCompany(deviceTree* root, char* company) { // preorder
	if (!root)
		return;

	if (isZero(strcmp(company, root->item.company)))
		device_print_all_items(&root->item, false);
	searchDeviceByCompany(root->left, company);
	searchDeviceByCompany(root->right, company);
}


void searchDeviceByPrice(deviceTree* root, float price, enumSearchTypes searchFlag) { // preorder
	if (!root)
		return;

	switch (searchFlag)
	{
	case(e_equal):
		if (price == root->item.price)
			device_print_all_items(&root->item, false);
		break;
	case(e_forward_or_bigger):
		if (price < root->item.price)
			device_print_all_items(&root->item, false);
		break;
	case(e_backword_or_smaller):
		if (price > root->item.price)
			device_print_all_items(&root->item, false);
		break;
	}
	searchDeviceByPrice(root->left, price, searchFlag);
	searchDeviceByPrice(root->right, price, searchFlag);
}


void searchByStock(deviceTree* root, bool isInStock) { // preorder
	if (!root)
		return;

	if (isInStock == root->item.stock)
		device_print_all_items(&root->item, false);
	searchByStock(root->left, isInStock);
	searchByStock(root->right, isInStock);
}

int* parseDateStrToDateInt(char* date) {
	int* date_int = (int*)malloc(sizeof(int) * 3);
	date_int[e_day] = 0;
	date_int[e_month] = 0;
	date_int[e_year] = 0;

	if (isdigit(date[0])) date_int[e_day] += (date[0] - '0') * 10;
	if (isdigit(date[1])) date_int[e_day] += (date[1] - '0');
	// date[2] = '-'
	if (isdigit(date[3])) date_int[e_month] += (date[3] - '0') * 10;
	if (isdigit(date[4])) date_int[e_month] += (date[4] - '0');
	// date[5] = '-'
	if (isdigit(date[6])) date_int[e_year] += (date[6] - '0') * 1000;
	if (isdigit(date[7])) date_int[e_year] += (date[7] - '0') * 100;
	if (isdigit(date[8])) date_int[e_year] += (date[8] - '0') * 10;
	if (isdigit(date[9])) date_int[e_year] += (date[9] - '0');
	return date_int;
}

void searchByDate(deviceTree* root, char* dateStr, enumSearchTypes searchFlag) {
	if (!root)
		return;

	int* targetDate;
	targetDate = parseDateStrToDateInt(dateStr);
	int* root_date;
	root_date = parseDateStrToDateInt(root->item.date);
	bool correctRootDateFlag = true;
	switch (searchFlag) {
	case(e_equal):
		for (int dateCode = e_year; (dateCode >= e_day) && (correctRootDateFlag == true); dateCode--)
			if (targetDate[dateCode] == root_date[dateCode])
				correctRootDateFlag = false;
		break;
	case(e_forward_or_bigger):
		for (int dateCode = e_year; (dateCode >= e_day) && (correctRootDateFlag == true); dateCode--)
			if (targetDate[dateCode] < root_date[dateCode])
				break;
			else if (targetDate[dateCode] > root_date[dateCode])
				correctRootDateFlag = false;
		break;//    20-01-2017            13-01-2018
	case(e_backword_or_smaller):
		for (int dateCode = e_year; (dateCode >= e_day) && (correctRootDateFlag == true); dateCode--)
			if (targetDate[dateCode] > root_date[dateCode])
				break;
			else if (targetDate[dateCode] < root_date[dateCode])
				correctRootDateFlag = false;
		break;
	}
	if (correctRootDateFlag)
		device_print_all_items(&root->item, false);
	searchByDate(root->left, dateStr, searchFlag);
	searchByDate(root->right, dateStr, searchFlag);
}


deviceTree* device_min_value(deviceTree* node, int* height)
{
	*height = 0;

	/* loop down to find the leftmost leaf */
	while (node->left != NULL)
	{
		node = node->left;
		(*height)++;
	}

	return node;
}

deviceTree* device_max_value(deviceTree* node, int* height)
{
	*height = 0;

	/* loop down to find the rightmost leaf */
	while (node->right != NULL)
	{
		node = node->right;
		(*height)++;
	}

	return node;
}

/*delete a node in the BST*/
deviceTree* device_delete_node(deviceTree* root, device item)
{
	if (!root)
		return NULL;

	if (item.sn < root->item.sn)
		root->left = device_delete_node(root->left, item);
	else if (item.sn > root->item.sn)
		root->right = device_delete_node(root->right, item);
	else
	{
		deviceTree* cursor = NULL;

		if ((root->left) && (root->right)) //2 children
		{
			int left, right;
			deviceTree* parent = NULL;
			deviceTree* cursorLeft = device_min_value(root->right, &left);
			deviceTree* cursorRight = device_max_value(root->left, &right);

			cursor = (left > right) ? cursorLeft : cursorRight;
			parent = cursor->parent;
			root->item = cursor->item;

			if (parent->left == cursor)
				parent->left = device_delete_node(parent->left, cursor->item);
			else
				parent->right = device_delete_node(parent->right, cursor->item);
		}
		else
		{
			if (root->left)	//only left child
			{
				cursor = root->left;
				cursor->parent = root->parent;
			}
			else if (root->right) //only right child
			{
				cursor = root->right;
				cursor->parent = root->parent;
			}
			free(root);
			root = cursor;
		}
	}
	return root;
}

// Function to print binary tree in 2D
// It does reverse inorder
void device_print_tree(deviceTree* root, int space)
{
	int i;

	// Base case
	if (!root)
		return;

	// Process right child first
	device_print_tree(root->right, space + COUNT);

	// Print current node after space
	// count
	printf("\n");
	for (i = 0; i < space; i++)
		printf(" ");
	printf("%d\n", root->item.sn);

	// Process left child
	device_print_tree(root->left, space + COUNT);
}

void device_save_tree_to_file(deviceTree* root, FILE* ifPtr) {
	if (root) {
		device_save_tree_to_file(root->left, ifPtr);
		fwrite(&root->item, sizeof(struct device), 1, ifPtr);
		LOG_VAR(DEBUG, "worker %d saved to items file", root->item.sn);
		printf("\titem (SN) -> '%d' has been SAVED to items-file\n", root->item.sn);
		device_save_tree_to_file(root->right, ifPtr);
	}
}
