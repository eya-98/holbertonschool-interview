#include "palindrome.h"
/**
 * is_palindrome - A function that checks
 * if a given unsigned integer is a palindrome.
 * @n: Unsigned integer
 * Return: 1 or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long rest = 0;
	unsigned long value = n;
	while (value != 0)
	{
		rest += value % 10;
		value /= 10;
		if (value != 0)
			rest *= 10;
	}
	if (rest == n)
		return (1);
	return (0);
}