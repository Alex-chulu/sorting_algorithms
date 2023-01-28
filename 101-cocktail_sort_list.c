#include "sort.h"
#include <stdio.h>
/**
 *swap_node - swap a node for its previous one
 *@node: the node
 *@list: node list
 *Return: return a pointer to a node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back_node = node->prev, *current_node = node;
	/*NULL, 19, 48, 9, 71, 13, NULL*/

	back_node->next = current_node->next;
	if (current_node->next)
		current_node->next->prev = back_node;
	current_node->next = back_node;
	current_node->prev = back_node->prev;
	back_node->prev = current_node;
	if (current_node->prev)
		current_node->prev->next = current_node;
	else
		*list = current_node;
	return (current_node);
}
/**
 *cocktail_sort_list - cocktail sort implementation
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swaped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swaped == 1)
	{
		swaped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swaped = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swaped == 0)
			break;
		swaped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swaped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
