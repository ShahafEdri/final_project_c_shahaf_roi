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
#include "Header.h"
#include "user_binary_tree.h"

/*create a new node*/
userTree* user_create_node(userTree* parent, user info)
{
	userTree* node = (userTree*)malloc(sizeof(userTree));
	if (!node)
	{
		printf("Not enough system memory is available for allocation!\n");
		exit(1);
	}
	node->info = info;
	node->parent = parent;
	node->left = node->right = NULL;
	return node;
}

/*insert a new node into the BST using iterative method*/
void user_insert_iterative(userTree** root, user info)
{
	//int data = user_data.id;
	if (!(*root))
	{
		*root = user_create_node(NULL, info);
	}
	else
	{
		userTree* cursor = *root;

		while (1)
		{
			if (isNegative(strcmp(info.username, cursor->info.username)))
			{
				if (cursor->left)
					cursor = cursor->left;
				else
				{
					cursor->left = user_create_node(cursor, info);
					return;
				}
			}
			else if (isPositive(strcmp(info.username, cursor->info.username)))
			{
				if (cursor->right)
					cursor = cursor->right;
				else
				{
					cursor->right = user_create_node(cursor, info);
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
void user_insert_recursive(userTree** root, userTree* parent, user info)
{
	if (!(*root))
	{
		userTree* temp = user_create_node(parent, info);
		*root = temp;
		return;
	}

	if (isNegative(strcmp(info.username, (*root)->info.username)))
	{
		user_insert_recursive(&(*root)->left, *root, info);
	}
	else if (isPositive(strcmp(info.username, (*root)->info.username)))
	{
		user_insert_recursive(&(*root)->right, *root, info);
	}
}

void user_print_preorder(userTree* root)
{
	if (root)
	{
		printf("%s ", root->info.username);
		user_print_preorder(root->left);
		user_print_preorder(root->right);
	}

}

void user_print_inorder(userTree* root)
{
	if (root)
	{
		user_print_inorder(root->left);
		user_print_all_user_info(&(root->info), false);
		//printf("%s ", root->info.username);
		user_print_inorder(root->right);
	}
}

void user_print_postorder(userTree* root)
{
	if (root)
	{
		user_print_postorder(root->left);
		user_print_postorder(root->right);
		printf("%s ", root->info.username);
	}
}

void user_print_all_user_info(user* member, bool showHeader) {
	if (showHeader) {
		printf("%-15s%-15s%-20s%-10s\n",
			"USERNAME",
			"PASSWORD",
			"FULLNAME",
			"LEVEL");
	}
	printf("%-15s%-15s%-20s%-10d\n",
		member->username,
		member->password,
		member->fullname,
		member->level);
}

void user_deltree(userTree** root)
{
	if (*root)
	{
		user_deltree(&((*root)->left));
		user_deltree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

userTree* user_searchByBST(userTree* root, user info)
{
	if (!root)
		return NULL;

	if (isNegative(strcmp(info.username, (root)->info.username)))
	{
		user_searchByBST(root->left, info);
	}
	else if (isPositive(strcmp(info.username, (root)->info.username)))
	{
		user_searchByBST(root->right, info);
	}
	else //if (isZero(strcmp(info.username, (root)->info.username)))
	{
		return root;
	}
}


userTree* user_min_value(userTree* node, int* height)
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

userTree* user_max_value(userTree* node, int* height)
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
userTree* user_delete_node(userTree* root, user info)
{
	if (!root)
		return NULL;

	if (isNegative(strcmp(info.username, (root)->info.username)))
		root->left = user_delete_node(root->left, info);
	else if (isPositive(strcmp(info.username, (root)->info.username)))
		root->right = user_delete_node(root->right, info);
	else
	{
		userTree* cursor = NULL;

		if ((root->left) && (root->right)) //2 children
		{
			int left, right;
			userTree* parent = NULL;
			userTree* cursorLeft = user_min_value(root->right, &left);
			userTree* cursorRight = user_max_value(root->left, &right);

			cursor = (left > right) ? cursorLeft : cursorRight;
			parent = cursor->parent;
			root->info = cursor->info;

			if (parent->left == cursor)
				parent->left = user_delete_node(parent->left, cursor->info);
			else
				parent->right = user_delete_node(parent->right, cursor->info);
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
void user_print_tree(userTree* root, int space)
{
	int i;

	// Base case
	if (!root)
		return;

	// Process right child first
	user_print_tree(root->right, space + COUNT);

	// Print current node after space
	// count
	printf("\n");
	for (i = 0; i < space; i++)
		printf(" ");
	printf("%s\n", root->info.username);

	// Process left child
	user_print_tree(root->left, space + COUNT);
}

void user_save_tree_to_file(userTree* root, FILE* wfPtr) {
	if (root) {
		user_save_tree_to_file(root->left, wfPtr);
		fwrite(&root->info, sizeof(struct user), 1, wfPtr);
		LOG_VAR(DEBUG, "worker %s saved to workers file", root->info.fullname);
		printf("\tworker -> '%s' has been SAVED to workers-file\n", root->info.username);
		user_save_tree_to_file(root->right, wfPtr);
	}
}
