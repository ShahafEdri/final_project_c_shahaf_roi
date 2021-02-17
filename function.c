/*
Assigned by:
Shahaf Edri 206328593
*/
#include<stdio.h>
#include <string.h>
#include <ctype.h>
#include "device_binary_tree.h"
#include "user_binary_tree.h"
#include "function.h"
#include "Header.h"

char requestActionFromUser(bool shoudReturnInt) {
	char action;
	while (((action = getchar()) == '\n') || (action == EOF));
	if (shoudReturnInt)
		action = action - '0'; //char to int
	return action;
}

void view_all_devices(deviceTree* deviceRoot) {
	printf("\n%-15s%-15s%-15s%-10s%-10s%-15s\n",
		"S/N",
		"Brand",
		"Company",
		"Price",
		"Stock?", // if 1 then V else X
		"Date"
	);
	LOG(INFO, "printing the devices");
	device_print_inorder(deviceRoot);
}

void add_device(deviceTree** deviceRoot)
{
	device item;

	printf("enter item serial number:\n");
	scanf_s("%d", &item.sn);
	if (device_searchByBST(*deviceRoot, item.sn)) {
		printf("this code is already taken\n");
		LOG_VAR(ERROR, "tried to input serial number %d but it is already taken", item.sn);
		return;
	}

	printf("enter item brand: ");
	scanf_s("%14s", item.brand, TEXT_LEN);
	//printf("%s", item.brand);
	printf("enter item company: ");
	scanf_s("%14s", item.company, TEXT_LEN);
	//printf("%s", item.company);
	printf("enter item price: ");
	scanf_s("%f", &item.price);
	printf("enter item date dd-mm-yyyy: ");
	scanf_s("%14s", &item.date, TEXT_LEN);
	item.stock = true;

	device_insert_iterative(deviceRoot, item);
}


void update_device(deviceTree* deviceRoot) {
	deviceTree* Node = (deviceTree*)malloc(sizeof(deviceTree));
	printf("what is the serial-number of the product you want to change? --> ");
	scanf_s("%d", &(Node->item.sn));
	if ((Node = device_searchByBST(deviceRoot, Node->item.sn)) == NULL) {
		printf("ERROR - unknown serial number was entered");
		LOG(DEBUG, "ERROR - unknown serial number was entered");
		return;
	}
	device_print_all_items(&Node->item, false);
	printf(ITEM_PARAMETERS);
	int change_option;
	printf("what would you like to change in the product (by number)? --> ");
	change_option = requestActionFromUser(true);
	printf("what would you like to change it to? --> ");
	switch (change_option)
	{
	case(e_serial_num):
		scanf_s("%d", &(Node->item.sn));
		break;
	case(e_brand):
		scanf_s("%s", Node->item.brand, TEXT_LEN);
		break;
	case(e_company):
		scanf_s("%s", Node->item.company, TEXT_LEN);
		break;
	case(e_price):
		scanf_s("%f", &(Node->item.price));
		break;
	case(e_stock):
		printf("\n1 for true 0 for false\n");
		scanf_s("%d", &(Node->item.stock));
		break;
	case(e_date):
		scanf_s("%s", Node->item.date, TEXT_LEN);
		break;
	default:
		printf("no action was picked");
		break;
	}
	printf("changes made:\n");
	device_print_all_items(&Node->item, false);
}

void search_device(deviceTree* deviceRoot) {
	char searchHeader;
	device* item = NULL;
	printf(ITEM_PARAMETERS);
	printf("what would you like to search by? (by number) --> ");
	searchHeader = requestActionFromUser(true);
	switch (searchHeader) {
	case(e_serial_num): {
		LOG(INFO, "user chose function - search by SN");
		printf("enter the serial you want to search by --> ");
		int serial = 0;
		while (!serial)
			scanf_s("%d", &serial);
		printf(SEARCH_PREFERENCE_OPTION);
		printf("\nsearch preference (by number)? --> ");
		enumSearchTypes searchFlag;
		searchFlag = requestActionFromUser(true);
		printf(ITEMS_HEADER);
		searchDeviceBySerialNum(deviceRoot, serial, searchFlag);
	}break;
	case (e_brand): {
		LOG(INFO, "user chose function - search by brand");
		char brand[TEXT_LEN];
		printf("Enter the brand you want to search --> ");
		scanf_s("%s", brand, TEXT_LEN);
		printf(ITEMS_HEADER);
		searchDeviceByBrand(deviceRoot, brand);
	}break;
	case(e_company): {
		LOG(INFO, "user chose function - search by company");
		printf("Enter the company you want to search --> ");
		char company[TEXT_LEN];
		scanf_s("%s", company, TEXT_LEN);
		printf(ITEMS_HEADER);
		searchDeviceByCompany(deviceRoot, company);
	}break;
	case(e_price): {
		LOG(INFO, "user chose function - search by price");
		printf("enter the value of the price you want to search by\n");
		float price = 0;
		while (price <= 0) {
			printf("should be bigger then zero --> ");
			scanf_s("%f", &price);
		}
		printf(SEARCH_PREFERENCE_OPTION);
		printf("\nsearch preference (by number)? --> ");
		enumSearchTypes searchFlag;
		searchFlag = requestActionFromUser(true);
		printf(ITEMS_HEADER);
		searchDeviceByPrice(deviceRoot, price, searchFlag);
	}break;
	case(e_stock): {
		LOG(INFO, "user chose function - search by stock");
		int boolVar = -1;
		printf("for devices in stock enter 1 , for out of stock 0: ");
		while (!(boolVar == 0 || boolVar == 1)) {
			printf("[1/0]? --> ");
			scanf_s("%d", &boolVar);
		}
		printf(ITEMS_HEADER);
		searchByStock(deviceRoot, boolVar);
	}break;
	case(e_date): {
		LOG(INFO, "user chose function - search by date");
		printf("Enter the date you want to search {format 'dd-mm-yyyy'} --> ");
		char date[TEXT_LEN];
		scanf_s("%s", date, TEXT_LEN);
		printf(SEARCH_PREFERENCE_OPTION);
		printf("\nsearch preference (by number)? --> ");
		enumSearchTypes searchFlag;
		scanf_s("%d", &searchFlag);
		printf(ITEMS_HEADER);
		searchByDate(deviceRoot, date, searchFlag); 
	}break;
	default:
		printf("Wrong input.");
		LOG(ERROR, "wrong input was entered");
		return;
	}
	char choise = -1;
	printf("do you want to update one of the items? ");
	while (!(choise == 'y' || choise == 'n')) {
		printf("[y/n]? --> ");
		choise = requestActionFromUser(false);
	}
	if (choise == 'y')
		update_device(deviceRoot);
	//return item;
}

