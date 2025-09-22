#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: string name
 * @f: pointer to function that takes a string
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == 0 || f == 0)
		return;

	f(name);
}

