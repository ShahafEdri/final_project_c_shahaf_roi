#pragma once

#include <stdbool.h>

#define LOG(log_level, msg) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__)
#define LOG_VAR(log_level, msg, var) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__, var)
//use example --> LOG(WARNING, "message")
//use example --> LOG(WARNING, "mesasge with var %d", var)
//log_level = options INFO, WARNING, DEBUG, ERROR


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
