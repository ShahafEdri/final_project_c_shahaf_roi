#include<stdio.h>
#include "device_binary_tree.h"
#include "user_binary_tree. h"

void view_device(deviceTree *root)
{
    device_print_inorder(root)
}

struct deviceTree* add_device(deviceTree* root)
{
    deviceTree temp;
    printf("Please enter the device details in the following order : SN  price  brand  company");
    scanf_s("%d %d %d %d", &temp.data.sn,&temp.data.price,&temp.data.brand,&temp.data.company);
    device_insert_iterative(root, temp.data.sn);
    device_insert_iterative(root, temp.data.price);
    device_insert_iterative(root, temp.data.company);
    device_insert_iterative(root, temp.data.brand);
    return deviceTree;
}

struct deviceTree* delete_device(deviceTree* root)
{
    deviceTree temp;
    printf("Please enter the SN of the device you want to delete");
    scanf_s("%d", &temp);
    device_delete_node(device_root, temp)
}
struct deviceTree* update_device(deviceTree* root)
{
    deviceTree Oldval, Newval;
    printf("please enter the SN of the device you want to change");
        scanf("%d", &Oldval);
    //  First delete old key value 
    root = delete_node(root, Oldval);
    printf("please enter the new SN of the new device");
    scanf("%d", &Newval);
    // Then insert new key value 
    root = insert_iterative(root, Newval);
    // Return new root 
    return root;
}
void search_device(tree *device_root, device)
{
    //TBD
}
void staff_view(struct node* staff_root)
{
    print_inorder(tree * staff_root)
}
void staff_addition_func(struct node* staff_root, device)
{
    insert_iterative(staff_root, device)
        return node;
}
staff_update_func();