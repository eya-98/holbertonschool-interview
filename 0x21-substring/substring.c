#include "substring.h"
/**
* find_substring - finds all possible substrings containing a list of words
* @s: string to scan
* @words: array of words all substrings must be concatenation arrangement of
* @nb_words: number of elements in array words
* @n: address at which to store nmbr of elements in returned array
* Return: allocated array, storing each index in s else NULL
*/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (s == NULL)
		return (NULL);
int j, k;
unsigned int i;
int *elements, *substrings;
	*n = 0;
	substrings = malloc(nb_words * sizeof(int));
	elements = malloc(strlen(s) * sizeof(int));
	for (i = 0; i <= (strlen(s) - nb_words * strlen(words[0])); i++)
{
		for (j = 0; j < nb_words; j++)
			substrings[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (k = 0; k < nb_words; k++)
			{
				if (substrings[k] == 0 &&
					strncmp(s + i + j * strlen(words[0]), words[k], strlen(words[0])) == 0)
				{
					substrings[k] = 1;
					break;
				}
			}
			if (k == nb_words)
				break;
		}
		if (j == nb_words)
			elements[(*n)++] = i;
	}
	free(substrings);
	return (elements);
}
