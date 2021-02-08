#define VIEW 1
#define SEARCH 2
#define ADD 3
#define UPDATE 4
#define DELETE 5
#define STAFF_VIEW 6
#define STAFF_ADDITION 7
#define STAFF_UPDATE 8
#define STAFF_DELETION 9

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"


void func() {

}



bool check_if_there_are_files() {
	bool bvar;
	return bvar;
}

user user_validation() {
	// input username
	// check if username exist in users-file
	// input password
	// check if password correct
	user user_var;
	return user_var;
}

void view_func();
void load_files() {
	FILE* fin;
	fin = fopen("testFile.dat", "r");
	if (fin == NULL);
	{
		printf("File not found\n");
		printf("creating new file\n");

	}
	fclose(fin);
}
void create_admin();
void update_func();
void add_func();
void search_func();
void delete_func();
void staff_view_func();
void staff_addition_func();
void staff_update_func();
void staff_deletion_func();

void main() {
	//load the project files
	if (check_if_there_are_files())
		load_files();
	else
		create_admin();

	//put in your username and password
	user usr_var = user_validation();
	while (1)
	{
		if (usr_var.level = 1) //permissions - view, search, add
		{
			// print level 1 menu
			printf("1-view\n2-search\n3-add\n");
		}
		else if (usr_var.level = 2) //permissions - view, search, add, update, delete
		{
			// print level 2 menu
			printf("1-view\n2-search\n3-add\n4-update\n5-delete\n");
		}
		else if (usr_var.level = 3) //permissions - view, search, add, update, delete, staff-view, staff-addition, staff-update, staff-deletion
		{
			// print level 3 menu
			printf("1-view\n2-search\n3-add\n4-update\n5-delete\n6-staff-view\n7-staff-addition\n8-staff-update\n9-staff-deletion\n");
		}
		int action = scanf_s("%d");
		if (action != usr_var.level)
			//print error msg
			continue;


		switch (action)
		{
		case(VIEW): // view - 1
			view_func();
			break;
		case(SEARCH): // search - 2
			search_func();
			break;
		case(ADD): // add - 3
			add_func();
			break;
		case(UPDATE): // update - 4
			update_func();
			break;
		case(DELETE): // delete - 5
			delete_func();
			break;
		case(STAFF_VIEW): // staff-view - 6
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

}