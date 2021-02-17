/*
Assigned by:
Shahaf Edri 206328593
*/

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
	user user_var; 
	scanf("%s", user_var.username); 
	//check if username exist in users-BS-Tree
	userTree* userNode = user_searchByBST(*root, user_var);
	int tries = 1;
	while (userNode == NULL) {
		if (tries >= 3) {
			printf("wrong username enterd too many times {%d/3}\n", tries);
			printf("EXITING PROGRAM\n\n");
			LOG_VAR(ERROR, "tried to enter a worng username to manny time {%d/3}", tries);
			exit(1);
		}
		printf("ERROR - tried {%d/3} to enter a worng username {%s}\n", tries, user_var.username);
		LOG_VAR(ERROR, "tried to enter a worng username {%s}", user_var.username);
		printf("enter your username --> ");
		scanf("%s", user_var.username); 
		userNode = user_searchByBST(*root, user_var);
		tries++;
	}
	LOG_VAR(INFO, "user %s found in database", user_var.username);
	user_var = userNode->info;
	//input password
	printf("enter your password --> ");
	char userPassword[TEXT_LEN];
	scanf("%s", userPassword); 
	tries = 1;
	while (!(isZero(strcmp(userPassword, user_var.password)))) {//check if password correct
		if (tries >= 3) {
			printf("ERROR - exiting program, tried maximum tries (%d/3)\n\n", tries);
			LOG_VAR(ERROR, "user %s has entered a wrong password TOO MANY TIMES", user_var.username);
			exit(1);
		}
		printf("wrong password entered\n");
		LOG_VAR(DEBUG, "user %s has entered a wrong password", user_var.username);
		tries++;
		printf("try again {%d/3} --> ", (tries));
		scanf("%s", userPassword);
	}
	printf("successful login\n");
	LOG_VAR(INFO, "user %s has made a successful login", user_var.username);
	return user_var;
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
	errorLogFile = fopen_s(&logFile, "log_file.txt", "a");
	if (errorLogFile)
	{
		printf("ERROR!!! - could not open LOG file!");
		exit(1);
	}
}

void end_func(userTree* userRoot, deviceTree* deviceRoot, FILE* wfPtr, FILE* ifPtr) {
	printf("\nclosing the program\n");

	printf("saving to files:\n");
	freopen(WORKERS_FILE_NAME, "wb", wfPtr);
	//rewind(wfPtr);
	printf("Workers:\n");
	user_save_tree_to_file(userRoot, wfPtr);
	LOG(DEBUG, "finished Workers tree saving sucessfully");

	if ((errWorkers = fclose(wfPtr)) == 0)
		LOG(DEBUG, "Workers file was closed sucessfully");

	freopen(ITEMS_FILE_NAME, "wb", ifPtr);
	//rewind(ifPtr);
	printf("Items:\n");
	device_save_tree_to_file(deviceRoot, ifPtr);
	LOG(DEBUG, "finished Items tree saving sucessfully");

	if ((errItems = fclose(ifPtr)) == 0)
		LOG(DEBUG, "Items file was closed sucessfully");
	if ((errorLogFile = fclose(logFile)) == 0)
		LOG(DEBUG, "Items file was closed sucessfully");
}

user create_admin() {
	user admin_user = { .fullname = "System_Manager",.level = 3,.password = "admin",.username = "admin" };
	return admin_user;
}

//char requestActionFromUser() {
//	char action;
//	while (((action = getchar()) == '\n') || (action == EOF));
//	action = action - '0'; //char to int
//	return action;
//}

