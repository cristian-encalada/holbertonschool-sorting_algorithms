#include "deck.h"

/**
 * get_card_value_weight - Assigns a numerical weight to a card value
 *
 * @value: The card value to assign a weight to
 *
 * Return: The numerical weight of the card value
 */
int get_card_value_weight(const char *value)
{
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
	};
	const int weights[] = {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
	};
	const int num_values = sizeof(values) / sizeof(values[0]);

	for (int i = 0; i < num_values; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (weights[i]);
	}

	return (0);  /* Default weight if value is not recognized */
}
/**
 * compare_cards - Custom comparison function for sorting cards
 *
 * @card1: Pointer to the first card pointer
 * @card2: Pointer to the second card pointer
 *
 * Return: Negative if card1 < card2, positive if card1 > card2, 0 if equal
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	int kind_diff = c1->kind - c2->kind;

	if (kind_diff != 0)
		return (kind_diff);

	int value_weight1 = get_card_value_weight(c1->value);
	int value_weight2 = get_card_value_weight(c2->value);

	return (value_weight1 - value_weight2);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 *
 * @deck: Pointer to a pointer to the first node of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	deck_node_t *node = *deck;
	card_t *cards[52];

	/* Store card pointers in an array */
	for (i = 0; i < 52; i++)
	{
		cards[i] = (card_t *)node->card;
		node = node->next;
	}

	/* Sort the array of card pointers */
	qsort(cards, 52, sizeof(card_t *), compare_cards);

	/* Update the deck with the sorted cards */
	node = *deck;
	for (i = 0; i < 52; i++)
	{
		node->card = cards[i];
		node = node->next;
	}
}
