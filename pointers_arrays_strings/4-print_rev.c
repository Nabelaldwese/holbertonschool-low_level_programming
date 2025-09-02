#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string to print
 */
void print_rev(char *s)
{
	int len = 0;

	/* احسب طول السلسلة */
	while (s[len] != '\0')
		len++;

	/* اطبع من الآخر للأول */
	while (len > 0)
	{
		len--;
		_putchar(s[len]);
	}
	_putchar('\n');
}