void main() {
	init_func();
	userTree* userRoot = NULL;
	deviceTree* deviceRoot = NULL;
	FILE* ifPtr = (FILE*)malloc(sizeof(FILE)); // items file
	FILE* wfPtr = (FILE*)malloc(sizeof(FILE)); // workers file
	errItems = (fopen_s(&ifPtr, ITEMS_FILE_NAME, "rb")); // try to open file
	errWorkers = (fopen_s(&wfPtr, WORKERS_FILE_NAME, "rb")); // try to open file

	if ((errWorkers != 0) || (errItems != 0)) {
		LOG(ERROR, "file could not open");
		printf("file could not open");
		exit(1);
	}

	fseek(wfPtr, 0, SEEK_END);
	if (ftell(wfPtr) == SEEK_SET) {  // file is empty
		printf("file is empty\n");
		user admin_user = create_admin();
		user_insert_iterative(&userRoot, admin_user);
		printf("new user -> admin");
	}
	else { // file not empty
		load_workers_file(wfPtr, &userRoot);// load_DB_worker_file
		load_items_file(ifPtr, &deviceRoot);// load_DB_items_file

		printf("FILES LOADED!\n");
		LOG(DEBUG, "files loaded!");
	}

	//put in your username and password
	user user_var = user_validation(&userRoot);
	printf("user info:\n%-20s%-15s%-15s%-10d\n", user_var.fullname, user_var.username, user_var.password, user_var.level);

	bool exitApplicationFlag = true;
	while (exitApplicationFlag) {
		printf("\n____________________________________");
		printf("\nMENU:\n");
		if (user_var.level == e_viewer) //permissions - view, search
			printf(SIMPLE_MENU); // print level 1 menu
		else if (user_var.level == e_employee) //permissions - view, search, add, update, delete
			printf(EMPLOYEE_MENU); // print level 2 menu
		else if (user_var.level == e_manager) //permissions - view, search, add, update, delete, staff-view, staff-addition, staff-update, staff-deletion
			printf(MANAGER_MENU);// print level 3 menu

		printf("what action would you want to make? (by number) --> ");
		char action = 0;
		while (true) {
			action = requestActionFromUser();
			//while (((action = getchar()) == '\n') || (action == EOF));
			//action = action - '0'; //char to int
			if (((user_var.level == e_viewer && HAS_PERMISSION_FOR_ACTION_SIMPLE(action)) ||
				(user_var.level == e_employee && HAS_PERMISSION_FOR_ACTION_EMPLOYEE(action)) ||
				(user_var.level == e_manager && HAS_PERMISSION_FOR_ACTION_MANAGER(action))))
				break;
			printf("\nentered a wrong number {%d}, please choose again --> ", action);
		}

		switch (action) {
			LOG_VAR(DEBUG, "executing action numebr %d", action);
		case(EXIT): // exit - 0
			LOG_VAR(INFO, "user %s chose to finish the program", user_var.fullname);
			exitApplicationFlag = false;
			break;
		case(VIEW): // view - 1
			LOG_VAR(INFO, "user %s chose function - view", user_var.fullname);
			view_all_devices(deviceRoot);
			break;
		case(SEARCH): // search - 2 -- complete
			LOG_VAR(INFO, "user %s chose function - search", user_var.fullname);
			search_device(deviceRoot);
			break;
		case(ADD): // add - 3 complete
			LOG_VAR(INFO, "user %s chose function - add device", user_var.fullname);
			add_device(&deviceRoot);
			break;
		case(UPDATE): // update - 4 -- complete
			LOG_VAR(INFO, "user %s chose function - update device", user_var.fullname);
			update_device(deviceRoot);
			break;
		case(DELETE): // delete - 5 --complete
			LOG_VAR(INFO, "user %s chose function - delete device", user_var.fullname);
			delete_device(&deviceRoot);
			break;
		case(STAFF_VIEW): // staff-view - 6 -- complete
			LOG_VAR(INFO, "user %s chose function - staff view", user_var.fullname);
			view_all_staff_members(userRoot);
			break;
		case(STAFF_ADDITION): // staff-addition - 7 -- complete
			LOG_VAR(INFO, "user %s chose function - staff addition", user_var.fullname);
			staff_addition(userRoot);
			break;
		case(STAFF_UPDATE): // staff-update - 8 
			LOG_VAR(INFO, "user %s chose function - staff update", user_var.fullname);
			staff_update(userRoot);
			break;
		case(STAFF_DELETION): // staff-deletion - 9 -- complete
			LOG_VAR(INFO, "user %s chose function - staff deletion", user_var.fullname);
			staff_deletion(&userRoot);
			break;
		default:
			printf("The action is not supported.");
			LOG(ERROR, "wrong number was entered");
		}
	}
	end_func(userRoot, deviceRoot, wfPtr, ifPtr);
}