/**
 *sort_deck - Sort a deck of cards from ace to king and
 * from spades to diamonds using Bubble Sort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	int swapped;
	deck_node_t *current;
	deck_node_t *last = NULL;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	do

	{
		swapped = 0;
		current = *deck;

		while (current->next != last)
		{
			if (current->card->kind > current->next->card->kind ||
					(current->card->kind == current->next->card->kind &&
					 get_value(current) > get_value(current->next)))
			{
				if (current->prev != NULL)
					current->prev->next = current->next;
				else
					*deck = current->next;

				current->next->prev = current->prev;
				current->prev = current->next;
				current->next = current->next->next;

				if (current->next != NULL)
					current->next->prev = current;

				current->prev->next = current;

				swapped = 1;
			}
			else
			{
				current = current->next; } }
		last = current;
	} while (swapped);
}



/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 * Return: Positive byte difference if s1 > s2
 * 0 if s1 == s2
 * Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 * Return: The numerical value of the card.
 */
char get_value(deck_node_t *card)
{
	int i;
	char *values[] = {"Ace", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen"};

	for (i = 0; i < 13; ++i) {
		if (_strcmp(card->card->value, values[i]) == 0) {
			return (i);
		}
	}

	return (13);
}
