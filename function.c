#include<stdio.h>
#include "device_binary_tree.h"
#include "user_binary_tree.h"
#include "function.h"

//void view_device(deviceTree* root)
//{
//	device_print_inorder(root);
//}
//
//struct deviceTree* add_device(deviceTree* root)
//{
//	deviceTree temp;
//	printf("Please enter the device details in the following order : SN  price  brand  company");
//	scanf_s("%d %d %d %d", &temp.data.sn, &temp.data.price, &temp.data.brand, &temp.data.company);
//	device_insert_iterative(root, temp.data.sn);
//	device_insert_iterative(root, temp.data.price);
//	device_insert_iterative(root, temp.data.company);
//	device_insert_iterative(root, temp.data.brand);
//	return deviceTree;
//}
//
//struct deviceTree* delete_device(deviceTree* root)
//{
//	deviceTree temp;
//	printf("Please enter the SN of the device you want to delete");
//	scanf_s("%d", &temp);
//	device_delete_node(device_root, temp)
//}
//struct deviceTree* update_device(deviceTree* root)
//{
//	deviceTree Oldval, Newval;
//	printf("please enter the SN of the device you want to change");
//	scanf("%d", &Oldval);
//	//  First delete old key value 
//	root = delete_node(root, Oldval);
//	printf("please enter the new SN of the new device");
//	scanf("%d", &Newval);
//	// Then insert new key value 
//	root = insert_iterative(root, Newval);
//	// Return new root 
//	return root;
//}
//void search_device(tree* device_root, device)
//{
//	//TBD
//}
//void staff_view(struct node* staff_root)
//{
//	print_inorder(tree * staff_root);
//}
//void staff_addition_func(struct node* staff_root, device)
//{
//	insert_iterative(staff_root, device);
//	return node;
//}

void insertNewItem(deviceTree* deviceRoot)
{
	device item;
	printf("enter item serial number:\n");
	scanf_s("%3d", &item.sn);
	if (device_search(deviceRoot, item)) {
		printf("this code is already taken\n");
		LOG(ERROR, "tried to input serial number %d but it is already taken");
		return;
	}
	printf("enter item brand:\n");
	scanf_s("%14s", item.brand, TEXT_LEN);
	printf("enter item company:\n");
	scanf_s("%14s", item.company, TEXT_LEN);
	printf("enter item price:\n");
	scanf_s("%f", &item.price);
	printf("enter item date dd-mm-yyyy:\n");
	scanf_s("%14s", &item.date, TEXT_LEN);
	item.stock = true;

	device_insert_iterative(&deviceRoot, item);
}