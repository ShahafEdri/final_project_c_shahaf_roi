#define EXIT 0
#define VIEW 1
#define SEARCH 2
#define ADD 3
#define UPDATE 4
#define DELETE 5
#define STAFF_VIEW 6
#define STAFF_ADDITION 7
#define STAFF_UPDATE 8
#define STAFF_DELETION 9

#define SIMPLE_MENU " 0-exit\n 1-view\n 2-search\n\n"
#define HAS_PERMISSION_FOR_ACTION_SIMPLE(X) ((X) > -1 && (X) < 3)
#define EMPLOYEE_MENU " 0-exit\n 1-view\n 2-search\n 3-add\n 4-update\n 5-delete\n\n"
#define HAS_PERMISSION_FOR_ACTION_EMPLOYEE(X) ((X) > -1 && (X) < 6)
#define MANAGER_MENU " 0-exit\n 1-view\n 2-search\n 3-add\n 4-update\n 5-delete\n 6-staff-view\n 7-staff-addition\n 8-staff-update\n 9-staff-deletion\n\n"
#define HAS_PERMISSION_FOR_ACTION_MANAGER(X) ((X) > -1 && (X) < 10)

#define _CRT_SECURE_NO_WARNINGS

#define VariableName(name) #name

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Header.h"
#include "device_binary_tree.h"
#include "user_binary_tree.h"
#include "function.h"


