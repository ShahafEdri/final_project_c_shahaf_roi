#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Header.h"
//check

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
		case(1): //view
			//1
			break;
		case(2): //, search, 
			//2
			break;
		case(3): //add, 
			//3
			break;
		case(4): // update, 
			//4
			break;
		case(5): //delete, 
			//5
			break;
		case(6): //staff-view
			//6
			break;
		case(7): //, staff-addition, 
			//7
			break;
		case(8): //, staff-update, 
			//7
			break;
		case(9): //, staff-deletion , 
			//7
			break;
		}
	}

}