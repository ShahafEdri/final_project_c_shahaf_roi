#pragma once
#include"Header.h"

char requestActionFromUser();

void view_all_devices(deviceTree* deviceRoot);

void add_device(deviceTree** device_root);

void update_device(deviceTree* deviceRoot);

void search_device(deviceTree* deviceRoot);

void delete_device(deviceTree** deviceRoot);

void view_all_staff_members(userTree* userRoot);

void staff_addition(userTree* userRoot);

void staff_update(userTree* userRoot);

void staff_deletion(userTree** userRoot);