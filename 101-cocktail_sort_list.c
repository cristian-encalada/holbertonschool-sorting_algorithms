#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail shaker sort
 *
 * @list: Pointer to a pointer to the first element of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	int checks;
	int left = 0;
	int right = 0;
	listint_t *temp;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	do {
		swapped = 0;

		/* Forward pass */
		for (checks = 0; temp->next && checks < right; checks++)
		{
			if (temp->next->n < temp->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
			}
			else
				temp = temp->next;
		}
		right = checks;
		temp = temp->prev; /* Update temp to the last swapped node */

		if (!swapped)
			break;

		/* Backward pass */
		swapped = 0;
		for (checks = 0; temp->prev && checks < left; checks++)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
			}
			else
				temp = temp->prev;
		}
		left = checks;
		temp = temp->next; /* Update temp to the last swapped node */

	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the first element of the list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *swap;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node1->prev = node2;
	swap = node2;
	node1->next = node2->next;
	swap->next = node1;

	print_list(*list);
}
