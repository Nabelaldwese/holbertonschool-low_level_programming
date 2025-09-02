#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string
 *
 * Return: integer value of string, or 0 if no numbers
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;     /* +1 أو -1 حسب عدد علامات السالب */
	int started = 0;  /* متى بدأنا نقرأ أرقام */
	int res = 0;      /* نبني القيمة دائماً كسالب لتفادي مشكلة INT_MIN */

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] == '+')
			; /* تجاهل */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			/* ابنِ القيمة كسالب: res = res*10 - digit */
			res = res * 10 - (s[i] - '0');
		}
		else if (started)
			break; /* توقف بعد انتهاء كتلة الأرقام */
		i++;
	}

	/* إن كانت الإشارة موجبة أعد -res، وإلا أعد res كما هو */
	return (sign > 0) ? -res : res;
}

