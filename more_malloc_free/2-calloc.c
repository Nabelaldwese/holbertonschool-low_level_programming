#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array using malloc and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory initialized to zero,
 *         or NULL if nmemb/size is 0 or malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;
	p = malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return (p);
}

