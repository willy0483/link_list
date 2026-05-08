#include "node.h"

#include <stdlib.h>
#include <stdio.h>

node_t* create_node(int value)
{
	node_t* node = malloc(sizeof(node_t));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

void free_node(node_t* node)
{
	if(node != NULL)
	{
		free(node);
	}
}

void print_node(node_t* node)
{
	if(node != NULL)
	{
		printf("\nValue: %d\n"
			   "Pointer: %p\n"
			   "Next:  %d\n"
			   "Prev:  %d\n\n",
			   node->value,
			   (void*)&node,
			   node->next ? node->next->value : -1,
			   node->prev ? node->prev->value : -1);
	}
	else
	{
		printf("Node was a NULL\n");
	}
}
