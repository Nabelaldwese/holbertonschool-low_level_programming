#include "main.h"
#include <stdlib.h>

/**
 * _strlen - Compute length of a C string.
 * @s: Pointer to string (may be NULL).
 *
 * Return: Length (0 if s is NULL).
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * string_nconcat - Concatenate s1 with the first n bytes of s2.
 * @s1: First string (NULL treated as "").
 * @s2: Second string (NULL treated as "").
 * @n:  Number of bytes from s2 to copy.
 *
 * Return: Pointer to newly allocated string on success, or NULL on failure.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, i, j;
	char *new_str;

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (n >= len2)
		n = len2;

	new_str = malloc(len1 + n + 1);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	for (j = 0; j < n; j++)
		new_str[i + j] = s2[j];

	new_str[i + j] = '\0';

	return (new_str);
}

