#ifndef NODE_H
#define NODE_H

struct node
{
	int value;
	struct node* next;
	struct node* prev;
};

typedef struct node node_t;

node_t* create_node(int value);
void free_node(node_t* node);
void print_node(node_t* node);

#endif
