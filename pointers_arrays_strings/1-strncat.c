#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: destination string, must have enough space
 * @src: source string to append
 * @n: maximum number of bytes to use from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of dest */
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append at most n bytes from src */
	j = 0;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add terminating null byte */
	dest[i] = '\0';

	return (dest);
}

