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
#include "binary_tree.h"

/*create a new node*/
tree* create_node(tree* parent, tree_type data)
{
	tree* node = (tree*)malloc(sizeof(tree));
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
void insert_iterative(tree** root, tree_type data)
{
	//int data = user_data.id;
	if (!(*root))
	{
		*root = create_node(NULL, data);
	}
	else
	{
		tree* cursor = *root;

		while (1)
		{
			if (isNegative(strcmp(data.username, cursor->data.username)))
			{
				if (cursor->left)
					cursor = cursor->left;
				else
				{
					cursor->left = create_node(cursor, data);
					return;
				}
			}
			else if (isNegative(strcmp(data.username, cursor->data.username)))
			{
				if (cursor->right)
					cursor = cursor->right;
				else
				{
					cursor->right = create_node(cursor, data);
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
void insert_recursive(tree** root, tree* parent, tree_type data)
{
	if (!(*root))
	{
		tree* temp = create_node(parent, data);
		*root = temp;
		return;
	}

	if (isNegative(strcmp(data.username, (*root)->data.username)))
	{
		insert_recursive(&(*root)->left, *root, data);
	}
	else if (isPositive(strcmp(data.username, (*root)->data.username)))
	{
		insert_recursive(&(*root)->right, *root, data);
	}
}

void print_preorder(tree* root)
{
	if (root)
	{
		printf("%d ", root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}

}

void print_inorder(tree* root)
{
	if (root)
	{
		print_inorder(root->left);
		printf("%d ", root->data);
		print_inorder(root->right);
	}
}

void print_postorder(tree* root)
{
	if (root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d ", root->data);
	}
}

void deltree(tree** root)
{
	if (*root)
	{
		deltree(&((*root)->left));
		deltree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}

tree* search(tree* root, tree_type data)
{
	if (!root)
		return NULL;

	if (isNegative(strcmp(data.username, (root)->data.username)))
	{
		search(root->left, data);
	}
	else if (isPositive(strcmp(data.username, (root)->data.username)))
	{
		search(root->right, data);
	}
	else if (isZero(strcmp(data.username, (root)->data.username)))
	{
		return root;
	}
}

tree* min_value(tree* node, int* height)
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

tree* max_value(tree* node, int* height)
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
tree* delete_node(tree* root, tree_type data)
{
	if (!root)
		return NULL;

	if (data.id < root->data.id)
		root->left = delete_node(root->left, data);
	else if (data.id > root->data.id)
		root->right = delete_node(root->right, data);
	else
	{
		tree* cursor = NULL;

		if ((root->left) && (root->right)) //2 children
		{
			int left, right;
			tree* parent = NULL;
			tree* cursorLeft = min_value(root->right, &left);
			tree* cursorRight = max_value(root->left, &right);

			cursor = (left > right) ? cursorLeft : cursorRight;
			parent = cursor->parent;
			root->data = cursor->data;

			if (parent->left == cursor)
				parent->left = delete_node(parent->left, cursor->data);
			else
				parent->right = delete_node(parent->right, cursor->data);
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
void print_tree(tree* root, int space)
{
	int i;

	// Base case
	if (!root)
		return;

	// Process right child first
	print_tree(root->right, space + COUNT);

	// Print current node after space
	// count
	printf("\n");
	for (i = 0; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	print_tree(root->left, space + COUNT);
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