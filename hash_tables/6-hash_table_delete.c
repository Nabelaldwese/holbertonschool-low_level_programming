#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table and frees all memory
 * @ht: pointer to the hash table
 *
 * Description: Frees every node (key & value), then the array,
 * then the table itself. Safe on NULL.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur, *tmp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			tmp = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = tmp;
		}
	}
	free(ht->array);
	free(ht);
}

