#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: integer value of the string, or 0 if no number found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			; /* ignore */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			res = res * 10 - (s[i] - '0');
		}
		else if (started)
			break;
		i++;
	}

	if (sign > 0)
		return (-res);
	return (res);
}

