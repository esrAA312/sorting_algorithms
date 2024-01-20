
/**
 *sort_deck - Sort a deck
 *using Bubble Sort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	int EE;
	deck_node_t *current;
	deck_node_t *last = NULL;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	do

	{
		EE = 0;
		current = *deck;

		while (current->next != last)
		{
			if (current->card->kind > current->next->card->kind ||
					(current->card->kind == current->next->card->kind &&
					 gema(current) > gema(current->next)))
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

				EE = 1;
			}
			else
			{
				current = current->next; } }
		last = current;
	} while (EE);
}

/**
 * _strcmp - Compares two strings.
 * @X: The first string to be compared.
 * @X2: The second string to be compared.
 * Return: Positive byte difference if X > X2
 * Return X == X2
 * Negative byte difference if s1 < s2
 */
/**
 * st_rcmp - a Function that ...
 * @X: Description of X.
 * @X2: Description of X2.
 * Return: Description of the return value.
 */
int st_rcmp(const char *X, const char *X2)
{
	for (; *X && *X2 && *X == *X2; X++, X2++)
	{
	}

	return (*X - *X2);
}

/**
 * gema - Get the numerical value.
 * @card: A pointer to a deck_node_t card.
 * Return: The numerical value of the card.
 */
char gema(deck_node_t *card)
{
	int i;
	char *geem[] = {"Ace", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen"};

	for (i = 0; i < 13; ++i)

{
		if (st_rcmp(card->card->value, geem[i]) == 0)
{
			return (i);
		}
	}

	return (13);
}

