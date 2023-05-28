#include "deck.h"

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

    /* Compare the kind first */
    if (c1->kind < c2->kind)
        return -1;
    else if (c1->kind > c2->kind)
        return 1;

    /* If the kinds are the same, compare the values */
    if (c1->value < c2->value)
        return -1;
    else if (c1->value > c2->value)
        return 1;

    return 0;  /* Cards are equal */
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