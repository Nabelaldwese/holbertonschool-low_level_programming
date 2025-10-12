#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: address of pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* حذف أول عقدة */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* التنقل حتى نصل للعقدة المطلوبة */
	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* لو ما لقينا العقدة */
	if (temp == NULL)
		return (-1);

	/* تعديل الروابط قبل وبعد العقدة المحذوفة */
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}

