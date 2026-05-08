#ifndef LIST_H
#define LIST_H

#include "../node/node.h"

/*
    TODO

    start over - add https://www.geeksforgeeks.org/dsa/doubly-linked-list/
    Doubly Linked List

    List core
    - print_list - done

    Insert
    - insert_at_head - done
    - insert_at_tail - done
    - insert_after   - done
    - insert_before  - done

    Delete
    - remove_node - done
    - clear_list  - done

    Search
    - find_node - done
    - contains
    - nth_from_end

    Algorithms - https://www.geeksforgeeks.org/dsa/introduction-to-sorting-algorithm/
    - reverse_list - done
    - sort_list
    - copy_list
    - detect_cycle
    - find_min
    - find_max

   */

struct list
{
	node_t* head;
	node_t* tail;
	int length;
};

typedef struct list list_t;

// List core
list_t* create_list();
void free_list(list_t* list);
void print_list(node_t* node);

// Insert
node_t* insert_at_head(list_t* list, node_t* node_to_insert);
node_t* insert_at_tail(list_t* list, node_t* node_to_insert);
node_t* insert_after(list_t* list, int value, node_t* node_to_insert);
node_t* insert_before(list_t* list, int value, node_t* node_to_insert);

// Delete
void remove_node(list_t* list, int value);
void clear_list(list_t* list);

// Search
node_t* find_node(node_t* head, int value);

// Algorithms
node_t* reverse_list(list_t* list);

#endif
