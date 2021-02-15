#pragma once
#include"Header.h"

#define ITEM_PARAMETERS "1-serial-number, 2-brand, 3-company, 4-price, 5-stock, 6-date"
#define SERIAL_NUM 1
#define BRAND 2
#define COMPANY 3
#define PRICE 4
#define STOCK 5
#define DATE 6

void view_all_devices(deviceTree* deviceRoot);

void add_device(deviceTree* device_root);

void update_device(deviceTree* deviceRoot);

void search_device(deviceTree* deviceRoot);

void delete_device(deviceTree* deviceRoot);

void view_all_staff_members(userTree* userRoot);

void staff_addition(userTree* userRoot);

void staff_update(userTree* userRoot);

void staff_deletion(userTree* userRoot);