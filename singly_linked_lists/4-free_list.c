#include <stdlib.h>
#include "lists.h"

/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 *
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head->next; /* حفظ المؤشر للعقدة التالية */
		free(head->str);   /* تحرير السلسلة النصية داخل العقدة */
		free(head);        /* تحرير العقدة نفسها */
		head = temp;       /* الانتقال للعقدة التالية */
	}
}

