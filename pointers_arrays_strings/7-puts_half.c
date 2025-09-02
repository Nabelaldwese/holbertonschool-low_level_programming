#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: pointer to the string
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	/* احسب طول السلسلة */
	while (str[len] != '\0')
		len++;

	/* إذا فردي: (len + 1) / 2، إذا زوجي: len / 2 */
	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	/* اطبع من start للنهاية */
	for (i = start; i < len; i++)
		_putchar(str[i]);

	_putchar('\n');
}

