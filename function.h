#pragma once
#include"Header.h"

#define ITEM_PARAMETERS "1-serial-number, 2-brand, 3-company, 4-price, 5-stock, 6-date"

void add_device(deviceTree* device_root);

void update_device(deviceTree* deviceRoot);

void search_device();

void delete_device();

void staff_view();

void staff_addition();

void staff_update();

void staff_deletion();