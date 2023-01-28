#include "deck.h"
#include <stdio.h>
/**
 *_strcmp - compare two strings
 *@str1: string
 *@str2: string
 *Return: 1 str1 and str2 is equal, 0 they are not equal
 */OOA
int _strcmp(const char *str1, char *str2)
{
	size_t x = 0;

	if (str1 == '\0')
		return (0);
	while (str1[x])
	{
		if (str1[x] != str2[x])
			return (0);
		x++;
	}
	if (str1[x] == '\0' && str2[x])
		return (0);
	return (1);
}
/**
 * get_card_position - return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int get_card_position(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}
/**
 *swap_card - swap a card for his previous one
 *@card: card
 *@deck: card deck
 *Return: return a pointer to a card
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * @deck: Dobule linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int prev_v, current_v;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing the previous value */
		if (node->prev)
		{
			prev_v = get_card_position((node->prev));
			current_v = get_card_position(node);
		}
		while ((node->prev) && (prev_v > current_v))
		{
			prev_v = get_card_position((node->prev));
			current_v = get_card_position(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}
