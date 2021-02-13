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

void add_device(deviceTree* deviceRoot)
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


void update_device(deviceTree* deviceRoot) {
	deviceTree* Node = (deviceTree*)malloc(sizeof(deviceTree));
	printf("what is the serial-number of the prodect you want to change? --> ");
	scanf_s("%d", Node->item.sn);
	Node = device_search(deviceRoot, Node->item);
	printf(ITEM_PARAMETERS);
	device_print_items(&Node->item);
	int change_option;
	printf("what what would you like to change in the product (by number)? --> ");
	scanf_s("%d", &change_option);
	switch (change_option)
	{
	case(1): // serial number
		scanf("%d", Node->item.sn);
		break;
	case(2): // brand
		scanf("%s", Node->item.brand);
		break;
	case(3): // company
		scanf("%s", Node->item.company);
		break;
	case(4): // price
		scanf("%s", Node->item.price);
		break;
	case(5): // stock
		printf("1 for true 0 for false");
		scanf("%d", Node->item.stock);
		break;
	case(6): // date
		scanf("%s", Node->item.date);
		break;
	default:
		printf("no action was picked");
		break;
	}
	prinf("changes made:\n");
	device_print_items(&Node->item);
}

void search_device() {}

void delete_device(deviceTree* deviceRoot) {
	printf("enter serial number of device you want to delete: ");
	device item;
	scanf_s("%d", item.sn);
	if (!device_delete_node(deviceRoot, item))
		printf("device was deleted successfully");
	else
		printf("device could not be found");
	return;
}

void staff_view() {}

void staff_addition() {}

void staff_update() {}

void staff_deletion() {}
