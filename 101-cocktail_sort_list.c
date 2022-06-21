#include "sort.h"

/**
 * swap - Swap nodes in a doubly linked list.
 *
 * @list: doubly linked head of list.
 * @node: node to swap.
 *
 * Description: swaps two nodes exchanging its
 * connections to other nodes in list.
 */

void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - sorts a doubly linked list.
 *
 * @list: doubly linked head node.
 *
 * Description: sorts an array using cocktail sorting.
 * (an extension of bubble sorting)
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *tmp = NULL;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	tmp = *list;

	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if ((tmp->next)->n < tmp->n)
			{
				swap(list, tmp);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (swapped == 0)
			break;

		swapped = 0;
		while (tmp->prev != NULL)
		{
			if ((tmp->prev)->n > tmp->n)
			{
				swap(list, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