void func(FILE* wfPtr) {
	printf("%d\n", ftell(wfPtr));
	rewind(wfPtr);
	printf("%d\n", ftell(wfPtr));
	fseek(wfPtr, 0, SEEK_SET);
	printf("%d\n", ftell(wfPtr));
	fseek(wfPtr, 0, SEEK_END);
	printf("%d\n", ftell(wfPtr));
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
		user_var = userNode->info;
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

void view_all_devices(deviceTree* root) {
	LOG(INFO, "printing the devices");
	device_print_inorder(root);

}

void load_workers_file(FILE* wfPtr, userTree** userRoot) {
	rewind(wfPtr);
	user current_user_from_file;
	fread(&current_user_from_file, sizeof(struct user), 1, wfPtr);
	while (!(feof(wfPtr))) {
		LOG_VAR(DEBUG, "user added to user_BST, USER: %s", current_user_from_file.username);
		user_insert_iterative(userRoot, current_user_from_file);
		fread(&current_user_from_file, sizeof(struct user), 1, wfPtr);
	}
}

void load_items_file(FILE* ifPtr, deviceTree** deviceRoot) {
	rewind(ifPtr);
	device current_item_from_file;
	fread(&current_item_from_file, sizeof(struct user), 1, ifPtr);
	while (!(feof(ifPtr))) {
		LOG_VAR(DEBUG, "item added to item_BST, USER: %s", current_item_from_file.brand);
		device_insert_iterative(deviceRoot, current_item_from_file);
		fread(&current_item_from_file, sizeof(struct user), 1, ifPtr);
	}
}

void init_func() {
	err = fopen_s(&logFile, "log_file.txt", "a");
}

void end_func(userTree* userRoot, deviceTree* deviceRoot, FILE* wfPtr, FILE* ifPtr) {
	rewind(wfPtr);
	user_save_tree_to_file(userRoot, wfPtr);
	rewind(ifPtr);
	device_save_tree_to_file(deviceRoot, ifPtr);
	err = fclose(logFile);
}

user create_admin() {
	user admin_user = { .fullname = "System_Manager",.level = 3,.password = "admin",.username = "admin" };
	return admin_user;
}


void main() {
	init_func();
	userTree* userRoot = NULL;
	deviceTree* deviceRoot = NULL;
	FILE* ifPtr = (FILE*)malloc(sizeof(FILE)); // items file
	FILE* wfPtr = (FILE*)malloc(sizeof(FILE)); // workers file
	err = (fopen_s(&ifPtr, "items.bin", "ab+")); // try to open file
	//fseek(ifPtr, 0, SEEK_END);
	printf("%d\n", ftell(ifPtr));
	err = (fopen_s(&wfPtr, "workers.bin", "ab+")); // try to open file
	//fseek(wfPtr, 0, SEEK_END);
	printf("%d\n", ftell(wfPtr));

	/* read all records from file (until eof) */
	user user_var;
	printf("\n\n%-20s%-15s%-15s%-10s\n",
		"fullname", "username",
		"password", "level");
	fread(&user_var, sizeof(struct user), 1, wfPtr);
	while (!feof(wfPtr)) {
		/* display record */
		printf("%-20s%-15s%-15s%-10d\n",
			user_var.fullname, user_var.username,
			user_var.password, user_var.level);
		fread(&user_var, sizeof(struct user), 1, wfPtr);
	} /* end while */


	if (!(err == 0))
	{
		LOG(ERROR, "workers.bin file could not open");
		printf("workers.bin file could not open");
		exit(1);
	}
	//func(wfPtr);
	fseek(wfPtr, 0, SEEK_END);
	if (ftell(wfPtr) == SEEK_SET) {  // file is empty
		printf("file is empty\n");
		user admin_user = create_admin();
		user_insert_iterative(&userRoot, admin_user);
		printf("printing tree: LEFT TO RIGHT");
		user_print_tree(userRoot, 0);
	}
	else { // file not empty
		//users
		load_workers_file(wfPtr, &userRoot);// load_DB_files
		printf("printing user tree: LEFT TO RIGHT\n");
		user_print_tree(userRoot, 2);

		//devices
		load_items_file(ifPtr, &deviceRoot);// load_DB_files
		printf("printing device tree: LEFT TO RIGHT\n");
		device_print_tree(userRoot, 2);

		printf("FILES LOADED!");
		LOG(DEBUG, "files loaded!");
	}
	//put in your username and password
	user_var = user_validation(&userRoot);
	bool flag = true;
	while (flag) {
		printf("\n\nMENU:\n");
		if (user_var.level == 1) //permissions - view, search, add
			printf(SIMPLE_MENU); // print level 1 menu
		else if (user_var.level == 2) //permissions - view, search, add, update, delete
			printf(EMPLOYEE_MENU); // print level 2 menu
		else if (user_var.level == 3) //permissions - view, search, add, update, delete, staff-view, staff-addition, staff-update, staff-deletion
			printf(MANAGER_MENU);// print level 3 menu

		printf("what action would you want to make? (by number) --> ");
		int action = 0;
		while (true) {
			scanf_s("%d", &action);
			if (((user_var.level == 1 && HAS_PERMISSION_FOR_ACTION_SIMPLE(action)) ||
				(user_var.level == 2 && HAS_PERMISSION_FOR_ACTION_EMPLOYEE(action)) ||
				(user_var.level == 3 && HAS_PERMISSION_FOR_ACTION_MANAGER(action))))
				break;
			printf("entered a wrong number, please choose again --> ");
		}

		switch (action)
		{
			LOG_VAR(DEBUG, "executing action numebr %d", action);
		case(EXIT): // exit - 0
			LOG_VAR(INFO, "user %s chose to finish the program", user_var.fullname);
			flag = false;
			break;
		case(VIEW): // view - 1
			LOG_VAR(INFO, "user %s chose function - view", user_var.fullname);
			view_all_devices(deviceRoot);
			break;
		case(SEARCH): // search - 2 -- complete
			search_device();
			break;
		case(ADD): // add - 3 complete
			add_device(deviceRoot);
			break;
		case(UPDATE): // update - 4 -- complete
			update_device(deviceRoot);
			break;
		case(DELETE): // delete - 5 --complete
			delete_device();
			break;
		case(STAFF_VIEW): // staff-view - 6 -- 
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

	end_func(userRoot, deviceRoot, wfPtr, ifPtr);
}