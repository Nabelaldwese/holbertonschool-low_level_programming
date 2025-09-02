#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char tmp;

	/* احسب طول السلسلة */
	while (s[j] != '\0')
		j++;

	/* j الآن هو الطول -> آخر اندكس = j-1 */
	j--;

	/* بدّل الأحرف من البداية والنهاية */
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

