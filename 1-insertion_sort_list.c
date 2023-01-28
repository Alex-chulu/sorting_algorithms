#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: list of node
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
