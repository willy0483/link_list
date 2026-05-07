#include "list/list.h"

int main(void)
{
	list_t* list = create_list();
	list->head = create_node(0);
	list->tail = list->head;

	for(int i = 1; i < 25; i++)
	{
		insert_at_tail(list, create_node(i));
	}

	//list->head = reverse_list(list);
	//remove_node(list, 11);
	//clear_list(list);

	print_list(list);

	// node_t* temp = find_node(list, 10);
	// printf("find node with value: %d\n", temp->value);

	free_list(list);
	return 0;
}
