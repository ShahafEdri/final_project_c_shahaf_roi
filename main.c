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
#include "binary_tree.h"

FILE* logFile;
errno_t err;
#define LOG(log_level, msg) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__)
#define LOG_VAR(log_level, msg, var) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__, var)
//use example --> LOG(WARNING, "message")
//use example --> LOG(WARNING, "mesasge with var %d", var)

void func() {}



bool check_if_there_are_files() {
	bool bvar = false;
	return bvar;
}

user user_validation(tree** root) {
	// input username

	// check if username exist in users-BS-Tree
	// input password
	// check if password correct
	user user_var = { .fullname = "Shahaf Edri", .level = 3, .password = "12345678", .username = "shahafe" };
	return user_var;
}

void view_func() {}

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
	user admin_user = { .fullname = "System_Manager",.level = 3,.password = "admin",.username = "admin" ,.id = 123456789 };
	return admin_user;
}

void update_func() {}

void add_func() {}

void search_func() {}

void delete_func() {}

void staff_view_func() {}

void staff_addition_func() {}

void staff_update_func() {}

void staff_deletion_func() {}

void main() {

	init_func();
	tree* root = NULL;
	//load the project files
	FILE* ifPtr = (FILE*)malloc(sizeof(FILE)); // items file
	FILE* wfPtr = (FILE*)malloc(sizeof(FILE)); // workers file
	if (fopen_s(wfPtr, "worker.dat", "a") || feof(wfPtr)) { // try to open file
		printf("File could not be found OR file is empty\n");
		printf("opening new file\n");
		user admin_user = create_admin();
		insert_iterative(&root, admin_user);
	}
	else { // file exist
		//load_file
		//fprintf();
	}
	//put in your username and password
	user usr_var = user_validation(&root);
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
		case(VIEW): // view - complete
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
			staff_addition_func();
			break;
		case(STAFF_UPDATE): // staff-update - 8
			staff_update_func();
			break;
		case(STAFF_DELETION): // staff-deletion - 9
			staff_deletion_func();
			break;
		}
	}
	end_func();
}