#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @action: pointer to function to be executed
 *
 * Return: Nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == 0 || action == 0)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}

