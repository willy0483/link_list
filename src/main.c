#include "list/list.h"
#include <stdio.h>

int main(void)
{
	list_t* list = create_list();

	for(int i = 0; i < 25; i++)
	{
		insert_at_head(list, create_node(i));
	}

	// remove_node(list, 5);
	// clear_list(list);
	// insert_after(list, 10, create_node(100));
	// insert_before(list, 100, create_node(101));

	list->head = reverse_list(list);

	printf("\nHead: %d\n"
		   "Tail: %d\n"
		   "Length: %d\n",
		   list->head ? list->head->value : -1,
		   list->tail ? list->tail->value : -1,
		   list->length);

	print_list(list->head);

	print_node(find_node(list->head, 10));

	free_list(list);
	return 0;
}
