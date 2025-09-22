#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Prints a char argument
 * @ap: variadic list
 */
static void print_char(va_list ap)
{
	printf("%c", (char)va_arg(ap, int));
}

/**
 * print_int - Prints an int argument
 * @ap: variadic list
 */
static void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - Prints a float/double argument
 * @ap: variadic list
 */
static void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - Prints a string or (nil) when NULL (بدون if/else)
 * @ap: variadic list
 */
static void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	char *nil = "(nil)";
	char *opt[2];

	opt[0] = nil;
	opt[1] = s;
	printf("%s", opt[s != NULL]);
}

/**
 * print_all - Prints arguments according to @format: c,i,f,s
 * @format: format string
 *
 * Constraints: no for/goto/else/?:/do..while,
 * exactly 2 while loops and ≤ 2 if in this function, ≤ 9 variables.
 */
void print_all(const char * const format, ...)
{
	/* parallel lookup tables (بدون struct لتجنّب تحذير Betty) */
	char tags[] = {'c', 'i', 'f', 's', '\0'};
	void (*funcs[])(va_list) = {
		print_char, print_int, print_float, print_string, NULL
	};

	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";
	void (*fn)(va_list);

	va_start(ap, format);
	while (format && format[i])          /* (1) while */
	{
		j = 0;
		fn = NULL;
		while (tags[j])                  /* (2) while */
		{
			if (format[i] == tags[j])    /* (1) if */
			{
				fn = funcs[j];
				break;
			}
			j++;
		}
		if (fn)                          /* (2) if */
		{
			printf("%s", sep);
			fn(ap);
			sep = ", ";
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}

