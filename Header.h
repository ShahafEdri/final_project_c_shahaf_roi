#pragma once

#include <stdbool.h>

#define ARG(...) int[]{__VA_ARGS__, 0}
#define IARG(...) int[]{__VA_ARGS__, 0}
#define CARG(...) char[]{__VA_ARGS__, 0}
#define WRAPPER(CHARS, INTS) funct(CARG CHARS, IARG INTS)

#define LOG(log_level, msg) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__)
#define LOG_VAR(log_level, msg, var) fprintf (logFile, #log_level ":  Time:%s, File:%s(%d), Function:%s \n\t" #log_level " Message: " msg  "\n", __TIMESTAMP__, __FILE__, __LINE__, __FUNCTION__, var)
//use example --> LOG(WARNING, "message")
//use example --> LOG(WARNING, "mesasge with var %d", var)
//log_level = options INFO, WARNING, DEBUG, ERROR

#define TEXT_LEN 15
#define FULLNAME_LEN 20

typedef struct user
{
	char username[TEXT_LEN];
	char password[TEXT_LEN];
	int level;
	char fullname[FULLNAME_LEN];
}user;

typedef struct device
{
	int sn;
	char brand[TEXT_LEN];
	char company[TEXT_LEN];
	float price;
	bool stock;
	char date[TEXT_LEN];
}device;


FILE* logFile;
errno_t err;

//void func(var);
