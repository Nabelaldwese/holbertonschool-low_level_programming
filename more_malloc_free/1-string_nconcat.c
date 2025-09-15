#include "main.h"
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
static unsigned int _strlen(char *s)
{
    unsigned int len = 0;

    if (s == NULL)
        return (0);

    while (s[len])
        len++;

    return (len);
}

/**
 * string_nconcat - concatenates s1 with first n bytes of s2
 * @s1: first string (NULL treated as "")
 * @s2: second string (NULL treated as "")
 * @n: number of bytes of s2 to use
 *
 * Return: pointer to newly allocated string, or NULL on failure
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

