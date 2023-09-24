#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *head = *list;

	if (list == NULL || *list == NULL)
		return;

	while (head->next)
	{
		temp = head->next;

		if (head->n > temp->n)
		{
			swap_node(list, &head, temp);
			print_list(*list);

			/* nested loop to continue looping through until sorted */
			while (head->prev != NULL && head->prev->n > head->n)
			{
				swap_node(list, &(head->prev), head);
				print_list(*list);
			}
		}
		else
		{
			head = head->next;
		}
	}
}


void swap_node(listint_t **list, listint_t **a, listint_t *b)
{
	listint_t *current, *temp, *temp_next;

	if (*list == NULL || *a == NULL || b == NULL)
		return;

	if (*a == b)
		return;

	current = *a;
	temp = b;

	if (current->prev == NULL)
	{
		/* if first node (a) is the head node */
		if (temp->next != NULL)
			temp->next->prev = current;

		current->next = temp->next;
		temp->next = current;
		temp->prev = NULL;
		current->prev = temp;
		*list = temp;
	}

	else if (temp->next == NULL)
	{
		/* if second node is last node */
		current->prev->next = temp;
		temp->prev = current->prev;
		current->prev = temp;
		temp->next = current;
		current->next = NULL;
	}

	else
	{
		/* General case */
		temp_next = temp->next;
		temp->next = current;
		current->prev->next = temp;
		temp->prev = current->prev;
		current->next = temp_next;
		temp_next->prev = current;
		current->prev = temp;
	}
}
