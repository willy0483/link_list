#include "list.h"

#include <stdlib.h>
#include <stdio.h>

// List core
list_t* create_list()
{
	list_t* list = malloc(sizeof(list_t));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	return list;
}

void free_list(list_t* list)
{
	if(list != NULL)
	{
		if(list->head != NULL)
		{
			node_t* curr = list->head;
			while(curr != NULL)
			{
				node_t* next = curr->next;
				free_node(curr);
				curr = next;
			}
		}
		free(list);
	}
}

void print_list(node_t* node)
{
	printf("\n");

	while(node != NULL)
	{
		printf("%d", node->value);

		if(node->next != NULL)
			printf(" <-> ");

		node = node->next;
	}

	printf("\n");
}

// Insert
node_t* insert_at_head(list_t* list, node_t* node_to_insert)
{

	if(list->head == NULL)
	{
		list->head = node_to_insert;
		list->tail = node_to_insert;
	}
	else
	{
		list->head->prev = node_to_insert;
		node_to_insert->next = list->head;
		list->head = node_to_insert;
	}

	if(list->tail == NULL)
	{
		list->tail = node_to_insert;
	}

	list->length++;
	return node_to_insert;
}

node_t* insert_at_tail(list_t* list, node_t* node_to_insert)
{

	if(list->tail == NULL)
	{
		list->head = node_to_insert;
		list->tail = node_to_insert;
	}
	else
	{
		list->tail->next = node_to_insert;
		node_to_insert->prev = list->tail;
		list->tail = node_to_insert;
	}

	if(list->head == NULL)
	{
		list->head = node_to_insert;
	}

	list->length++;
	return node_to_insert;
}

node_t* insert_after(list_t* list, int value, node_t* node_to_insert)
{
	node_t* temp = list->head;
	while(temp != NULL)
	{
		if(temp->value == value)
		{
			node_to_insert->prev = temp;
			node_to_insert->next = temp->next;

			if(temp->next != NULL)
			{
				temp->next->prev = node_to_insert;
			}
			else
			{
				list->tail = node_to_insert;
			}

			temp->next = node_to_insert;

			list->length++;
			return node_to_insert;
		}
		temp = temp->next;
	}
	return NULL;
}

node_t* insert_before(list_t* list, int value, node_t* node_to_insert)
{
	node_t* temp = list->head;
	while(temp != NULL)
	{
		if(temp->value == value)
		{
			node_to_insert->next = temp;
			node_to_insert->prev = temp->prev;

			if(temp->prev != NULL)
			{
				temp->prev->next = node_to_insert;
			}
			else
			{
				list->head = node_to_insert;
			}

			temp->prev = node_to_insert;

			list->length++;
			return node_to_insert;
		}

		temp = temp->next;
	}

	return NULL;
}

// Delete
void remove_node(list_t* list, int value)
{
	node_t* temp = list->head;
	while(temp != NULL)
	{
		if(temp->value == value)
		{
			if(temp->prev != NULL)
			{
				temp->prev->next = temp->next;
			}
			else
			{
				list->head = temp->next;
			}

			if(temp->next != NULL)
			{
				temp->next->prev = temp->prev;
			}
			else
			{
				list->tail = temp->prev;
			}

			list->length--;
			free_node(temp);
			return;
		}
		temp = temp->next;
	}
}

void clear_list(list_t* list)
{
	node_t* temp = list->head;

	while(temp != NULL)
	{
		node_t* next = temp->next;
		free_node(temp);
		temp = next;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

// Search
node_t* find_node(node_t* head, int value)
{
	node_t* temp = head;
	while(temp != NULL)
	{
		if(temp->value == value)
		{
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

// Algorithms
node_t* reverse_list(list_t* list)
{
	node_t* temp = list->head;
	node_t* prev = NULL;

	list->tail = list->head;

	while(temp != NULL)
	{
		node_t* next = temp->next;

		temp->next = prev;
		temp->prev = next;

		prev = temp;
		temp = next;
	}

	list->head = prev;
	return prev;
}
