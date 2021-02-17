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

#define isNegative(X) 0 > X
#define isPositive(X) 0 < X
#define isZero(X) 0 == X

#define ITEMS_FILE_NAME "items.bin"
#define WORKERS_FILE_NAME "workers.bin"

typedef struct user {
	char username[TEXT_LEN];
	char password[TEXT_LEN];
	int level;
	char fullname[FULLNAME_LEN];
}user;
#define USER_HEADER "\n\n%-20s%-15s%-15s%-10s\n","fullname", "username","password", "level"
#define USER_PARAMETERS "%d-fullname,  %d-username,  %d-password,  %d-permission\n",e_fullname,e_username,e_password,e_level
typedef enum enumUserStructOptions {
	e_fullname,
	e_username,
	e_password,
	e_level
}enumUserStructOptions;

typedef struct device {
	int sn;
	char brand[TEXT_LEN];
	char company[TEXT_LEN];
	float price;
	bool stock;
	char date[TEXT_LEN];// format -> dd-mm-yyyy
}device;
#define ITEMS_HEADER "\n%-15s%-15s%-15s%-10s%-10s%-15s\n","S/N","Brand","Company","Price","Stock?", "Date"
#define ITEM_PARAMETERS "%d-serial-number, %d-brand, %d-company, %d-price, %d-stock, %d-date\n",e_serial_num,e_brand,e_company,e_price,e_stock,e_date
typedef enum enumDeviceStructOptions {
	e_serial_num = 1,
	e_brand,
	e_company,
	e_price,
	e_stock,
	e_date
}enumUserStructOptions;


#define SEARCH_PREFERENCE_OPTION "%d-equal, %d-bigger_then, %d-smaller_then",e_equal,e_forward_or_bigger,e_backword_or_smaller
typedef enum enumSearchTypes {
	e_equal,
	e_forward_or_bigger,
	e_backword_or_smaller
}enumSearchTypes;


typedef enum enumManagerLevel {
	e_viewer = 1,
	e_employee,
	e_manager
}enumManagerLevel;

typedef enum enumDate {
	e_day,
	e_month,
	e_year
}enumDate;


FILE* logFile;
errno_t errItems;
errno_t errWorkers;
errno_t errorLogFile;
int temp;

//void func(var);
