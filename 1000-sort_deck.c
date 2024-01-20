#include "deck.h"
#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * compare_cards - Compare two cards for sorting
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *((const deck_node_t **)a);
	const deck_node_t *node_b = *((const deck_node_t **)b);

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	return (node_a->card->value[0] - node_b->card->value[0]);
}

/**
 * sort_deck - Sort a deck of cards using the Bubble Sort algorithm
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *ptr1 = *deck;
	deck_node_t *lptr = NULL;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	if (deck == NULL || *deck == NULL)
		return;

	do

	{
		swapped = 0;
		ptr1 = *deck;

		while (ptr1->next != lptr)
		{
			if (compare_cards(&ptr1, &ptr1->next) > 0)
			{
				swap_nodes(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}
