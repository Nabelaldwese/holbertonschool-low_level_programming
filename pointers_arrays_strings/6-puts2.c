#include "main.h"

/**
 * puts2 - prints every other character of a string,
 *         starting with the first character, then newline
 * @str: pointer to the string
 */
void puts2(char *str)
{
	int i, len = 0;

	/* احسب الطول أولاً */
	while (str[len] != '\0')
		len++;

	/* اطبع حرف كل 2 */
	for (i = 0; i < len; i += 2)
		_putchar(str[i]);

	_putchar('\n');
}

