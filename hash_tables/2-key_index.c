#include "hash_tables.h"

/**
 * key_index - Computes the index of a key for a hash table array
 * @key: key as unsigned char *
 * @size: size of the hash table array
 *
 * Return: index within [0 .. size-1]
 *
 * Description: Uses djb2 hash, then maps via modulo size.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

