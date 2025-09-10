#include "main.h"

/**
 * sqrt_helper - helper function to find sqrt recursively
 * @n: number to find sqrt of
 * @guess: current guess
 *
 * Return: sqrt if found, -1 otherwise
 */
int sqrt_helper(int n, int guess)
{
	if (guess * guess > n)
		return (-1);
	if (guess * guess == n)
		return (guess);
	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: number
 *
 * Return: natural sqrt of n, or -1 if not found
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}

