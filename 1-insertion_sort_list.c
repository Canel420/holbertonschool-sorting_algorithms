#include "sort.h"

/**
 * insertion_sort_list - Function that sorts a doubly linked list.
 * 
 * @list: doubly linked list to sort
 * 
 * Description: sorts a doubly linked list in 
 * ascending order using the Insertion sort algorithm
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *current = NULL, *tmp = NULL;

    current = *list;
    if (current->next == NULL)
        return;

    current = current->next;

    while (current)
    {
        while (current->prev && current->n < (current->prev)->n)
        {
            tmp = current;
            if (current->next)
                (current->next)->prev = tmp->prev;
            (current->prev)->next = tmp->next;
            current = current->prev;
            tmp->prev = current->prev;
            tmp->next = current;
            if (current->prev)
                (current->prev)->next = tmp;
            current->prev = tmp;
            if (tmp->prev == NULL)
                *list = tmp;
            print_list(*list);
            current = current->prev;
        }
        current = current->next;
    }

}