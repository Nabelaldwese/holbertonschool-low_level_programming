#include "function_pointers.h"

/**
 * int_index - searches for an integer using a callback function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to function to compare values
 *
 * Return: index of the first match, or -1 if no match / invalid input
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == 0 || cmp == 0 || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}

