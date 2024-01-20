#include <stdlib.h>
#include <string.h>
#include "deck.h"

int compare_cards(const void *a, const void *b) 
{
	int value_a, value_b;
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	const card_t *card_a = node_a->card;
	const card_t *card_b = node_b->card;


	if (card_a->kind != card_b->kind)
	{
		return card_a->kind - card_b->kind;
	} else
	{

		if (strcmp(card_a->value, "Ace") == 0)
		{
			value_a = 1;
		} else if (strcmp(card_a->value, "King") == 0) {
			value_a = 13;
		} else if (strcmp(card_a->value, "Queen") == 0) {
			value_a = 12;
		} else if (strcmp(card_a->value, "Jack") == 0) {
			value_a = 11;
		} else {
			value_a = atoi(card_a->value);
		}

		if (strcmp(card_b->value, "Ace") == 0) {
			value_b = 1;
		} else if (strcmp(card_b->value, "King") == 0) {
			value_b = 13;
		} else if (strcmp(card_b->value, "Queen") == 0) {
			value_b = 12;
		} else if (strcmp(card_b->value, "Jack") == 0) {
			value_b = 11;
		} else {
			value_b = atoi(card_b->value);
		}

		return value_a - value_b;
	}
}

void sort_deck(deck_node_t **deck) 
{
	deck_node_t **nodes;	
	deck_node_t *current = *deck;
	int i, count;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;
	while (current != NULL) 
	{
		count++;
		current = current->next;
	}

	nodes = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
	current = *deck;
	for (i = 0; i < count; i++) 
	{
		nodes[i] = current;
		current = current->next;
	}

	qsort(nodes, count, sizeof(deck_node_t *), compare_cards);

	*deck = nodes[0];
	current = *deck;
	current->prev = NULL;
	for ( i = 1; i < count; i++) 
	{
		current->next = nodes[i];
		nodes[i]->prev = current;
		current = current->next;
	}
	current->next = NULL;

	free(nodes);
}
