#include "node.h"

#include <stdlib.h>

node_t* create_node(int value)
{
	node_t* node = malloc(sizeof(node_t));
	node->value = value;
	node->next = NULL;
	return node;
}

void free_node(node_t* node)
{
	if(node != NULL)
	{
		free(node);
	}
}
