#include "sort.h"

/**
 * swap - Swap nodes in a doubly linked list.
 *
 * @list: doubly linked head of list.
 * @node1: first node to swap.
 * @node2: second node to swap.
 *
 * Description: swaps two nodes exchanging its
 * connections to other nodes in list.
 */

void swap(listint_t **list, listint_t *node1, listint_t *node2)
{

	if (node1->prev != NULL)
		(node1->prev)->next = node2;
	else
		*list = node2;
	node2->prev = node1->prev;
	node1->next = node2->next;
	node1->prev = node2;
	node2->next = node1;

	if (node2->next != NULL)
		(node2->next)->prev = node1;
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

	if (!list || *list == NULL)
		return;

	tmp = *list;

	while (swapped != 0)
	{
		swapped = 0;
		while (tmp->next != NULL)
		{
			if ((tmp->next)->n < tmp->n)
			{
				swap(list, tmp, tmp->next);
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
				swap(list, tmp, tmp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