void delete_device(deviceTree** deviceRoot) {
	printf("enter serial number of device you want to delete: ");
	device item;
	scanf_s("%d", &item.sn);
	if (device_searchByBST(*deviceRoot, item.sn)) {
		*deviceRoot = device_delete_node(*deviceRoot, item);
		printf("device was deleted successfully");
		LOG(DEBUG, "device was deleted successfully");
	}
	else {
		printf("device could not be found");
		LOG(DEBUG, "device could not be found");
	}
}

void view_all_staff_members(userTree* userRoot) {
	printf("\n\n%-20s%-15s%-15s%-10s\n",
		"fullname", "username",
		"password", "level");
	LOG(INFO, "printing the staff members");
	user_print_inorder(userRoot);
}

void strToNameFormat(char* str) {
	/*makes a string of one name no spaces to name format - uppercase first and lower case all the rest*/
	int i = 0;
	str[i] = toupper(str[i]);
	i++;
	while (str[i]) {
		str[i] = (tolower(str[i]));
		i++;
	}
}


void strcpyFullName(char* memberPtr, char* firstname, char* lastname) {
	strToNameFormat(firstname);
	strToNameFormat(lastname);
	strcat_s(firstname, sizeof(char) * TEXT_LEN, " ");
	strcat_s(firstname, sizeof(char) * TEXT_LEN, lastname);
	strcpy_s(memberPtr, sizeof(char) * TEXT_LEN, firstname);
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
	printf("enter member first name:\n");
	char firstname[TEXT_LEN];
	scanf_s("%7s", firstname, TEXT_LEN);
	strToNameFormat(firstname);
	printf("enter member last name:\n");
	char lastname[TEXT_LEN];
	scanf_s("%7s", lastname, TEXT_LEN);
	strToNameFormat(lastname);
	strcat_s(firstname, sizeof(char) * TEXT_LEN, " ");
	strcat_s(firstname, sizeof(char) * TEXT_LEN, lastname);
	strcpy_s(member.fullname, sizeof(char) * TEXT_LEN, firstname);
	printf("enter member permissions level 1-3:\n");
	scanf_s("%d", &(member.level));
	printf("enter member password:\n");
	scanf_s("%14s", member.password, TEXT_LEN);
	user_insert_iterative(&userRoot, member);
}

void staff_update(userTree* userRoot) {
	userTree* Node = (userTree*)malloc(sizeof(userTree));
	printf("what is the username of the member you want to change? --> ");
	scanf_s("%s", &(Node->info.username), TEXT_LEN);
	if ((Node = user_searchByBST(userRoot, Node->info)) == NULL) {
		printf("ERROR - unknown username was entered");
		LOG(DEBUG, "ERROR - unknown username was entered");
		return;
	}

	user_print_all_user_info(&(Node->info), true);
	printf(USER_PARAMETERS);
	enum enumUserStructOptions change_option;
	printf("what would you like to change in the member (by number)? --> ");
	scanf_s("%d", &change_option);
	//printf("what would you like to change it to? --> ");
	switch (change_option)
	{
	case(e_username):
		printf("enter member new username --> ");
		scanf_s("%s", &(Node->info.username), TEXT_LEN);
		break;
	case(e_password):
		printf("enter member new password --> ");
		scanf_s("%s", Node->info.password, TEXT_LEN);
		break;
	case(e_level):
		printf("enter member new permission level (1-3) --> ");
		scanf_s("%d", &Node->info.level);
		break;
	case(e_fullname):
		printf("enter member new first name --> ");
		char firstname[TEXT_LEN];
		scanf_s("%7s", firstname, TEXT_LEN);
		printf("enter member new last name --> ");
		char lastname[TEXT_LEN];
		scanf_s("%7s", lastname, TEXT_LEN);
		strcpyFullName(Node->info.fullname, firstname, lastname);
		break;
	default:
		printf("no action was picked");
		break;
	}
	printf("changes made:\n");
	user_print_all_user_info(&(Node->info), true);
}

void staff_deletion(userTree** userRoot) {
	printf("enter username of worker you want to delete: ");
	user member;
	scanf_s("%s", member.username, TEXT_LEN);
	if (user_searchByBST(*userRoot, member)) {
		*userRoot = user_delete_node(*userRoot, member);
		printf("user was deleted successfully");
		LOG_VAR(DEBUG, "user {%s} was deleted successfully", member.username);
	}
	else {
		printf("user could not be found");
		LOG_VAR(DEBUG, "user {%s} could not be found", member.username);
	}
}

