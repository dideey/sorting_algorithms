#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current = (*list)->next;

	if (list == NULL || *list == NULL)
		return;

	while (current != NULL)
	{
		temp = current;
		current = current->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			swap_node(list, &(temp->prev), temp);
			print_list(*list);

			if (temp->prev == NULL)
				*list = temp;
		}
	}
}

/**
 * swap_node - Custom Function to swap nodes in a linked list
 * @list: head of linked list
 * @a: node to be swapped (the bigger value)
 * @b: node to be swapped (the smaller value)
 *
 */

void swap_node(listint_t **list, listint_t **a, listint_t *b)
{
	listint_t *current, *temp, *temp_next;

	if (*list == NULL || *a == NULL || b == NULL || (*a == b))
		return;

	current = *a;
	temp = b;

	if (current->prev == NULL)
	{
		if (temp->next != NULL)
			temp->next->prev = current;

		current->next = temp->next;
		temp->next = current;
		temp->prev = NULL;
		current->prev = temp;
		*list = temp;
	}

	else if (temp->next == NULL) /* if second node is last node */
	{
		current->prev->next = temp;
		temp->prev = current->prev;
		current->prev = temp;
		temp->next = current;
		current->next = NULL;
	}

	else /* General Case */
	{
	temp_next = temp->next;
	temp->next = current;
	current->prev->next = temp;
	temp->prev = current->prev;
	current->next = temp_next;
	temp_next->prev = current;
	current->prev = temp;
	}
}
