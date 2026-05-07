#ifndef LIST_H
#define LIST_H

#include "../node/node.h"

/*
    TODO

    start over - add https://www.geeksforgeeks.org/dsa/doubly-linked-list/
    Doubly Linked List
   */

struct list
{
	node_t* head;
	node_t* tail;
	int length;
};

typedef struct list list_t;

list_t* create_list();
void free_list(list_t* list);
node_t* insert_at_head(list_t* list, node_t* node_to_insert);
node_t* find_node(list_t* list, int value);
node_t* reverse_list(list_t* list);
node_t* remove_node(list_t* list, int value);
node_t* insert_at_tail(list_t* list, node_t* node_to_insert);
void clear_list(list_t* list);

void print_list(list_t* list);

#endif
