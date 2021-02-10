#define VIEW 1
#define SEARCH 2
#define ADD 3
#define UPDATE 4
#define DELETE 5
#define STAFF_VIEW 6
#define STAFF_ADDITION 7
#define STAFF_UPDATE 8
#define STAFF_DELETION 9

#define SIMPLE_MENU " 1-view\n 2-search\n\n"
#define HAS_PERMISSION_FOR_ACTION_SIMPLE(X) ((X) > 0 && (X) < 3)
#define EMPLOYEE_MENU " 1-view\n 2-search\n 3-add\n 4-update\n 5-delete\n\n"
#define HAS_PERMISSION_FOR_ACTION_EMPLOYEE(X) ((X) > 0 && (X) < 6)
#define MANAGER_MENU " 1-view\n 2-search\n 3-add\n 4-update\n 5-delete\n 6-staff-view\n 7-staff-addition\n 8-staff-update\n 9-staff-deletion\n\n"
#define HAS_PERMISSION_FOR_ACTION_MANAGER(X) ((X) > 0 && (X) < 10)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
	//input username
	printf("enter your username --> ");
	//user user_var; // TODO uncomment
	user user_var = { .username = "admin" }; // TODO remove
	//scanf("%s", user_var.username); //TODO uncomment
	//check if username exist in users-BS-Tree
	userTree* userNode = user_search(*root, user_var);
	if (userNode != NULL) {
		LOG_VAR(info, "user %s found in database", user_var.username);
		user_var = userNode->data;
	}
	else {
		printf("tried to enter a worng username-- > % s", user_var.username);
		LOG_VAR(info, "tried to enter a worng username --> %s ", user_var.username);
	}
	//input password
	printf("enter your password --> ");
	char userPassword[TEXT_LEN] = "admin";
	int tries = 0;
	for (tries = 0; tries < 3; tries++) {
		//scanf("%s", userPassword);
		//check if password correct
		if (!strcmp(userPassword, user_var.password)) {
			printf("successful login");
			LOG_VAR(info, "user %s has made a successful login", user_var.username);
			return user_var;
		}
		else {
			printf("wrong password entered");
			LOG_VAR(info, "user %s has entered a wrong password", user_var.username);
		}
		printf("try again (%d)", (tries + 1));
	}
	printf("exiting program, tried maximum tries (%d)", tries);
	LOG_VAR(ERROR, "user %s has entered a wrong password TOO MANY TIMES", user_var.username);
	exit(1);
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
	if (fopen_s(wfPtr, "worker.dat", "a") || !(feof(wfPtr))) { // try to open file
		printf("File could not be found OR file is empty\n");
		user admin_user = create_admin();
		user_insert_iterative(&userRoot, admin_user);
	}
	else { // file exist
		//load_file
		printf("ERROR!!!");
	}
	//put in your username and password
	//func();
	user user_var = user_validation(&userRoot);
	while (true)
	{
		printf("\n\nMENU:\n");
		if (user_var.level == 1) //permissions - view, search, add
		{
			// print level 1 menu
			printf(SIMPLE_MENU);
		}
		else if (user_var.level == 2) //permissions - view, search, add, update, delete
		{
			// print level 2 menu
			printf(EMPLOYEE_MENU);
		}
		else if (user_var.level == 3) //permissions - view, search, add, update, delete, staff-view, staff-addition, staff-update, staff-deletion
		{
			// print level 3 menu
			printf(MANAGER_MENU);
		}

		printf("what action would you want to make? (by number) --> ");
		int action = 0;
		while (true) {
			scanf_s("%d", &action);
			if (((user_var.level == 1 && HAS_PERMISSION_FOR_ACTION_SIMPLE(action)) ||
				(user_var.level == 2 && HAS_PERMISSION_FOR_ACTION_EMPLOYEE(action)) ||
				(user_var.level == 3 && HAS_PERMISSION_FOR_ACTION_MANAGER(action))))
			{
				break;
			}
			printf("entered a wrong number, please choose again --> ");
		}

		switch (action)
		{
			LOG_VAR(DEBUG, "executing action numebr %d", action);
		case(VIEW): // view - 1
			LOG_VAR(INFO, "user %s chose function - view", user_var.fullname);
			view_device();
			break;
		case(SEARCH): // search - 2 -- complete
			search_device();
			break;
		case(ADD): // add - 3 complete
			add_device();
			break;
		case(UPDATE): // update - 4 -- complete
			update_device();
			break;
		case(DELETE): // delete - 5 --complete
			delete_device();
			break;
		case(STAFF_VIEW): // staff-view - 6 -- 
			staff_view_func();
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