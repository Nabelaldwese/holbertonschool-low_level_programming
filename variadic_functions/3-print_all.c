#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char
 * @ap: variadic list
 */
static void print_char(va_list ap)
{
	printf("%c", (char)va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: variadic list
 */
static void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float (double in varargs)
 * @ap: variadic list
 */
static void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string or (nil) if NULL
 * @ap: variadic list
 *
 * Note: لا نستخدم if/else هنا. نختار بين مؤشرين بمؤشر فهرسة.
 */
static void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);
	char *nil = "(nil)";
	char *opt[2];

	opt[0] = nil;      /* عندما s == NULL سنطبع opt[0] */
	opt[1] = s;        /* عندما s != NULL سنطبع opt[1] */
	printf("%s", opt[s != NULL]);
}

/**
 * print_all - prints anything according to @format
 * @format: list of types: 'c' 'i' 'f' 's'
 *
 * القيود المتحققة هنا:
 * - لا for / goto / do..while / else / ?: .
 * - while = 2 بالضبط.
 * - if = 2 بالضبط داخل هذه الدالة.
 * - <= 9 متغيرات.
 */
void print_all(const char * const format, ...)
{
	/* خريطة محلية لتجنّب الاعتماد على typedef في الهيدر */
	struct map { char t; void (*f)(va_list); } maps[] = {
		{'c', print_char}, {'i', print_int},
		{'f', print_float}, {'s', print_string},
		{'\0', NULL}
	};

	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";
	void (*fn)(va_list);

	va_start(ap, format);

	while (format && format[i])              /* (1) while */
	{
		j = 0;
		fn = NULL;
		while (maps[j].t)                    /* (2) while */
		{
			if (format[i] == maps[j].t)      /* (1) if */
			{
				fn = maps[j].f;
				break;
			}
			j++;
		}
		if (fn)                               /* (2) if */
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

