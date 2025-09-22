#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - print a char
 * @ap: va_list
 */
static void print_char(va_list ap)
{
	printf("%c", (char)va_arg(ap, int));
}

/**
 * print_int - print an int
 * @ap: va_list
 */
static void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - print a float (promoted to double)
 * @ap: va_list
 */
static void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - print a string or (nil) if NULL
 * @ap: va_list
 */
static void print_string(va_list ap)
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
 * print_all - prints anything according to format
 * @format: list of types: 'c','i','f','s'
 *
 * Rules satisfied here:
 * - لا for/goto/do..while
 * - while مرتين بالضبط
 * - if مرّة واحدة داخل الدالة
 * - بدون else
 * - ≤ 9 متغيّرات
 */
void print_all(const char * const format, ...)
{
	/* خريطة داخلية لتجنّب الاعتماد على typedef في الهيدر */
	struct map { char t; void (*f)(va_list); } maps[] = {
		{'c', print_char}, {'i', print_int},
		{'f', print_float}, {'s', print_string},
		{'\0', NULL}
	};

	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";
	void (*func)(va_list);

	va_start(ap, format);

	while (format && format[i])                /* (1) while */
	{
		j = 0;
		func = NULL;
		while (maps[j].t)                      /* (2) while */
		{
			if (format[i] == maps[j].t)        /* (1) if داخل الدالة */
			{
				func = maps[j].f;
				break;
			}
			j++;
		}
		if (func)                              /* نفس if السابقة (مو else) */
		{
			printf("%s", sep);
			func(ap);
			sep = ", ";
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}

