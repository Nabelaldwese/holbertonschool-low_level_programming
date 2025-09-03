#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination string, must have enough space
 * @src: source string to append
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* Find the end of dest */
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	/* Append src to dest */
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add terminating null byte */
	dest[i] = '\0';

	return (dest);
}

