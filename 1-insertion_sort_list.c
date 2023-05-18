#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * 												in ascending order
 *                        using the Insertion sort algorithm
 *
 * @list: Pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr, *next_node, *prev_node;

	curr = (*list)->next;
	while (curr != NULL)
	{
		next_node = curr->next;
		prev_node = curr->prev;

		while (prev_node != NULL && prev_node->n > curr->n)
		{
			prev_node->next = curr->next;

			if (curr->next != NULL)
				curr->next->prev = prev_node;

			curr->prev = prev_node->prev;
			curr->next = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = curr;
			else
				*list = curr;

			prev_node->prev = curr;
			prev_node = curr->prev;
			print_list(*list);
		}

		curr = next_node;
	}
}
