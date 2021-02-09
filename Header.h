#pragma once

#include <stdbool.h>

typedef struct user
{
	char username[15];
	char password[15];
	int level;
	char fullname[20];
	unsigned int id;
}user;

typedef struct device
{
	int sn[15];
	char txt[15];
	char txt1[15];
	float price;
	bool stock;
	char date[15];
}device;

//void func(var);
