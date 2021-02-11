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
userTree* user_create_node(userTree* parent, user data)
{
	userTree* node = (userTree*)malloc(sizeof(userTree));
	if (!node)
	{
		printf("Not enough system memory is available for allocation!\n");
		exit(1);
	}
	node->data = data;
	node->parent = parent;
	node->left = node->right = NULL;
	return node;
}

/*insert a new node into the BST using iterative method*/
void user_insert_iterative(userTree** root, user data)
{
	//int data = user_data.id;
	if (!(*root))
	{
		*root = user_create_node(NULL, data);
	}
	else
	{
		userTree* cursor = *root;

		while (1)
		{
			if (isNegative(strcmp(data.username, cursor->data.username)))
			{
				if (cursor->left)
					cursor = cursor->left;
				else
				{
					cursor->left = user_create_node(cursor, data);
					return;
				}
			}
			else if (isNegative(strcmp(data.username, cursor->data.username)))
			{
				if (cursor->right)
					cursor = cursor->right;
				else
				{
					cursor->right = user_create_node(cursor, data);
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
void user_insert_recursive(userTree** root, userTree* parent, user data)
{
	if (!(*root))
	{
		userTree* temp = user_create_node(parent, data);
		*root = temp;
		return;
	}

	if (isNegative(strcmp(data.username, (*root)->data.username)))
	{
		user_insert_recursive(&(*root)->left, *root, data);
	}
	else if (isPositive(strcmp(data.username, (*root)->data.username)))
	{
		user_insert_recursive(&(*root)->right, *root, data);
	}
}

void user_print_preorder(userTree* root)
{
	if (root)
	{
		printf("%s ", root->data.username);
		user_print_preorder(root->left);
		user_print_preorder(root->right);
	}

}

void user_print_inorder(userTree* root)
{
	if (root)
	{
		user_print_inorder(root->left);
		printf("%s ", root->data.username);
		user_print_inorder(root->right);
	}
}

void user_print_postorder(userTree* root)
{
	if (root)
	{
		user_print_postorder(root->left);
		user_print_postorder(root->right);
		printf("%s ", root->data.username);
	}
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

userTree* user_search(userTree* root, user data)
{
	if (!root)
		return NULL;

	if (isNegative(strcmp(data.username, (root)->data.username)))
	{
		user_search(root->left, data);
	}
	else if (isPositive(strcmp(data.username, (root)->data.username)))
	{
		user_search(root->right, data);
	}
	else if (isZero(strcmp(data.username, (root)->data.username)))
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
userTree* user_delete_node(userTree* root, user data)
{
	if (!root)
		return NULL;

	if (isNegative(strcmp(data.username, (root)->data.username)))
		root->left = user_delete_node(root->left, data);
	else if (isPositive(strcmp(data.username, (root)->data.username)))
		root->right = user_delete_node(root->right, data);
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
			root->data = cursor->data;

			if (parent->left == cursor)
				parent->left = user_delete_node(parent->left, cursor->data);
			else
				parent->right = user_delete_node(parent->right, cursor->data);
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
	printf("%s\n", root->data.username);

	// Process left child
	user_print_tree(root->left, space + COUNT);
}

void user_save_tree_to_file(userTree* root, FILE* wfPtr) {
	if (root) {
		user_save_tree_to_file(root->left, wfPtr);
		fwrite(&root->data, sizeof(struct user), 1, wfPtr);
		LOG_VAR(DEBUG, "worker %s saved to workers file", root->data.username);
		printf("worker '%s' has been SAVED to workers-file", root->data.username);
		user_save_tree_to_file(root->right, wfPtr);
	}
}


//void main()
//{
//	int num;
//	tree *temp = NULL;
//	tree *root = NULL;
//	
//	/* Inserting nodes into tree */
//	//insert_recursive(&root, NULL , 9);
//	//insert_recursive(&root, NULL , 4);
//	//insert_recursive(&root, NULL, 15);
//	//insert_recursive(&root, NULL, 6);
//	//insert_recursive(&root, NULL, 12);
//	//insert_recursive(&root, NULL, 17);
//	//insert_recursive(&root, NULL, 2);
//
//	insert_iterative(&root, 5);
//	insert_iterative(&root, 3);
//	insert_iterative(&root, 7);
//	insert_iterative(&root, 15);
//	insert_iterative(&root, 6);
//	insert_iterative(&root, 12);
//	insert_iterative(&root, 17);
//	insert_iterative(&root, 2);
//	insert_iterative(&root, 0);
//
//	print_tree(root,0);
//
//	/* Printing nodes of tree */
//	printf("Pre Order Display:  ");	print_preorder(root);	printf("\n\n");
//	printf("In Order Display:   ");	print_inorder(root);	printf("\n\n");
//	printf("Post Order Display: ");	print_postorder(root);	printf("\n\n");
//
//	/* Delete node in tree */	
//	printf("Value to delete in tree: ");
//	scanf("%d",&num);
//	printf("\n");
//
//	root = delete_node(root, num);
//
//	/* Search node into tree */	
//	printf("Value to search in tree: ");
//	scanf("%d",&num);
//	printf("\n");
//
//	temp = search(root, num);
//	if (temp)
//	{
//		printf("Data found in tree: \n");
//		printf("Node: %d\n", temp->data);
//		
//		if (temp->parent)	{ printf("Parent: %d\n", temp->parent->data);	} else { printf("Parent: NULL\n");		}
//		if (temp->left)		{ printf("Left Son: %d\n", temp->left->data);	} else { printf("Left Son: NULL\n");	}
//		if (temp->right)	{ printf("Right Son: %d\n", temp->right->data);	} else { printf("Right Son: NULL\n");	}
//	}
//	else
//	{
//		printf("Data Not found in tree.\n");
//	}
//
//	/* Deleting all nodes of tree */
//	deltree(&root);
//}