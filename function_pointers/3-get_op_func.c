#include "3-calc.h"

/**
 * get_op_func - select the right op function
 * @s: operator string
 * Return: pointer to the matching function, or NULL
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if (*ops[i].op == *s && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}

