#include "list/list.h"

#include <stdio.h>

int main(void)
{
	list_t* list = create_list();
	list->head = create_node(0);

	for(int i = 1; i < 25; i++)
	{
		insert_at_head(list, create_node(i));
	}

	list->head = reverse_list(list);

	remove_node(list, 11);

	print_list(list);

	printf("Head: %d\n"
		   "Tail: %d\n"
		   "Length: %d\n",
		   list->head->value,
		   list->tail->value,
		   list->length);

	node_t* temp = find_node(list, 10);
	printf("find node with value: %d\n", temp->value);

	free_list(list);
	return 0;
}
