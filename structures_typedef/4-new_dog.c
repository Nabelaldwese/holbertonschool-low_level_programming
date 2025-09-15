#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - get length of a C string
 * @s: string (must be non-NULL)
 *
 * Return: length of s
 */
static int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - copy a C string
 * @dest: destination buffer (enough space)
 * @src: source string
 *
 * Return: dest
 */
static char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - create a new dog (deep copy of fields)
 * @name: dog's name
 * @age: dog's age
 * @owner: owner's name
 *
 * Description: Allocates a struct dog and makes copies of the two
 * strings. If any allocation fails, frees what was allocated and
 * returns NULL.
 *
 * Return: pointer to new dog_t, or NULL on failure or NULL inputs
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int ln, lo;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(*d));
	if (d == NULL)
		return (NULL);

	ln = _strlen(name);
	lo = _strlen(owner);

	d->name = malloc((unsigned int)ln + 1);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc((unsigned int)lo + 1);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}

