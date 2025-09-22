#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_c - print a char
 * @ap: va_list
 */
void print_c(va_list ap)
{
	printf("%c", (char)va_arg(ap, int));
}

/**
 * print_i - print an int
 * @ap: va_list
 */
void print_i(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_f - print a float (as double from va_arg)
 * @ap: va_list
 */
void print_f(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_s - print a string, or (nil) if NULL
 * @ap: va_list
 */
void print_s(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", s);
}

/**
 * print_all - prints anything according to a format string
 * @format: "c" char, "i" int, "f" float, "s" char *
 *
 * Description: ignores any other characters in format.
 * Constraints satisfied inside this function:
 * - max 2 while loops (we use exactly 2)
 * - max 2 if statements (we use exactly 1 here; the other check is in helpers)
 * - no for/goto/else/ternary/do...while
 */
void print_all(const char * const format, ...)
{
	printer_t p[] = {
		{"c", print_c}, {"i", print_i},
		{"f", print_f}, {"s", print_s},
		{NULL, NULL}
	};
	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";

	va_start(ap, format);

	while (format && format[i])            /* (1) while over format */
	{
		j = 0;
		while (p[j].symbol)                /* (2) while over printer table */
		{
			if (format[i] == *(p[j].symbol))   /* (1) if in this function */
			{
				printf("%s", sep);
				p[j].print(ap);
				sep = ", ";
				break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}

