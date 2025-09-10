#include "main.h"

/**
 * prime_helper - checks if number is divisible by any number
 * @n: the number to check
 * @d: current divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int prime_helper(int n, int d)
{
	if (d * d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (prime_helper(n, d + 1));
}

/**
 * is_prime_number - returns 1 if the input integer is a prime number
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_helper(n, 2));
}

