#ifndef NODE_H
#define NODE_H

struct node
{
	int value;
	struct node* next;
};

typedef struct node node_t;

node_t* create_node(int value);
void free_node(node_t* node);

#endif
