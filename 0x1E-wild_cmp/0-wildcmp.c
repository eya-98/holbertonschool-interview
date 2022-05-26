#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: first string to compare
 * @s2: second string to compare that can contain the special character *
 * Return: 1 if strings are identical, else 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (!*s2);
	}
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	return (0);
}
