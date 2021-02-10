#define VIEW 1
#define SEARCH 2
#define ADD 3
#define UPDATE 4
#define DELETE 5
#define STAFF_VIEW 6
#define STAFF_ADDITION 7
#define STAFF_UPDATE 8
#define STAFF_DELETION 9

#define SIMPLE_MENU "1-view\n2-search\n3-add\n"
#define EMPLOYEE_MENU "1-view\n2-search\n3-add\n4-update\n5-delete\n"
#define MANAGER_MENU "1-view\n2-search\n3-add\n4-update\n5-delete\n6-staff-view\n7-staff-addition\n8-staff-update\n9-staff-deletion\n"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"
#include "device_binary_tree.h"
#include "user_binary_tree.h"


FILE* logFile;
errno_t err;

void func(userTree* root) {
	user_print_tree(root, 10);
}



bool check_if_there_are_files() {
	bool bvar = false;
	return bvar;
}

user user_validation(userTree** root) {
	// input username
	char userName[TEXT_LEN] = "";
	fgets(userName, TEXT_LEN, stdin);
	// check if username exist in users-BS-Tree
	user user_var = { .username = userName };
	userTree* userNode = user_search(*root, user_var);
	//userTree user = user_search(*root, );
	// input password
	// check if password correct
	//user user_var = { .fullname = "Shahaf Edri", .level = 3, .password = "12345678", .username = "shahafe" };
	return user_var;
}

void view_devices(deviceTree* root) {
	LOG(INFO, "printing the devices");
	user_print_inorder(root);

}

void load_file() {
	FILE* fin = (FILE*)malloc(sizeof(FILE));
	char file_name[] = "";
	err = fopen_s(fin, "testFile.dat", "r");
	if (err == 0) {
		printf("File not found\n");
		printf("creating new file\n");

	}
	else {
		printf("opened file %s\n", file_name);

	}
	fclose(fin);
}

void init_func() {
	err = fopen_s(&logFile, "log_file.txt", "a");
}

void end_func() {
	err = fclose(logFile);
}

user create_admin() {
	user admin_user = { .fullname = "System_Manager",.level = 3,.password = "admin",.username = "admin" };
	return admin_user;
}

void update_device() {}

void add_device() {}

void search_device() {}

void delete_device() {}

void staff_view() {}

void staff_addition() {}

void staff_update() {}

void staff_deletion() {}

void main() {

	init_func();
	userTree* userRoot = NULL;
	deviceTree* deviceRoot = NULL;
	//load the project files
	FILE* ifPtr = (FILE*)malloc(sizeof(FILE)); // items file
	FILE* wfPtr = (FILE*)malloc(sizeof(FILE)); // workers file
	if (fopen_s(wfPtr, "worker.dat", "a") || feof(wfPtr)) { // try to open file
		printf("File could not be found OR file is empty\n");
		printf("opening new file\n");
		user admin_user = create_admin();
		user_insert_iterative(&userRoot, admin_user);
	}
	else { // file exist
		//load_file
		//fprintf();
	}
	//put in your username and password
	//func();
	user usr_var = user_validation(&userRoot);
	while (true)
	{
		if (usr_var.level = 1) //permissions - view, search, add
		{
			// print level 1 menu
			printf(SIMPLE_MENU);
			LOG(INFO, "user added a");
		}
		else if (usr_var.level = 2) //permissions - view, search, add, update, delete
		{
			// print level 2 menu
			printf(EMPLOYEE_MENU);
		}
		else if (usr_var.level = 3) //permissions - view, search, add, update, delete, staff-view, staff-addition, staff-update, staff-deletion
		{
			// print level 3 menu
			printf(MANAGER_MENU);
		}
		int action = scanf_s("%d");
		if (action != usr_var.level)
			//print error msg
			continue;
		//test

		switch (action)
		{
		case(VIEW): // view - 1
			LOG_VAR(INFO, "user %s chose function - view", usr_var.fullname);
			//view_devices();
			break;
		case(SEARCH): // search - 2
			search_device();
			break;
		case(ADD): // add - 3
			add_device();
			break;
		case(UPDATE): // update - 4
			update_device();
			break;
		case(DELETE): // delete - 5
			delete_device();
			break;
		case(STAFF_VIEW): // staff-view - 6
			staff_view();
			break;
		case(STAFF_ADDITION): // staff-addition - 7
			staff_addition();
			break;
		case(STAFF_UPDATE): // staff-update - 8
			staff_update();
			break;
		case(STAFF_DELETION): // staff-deletion - 9
			staff_deletion();
			break;
		}
	}
	end_func();
}