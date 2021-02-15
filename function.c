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

void view_all_devices(deviceTree* deviceRoot) {
	LOG(INFO, "printing the devices");
	device_print_inorder(deviceRoot);
}

void add_device(deviceTree* deviceRoot)
{
	device item;
	printf("enter item serial number:\n");
	scanf_s("%3d", &item.sn);
	if (device_searchByBST(deviceRoot, item.sn)) {
		printf("this code is already taken\n");
		LOG_VAR(ERROR, "tried to input serial number %d but it is already taken", item.sn);
		return;
	}
	printf("enter item brand: ");
	scanf_s("%14s", item.brand, TEXT_LEN);
	printf("enter item company: ");
	scanf_s("%14s", item.company, TEXT_LEN);
	printf("enter item price: ");
	scanf_s("%f", &item.price);
	printf("enter item date dd-mm-yyyy: ");
	scanf_s("%14s", &item.date, TEXT_LEN);
	item.stock = true;

	device_insert_iterative(&deviceRoot, item);
}


void update_device(deviceTree* deviceRoot) {
	deviceTree* Node = (deviceTree*)malloc(sizeof(deviceTree));
	printf("what is the serial-number of the prodect you want to change? --> ");
	scanf_s("%d", &(Node->item.sn));
	Node = device_searchByBST(deviceRoot, Node->item.sn);
	printf(ITEM_PARAMETERS);
	device_print_all_items(&Node->item);
	int change_option;
	printf("what what would you like to change in the product (by number)? --> ");
	scanf_s("%d", &change_option);
	switch (change_option)
	{
	case(SERIAL_NUM):
		scanf_s("%d", &(Node->item.sn));
		break;
	case(BRAND):
		scanf_s("%s", Node->item.brand, TEXT_LEN);
		break;
	case(COMPANY):
		scanf_s("%s", Node->item.company, TEXT_LEN);
		break;
	case(PRICE):
		scanf_s("%f", &(Node->item.price));
		break;
	case(STOCK):
		printf("1 for true 0 for false");
		scanf_s("%d", &(Node->item.stock));
		break;
	case(DATE):
		scanf_s("%s", Node->item.date, TEXT_LEN);
		break;
	default:
		printf("no action was picked");
		break;
	}
	printf("changes made:\n");
	device_print_all_items(&Node->item);
}

void search_device(deviceTree* deviceRoot) {
	int searchHeader;
	device* item = NULL;
	scanf_s("%d", &searchHeader);
	printf("%-10s%-15s%-15s%-10s%-10s%-15s\n",
		"S/N",
		"Brand",
		"Company",
		"Price",
		"In Stock?", // if 1 then V else X
		"Date"
	);
	switch (searchHeader) {
	case(SERIAL_NUM): {
		int serial;
		scanf_s("%d", &serial);
		enumSearchTypes searchFlag;
		scanf_s("%d", &searchFlag);
		searchDeviceBySerialNum(deviceRoot, serial, searchFlag);
	}break;
	case (BRAND): {
		char brand[TEXT_LEN];
		scanf_s("%s", brand,TEXT_LEN);
		searchDeviceByBrand(deviceRoot, brand);
	}break;
	case(COMPANY): {
		char company[TEXT_LEN];
		scanf_s("%s", company, TEXT_LEN);
		searchDeviceByCompany(deviceRoot, company);
	}break;
	case(PRICE): {
		float price;
		scanf_s("%f", &price);
		enumSearchTypes searchFlag;
		scanf_s("%d", &searchFlag);
		searchDeviceByPrice(deviceRoot, price, searchFlag);
	}break;
	case(STOCK): {
		bool isInStock;
		scanf_s("%d", &isInStock);
		searchByStock(deviceRoot, isInStock); //TODO: Implement function
	}break;
	case(DATE): {
		char date[TEXT_LEN];
		scanf_s("%s", date, TEXT_LEN);
		enumSearchTypes searchFlag;
		scanf_s("%d", &searchFlag);
		searchByDate(deviceRoot, date, searchFlag); //TODO: Implement function
	}break;
	default:
		printf("Wrong input.");
	}
	printf("do you want to update one of the items? y/n --> ");
	char choise;
	scanf_s("%c", &choise,1);
	if (choise == 'y')
		update_device(deviceRoot);
	//return item;
}

void delete_device(deviceTree* deviceRoot) {
	printf("enter serial number of device you want to delete: ");
	device item;
	scanf_s("%d", &item.sn);
	if (!device_delete_node(deviceRoot, item))
		printf("device was deleted successfully");
	else
		printf("device could not be found");
	return;
}

void view_all_staff_members(userTree* userRoot) {

}

void staff_addition(userTree* userRoot) {
	user member;
	printf("enter member username:\n");
	scanf_s("%s", member.username, TEXT_LEN);
	if (user_searchByBST(userRoot, member)) {
		printf("member already singed to system\n");
		LOG_VAR(ERROR, "tried to input username %s but it is already taken", member.username);
		return;
	}
	printf("enter member fullname:\n");
	scanf_s("%14s", member.fullname, TEXT_LEN);
	printf("enter member permissions level 1-3:\n");
	scanf_s("%d", &(member.level));
	printf("enter member password:\n");
	scanf_s("%14s", member.password, TEXT_LEN);
	user_insert_iterative(&userRoot, member);
}

void staff_update(userTree* userRoot) {}

void staff_deletion(userTree* userRoot) {
	printf("enter username of worker you want to delete: ");
	user member;
	scanf_s("%s", member.username, TEXT_LEN);
	if (!user_delete_node(userRoot, member))
		printf("device was deleted successfully");
	else
		printf("device could not be found");
	return;
}
