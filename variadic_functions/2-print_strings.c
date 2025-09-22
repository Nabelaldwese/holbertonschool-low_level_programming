#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings separated by a separator, then newline
 * @separator: string printed between strings (ignored if NULL)
 * @n: number of strings passed
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *s;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, char *);
		if (s == NULL)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator && i < n - 1)
			printf("%s", separator);
	}
	va_end(ap);
	printf("\n");
}

