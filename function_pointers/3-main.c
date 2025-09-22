#include "3-calc.h"

/**
 * main - simple calculator
 * @argc: args count
 * @argv: args vector
 * Return: 0 on success, exits with 98/99/100 on errors
 */
int main(int argc, char *argv[])
{
	int a, b;
	int (*op)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = get_op_func(argv[2]);
	if (!op || argv[2][1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	b = atoi(argv[3]);
	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	a = atoi(argv[1]);
	printf("%d\n", op(a, b));
	return (0);
}

