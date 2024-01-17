#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integer
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ee, *Ipoint, *te;


	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	ee = (*list)->next;

	while (ee != NULL)
	{
		Ipoint = ee;

		while (Ipoint->prev != NULL && Ipoint->n < Ipoint->prev->n)
		{
			/* Swap nodes */
			te = Ipoint->prev;
			Ipoint->prev = te->prev;
			te->prev = Ipoint;
			te->next = Ipoint->next;
			Ipoint->next = te;

			if (te->next != NULL)
				te->next->prev = te;

			if (Ipoint->prev != NULL)
				Ipoint->prev->next = Ipoint;
			else
				*list = Ipoint;

			print_list(*list);
		}

		ee = ee->next;
	}
}
