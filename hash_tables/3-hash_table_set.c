/* 3-hash_table_set.c */
#include "hash_tables.h"
#include <string.h>

/**
 * make_node - Allocate and initialize a new hash node
 * @key: key string to duplicate (must be non-NULL and non-empty)
 * @value: value string to duplicate (may be empty, but non-NULL)
 *
 * Return: pointer to a freshly allocated node on success, NULL on failure
 *
 * Description: Duplicates @key and @value with strdup, sets next to NULL.
 * Caller owns the node and must free on error paths later.
 */
static hash_node_t *make_node(const char *key, const char *value)
{
	hash_node_t *node;
	char *k, *v;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	k = strdup(key);
	if (k == NULL)
	{
		free(node);
		return (NULL);
	}
	v = strdup(value);
	if (v == NULL)
	{
		free(k);
		free(node);
		return (NULL);
	}

	node->key = k;
	node->value = v;
	node->next = NULL;
	return (node);
}

/**
 * find_node - Find a node by key in a collision chain
 * @head: head of the singly linked list (bucket chain)
 * @key: key to search for
 *
 * Return: pointer to the matching node if found, otherwise NULL
 */
static hash_node_t *find_node(hash_node_t *head, const char *key)
{
	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head);
		head = head->next;
	}
	return (NULL);
}

/**
 * hash_table_set - Adds or updates a (key, value) pair in the hash table
 * @ht: pointer to hash table
 * @key: non-empty key string
 * @value: value string to store (duplicated)
 *
 * Return: 1 on success, 0 on failure
 *
 * Note: In case of collision, inserts the new node at the head of the list.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *slot, *node;
	char *vdup;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	/* update if key already exists */
	slot = find_node(ht->array[idx], key);
	if (slot)
	{
		vdup = strdup(value);
		if (vdup == NULL)
			return (0);
		free(slot->value);
		slot->value = vdup;
		return (1);
	}

	/* insert new node at head (chaining) */
	node = make_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}

