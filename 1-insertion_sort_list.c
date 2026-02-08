#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next_node, *prev_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        next_node = current->next;
        while (current->prev != NULL && current->prev->n) 
        {
            prev_node = current->prev;

			/* Swap logic starts here */
			
			/* 1. Connect prev_node to current's next */
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;

			/* 2. Move current behind prev_node */
			current->next = prev_node;
			current->prev = prev_node->prev;

			/* 3. Connect prev_node to current */
			prev_node->prev = current;

			/* 4. Connect current's new prev to current */
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current; /* Update head if current is first */

			print_list(*list);
        }
        current = next_node;
    }
}
