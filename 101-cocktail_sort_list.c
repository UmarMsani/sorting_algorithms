#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the linked list
 * @left: Left node to be swapped
 * @right: Right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;

	right->prev = left->prev;
	left->prev = right;
	left->next = right->next;

	if (right->next)
		right->next->prev = left;

	right->next = left;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                     in ascending order using Cocktail shaker sort.
 * @list: Pointer to the pointer of the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		left = *list;

		while (left->next)
		{
			if (left->n > left->next->n)
			{
				swap_nodes(list, left, left->next);
				print_list(*list);
				swapped = 1;
			}
			left = left->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		right = left->prev;

		while (right)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(list, right->prev, right);
				print_list(*list);
				swapped = 1;
			}
			right = right->prev;
		}
	}
}
