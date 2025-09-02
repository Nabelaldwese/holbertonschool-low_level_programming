#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: integer value of string, or 0 if no numbers
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1;
	int i = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			; /* تجاهل */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started)
			break;
		i++;
	}

	if (sign == -1)
		return (-((int)num));
	else
		return ((int)num);
}

