#include <stdlib.h>
#include "lists.h"

/**
 * free_list - free a list_t list
 * @head: pointer to the head of the list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		/* save next node pointer */
		temp = head->next;

		/* free string then the node */
		free(head->str);
		free(head);

		head = temp;
	}
}

