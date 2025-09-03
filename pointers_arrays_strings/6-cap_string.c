#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @str: string to modify
 *
 * Return: pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0, j;
	char sep[] = " \t\n,;.!?\"(){}";

	while (str[i] != '\0')
	{
		/* إذا كان أول حرف في النص */
		if (i == 0 && (str[i] >= 'a' && str[i] <= 'z'))
			str[i] -= 32;

		/* تحقق من الفواصل */
		for (j = 0; sep[j] != '\0'; j++)
		{
			if (str[i] == sep[j] && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			{
				str[i + 1] -= 32;
			}
		}
		i++;
	}

	return (str);
}

