#include "sort.h"

#define INCREMENT 1
#define DECREMENT -1

listint_t *dlistint_last(listint_t *h);
void swap_nodes(listint_t **list, listint_t *node);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail shaker sort
 *
 * @list: Pointer to a pointer to the first element of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *left_limit = NULL, *right_limit = NULL;
	int cycle = INCREMENT;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	left_limit = current;
	right_limit = dlistint_last(*list);

	while (left_limit != right_limit)
	{
		if (current->n == current->next->n)
			break;
		else if (current->n > current->next->n && cycle == INCREMENT)
			swap_nodes(list, current), print_list(*list);
		else if (current->next->n < current->n && cycle == DECREMENT)
			swap_nodes(list, current), current = current->prev, print_list(*list);
		else if (cycle == INCREMENT)
			current = current->next;
		else if (cycle == DECREMENT)
			current = current->prev;

		if (cycle == DECREMENT && current->next == left_limit)
		{
			cycle = INCREMENT;
			current = current->next;
		}

		if (cycle == INCREMENT && current->prev == right_limit)
		{
			right_limit = right_limit->prev;
			cycle = DECREMENT;
			current = current->prev;
		}
	}
}

/**
  * dlistint_last - Gets the last element of a doubly linked list
  * @head: The doubly linked list
  *
  * Return: The last element of the doubly linked list
  */
listint_t *dlistint_last(listint_t *head)
{
	listint_t *last_node = head;

	while (last_node->next != NULL)
		last_node = last_node->next;

	return (last_node);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: Pointer to a pointer to the first element of the list
 * @node: First node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev_node = node->prev;
	listint_t *next_node = node->next;

	if (prev_node)
		prev_node->next = next_node;
	else
		*list = next_node;

	if (next_node)
		next_node->prev = prev_node;

	node->prev = next_node;
	if (next_node)
		node->next = next_node->next;
	else
		node->next = NULL;

	if (node->prev)
		node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}
