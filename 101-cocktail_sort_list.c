#include "sort.h"
#include <stdbool.h>
/**
<<<<<<< HEAD
 * S_node_A - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @Til: A pointer .
 * @SH: A pointer  .
 */
void S_node_A(listint_t **list, listint_t **Til, listint_t **SH)
{
	listint_t *tmpe = (*SH)->next;

	if ((*SH)->prev != NULL)
		(*SH)->prev->next = tmpe;
	else
		*list = tmpe;
	tmpe->prev = (*SH)->prev;
	(*SH)->next = tmpe->next;
	if (tmpe->next != NULL)
		tmpe->next->prev = *SH;
	else
		*Til = *SH;
	(*SH)->prev = tmpe;
	tmpe->next = *SH;
	*SH = tmpe;
}

/**
 * S_node_B - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @Til: A pointer .
 * @SH: A pointer.
 */
void S_node_B(listint_t **list, listint_t **Til, listint_t **SH)
{
	listint_t *t = (*SH)->prev;

	if ((*SH)->next != NULL)
		(*SH)->next->prev = t;
	else
		*Til = t;
	t->next = (*SH)->next;
	(*SH)->prev = t->prev;
	if (t->prev != NULL)
		t->prev->next = *SH;
	else
		*list = *SH;
	(*SH)->next = t;
	t->prev = *SH;
	*SH = t;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list .
=======
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
>>>>>>> 751d1c51fb8ba1ff5b58f78629cee03db9b4a30d
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
<<<<<<< HEAD
	listint_t *Til, *SH;
	bool CHK = false;

	if (!list || !*list || (*list)->next == NULL)
		return;

	Til = *list;
	while (Til->next != NULL)
		Til = Til->next;

	while (!CHK)
	{
		CHK = true;
		SH = *list;
		while (Til != SH)
		{
			if (SH->n > SH->next->n)
			{
				S_node_A(list, &Til, &SH);
				print_list((const listint_t *)*list);
				CHK = false;
			}
			SH = SH->next;
		}
		for (SH = SH->prev; *list != SH;
				SH = SH->prev)
		{
			if (SH->n < SH->prev->n)
			{
				S_node_B(list, &Til, &SH);
				print_list((const listint_t *)*list);
				CHK = false;
=======
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
>>>>>>> 751d1c51fb8ba1ff5b58f78629cee03db9b4a30d
			}
		}
	}
}
