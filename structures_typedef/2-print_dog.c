#include "dog.h"
#include <stdio.h>
#include <stddef.h>

/**
 * print_dog - prints a struct dog
 * @d: pointer to struct dog
 *
 * Description: If an element of d is NULL, it prints (nil)
 * instead of the element. If d itself is NULL, nothing is printed.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	printf("Age: %f\n", d->age);

	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}

