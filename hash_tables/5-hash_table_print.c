#include "hash_tables.h"
#include <stdio.h>

/**
 * hash_table_print - Prints a hash table in dict-like form
 * @ht: pointer to hash table
 *
 * Description: Prints in the order of array indices; within each
 * bucket, follows the linked list order (head to tail). If @ht is
 * NULL, prints nothing. Always ends with a newline. Empty table -> {}.
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur;
	int first = 1;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", cur->key, cur->value);
			first = 0;
			cur = cur->next;
		}
	}
	printf("}\n");
}

