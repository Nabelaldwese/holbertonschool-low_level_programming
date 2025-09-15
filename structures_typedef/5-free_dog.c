#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees memory allocated for a dog_t struct
 * @d: pointer to dog to free
 *
 * Description: Frees name, owner, and the struct itself.
 * If d is NULL, does nothing.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}

