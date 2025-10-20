#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieve the value associated with a key
 * @ht: pointer to hash table
 * @key: key to search for (non-NULL, non-empty)
 *
 * Return: pointer to value string if found, otherwise NULL
 *
 * Note: The returned pointer is owned by the table; do NOT free it.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *cur;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	cur = ht->array[idx];

	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
			return (cur->value);
		cur = cur->next;
	}
	return (NULL);
}

