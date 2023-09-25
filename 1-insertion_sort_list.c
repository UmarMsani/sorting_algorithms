#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 *
 * @list: A pointer to the pointer of the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);

			prev = current->prev;
		}

		current = temp;
	}
}
