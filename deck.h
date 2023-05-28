#ifndef _DECK_H_
#define _DECK_H_

/* header files */

#include <stdio.h>	/* to use qsort */
#include <stdlib.h>	/* to use qsort */
#include <string.h> /* to use strcmp */

/* auxiliar structures */

/**
 * enum kind_e - Set of names to represent kinds of cards
 * @SPADE: First type of card, start at index 0
 * @HEART: Second type of card, index 1
 * @CLUB: Third type of card, index 2
 * @DIAMOND: Fourth type of card, index 3
 *
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* function prototypes */
void sort_deck(deck_node_t **deck);

#endif /* _DECK_H_ */
