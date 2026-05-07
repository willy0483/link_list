#include "list.h"

#include <stdlib.h>
#include <stdio.h>

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

node_t* insert_at_head(list_t* list, node_t* node_to_insert)
{
	node_to_insert->next = list->head;
	list->head = node_to_insert;

	if(list->tail == NULL)
	{
		list->tail = node_to_insert;
	}

	list->length++;

	return node_to_insert;
}

node_t* find_node(list_t* list, int value)
{
	node_t* temp = list->head;
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

node_t* reverse_list(list_t* list)
{
	node_t* prev = NULL;
	node_t* curr = list->head;
	node_t* next = NULL;

	list->tail = list->head;

	while(curr != NULL)
	{
		next = curr->next;

		curr->next = prev;

		prev = curr;
		curr = next;
	}
	return prev;
}

node_t* remove_node(list_t* list, int value)
{
	node_t* prev = NULL;
	node_t* curr = list->head;
	while(curr != NULL)
	{
		if(curr->value == value)
		{
			if(prev == NULL)
			{
				list->head = curr->next;
			}
			else
			{
				prev->next = curr->next;
			}

			if(curr == list->tail)
			{
				list->tail = prev;
			}

			free_node(curr);
			list->length--;
			return list->head;
		}
		prev = curr;
		curr = curr->next;
	}
	return list->head;
}

node_t* insert_at_tail(list_t* list, node_t* node_to_insert)
{

	if(list->tail == NULL)
	{
		list->head = node_to_insert;
		list->tail = node_to_insert;
		list->length++;
		return node_to_insert;
	}
	list->tail->next = node_to_insert;
	list->tail = node_to_insert;
	list->length++;
	return node_to_insert;
}

void clear_list(list_t* list)
{
	node_t* curr = list->head;

	while(curr != NULL)
	{
		node_t* next = curr->next;
		free_node(curr);
		curr = next;
	}

	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
}

void print_list(list_t* list)
{
	node_t* node = list->head;

	if(list->head != NULL && list->tail != NULL)
	{
		printf("Head: %d\n"
			   "Tail: %d\n"
			   "Length: %d\n",
			   list->head->value,
			   list->tail->value,
			   list->length);
	}

	while(node != NULL)
	{
		printf("%d - ", node->value);
		node = node->next;
	}
	printf("\n");
}
