#include "slide_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * swap - swaps two integers
 * @a: pointer
 * @b: pointer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * slide_left - slides to the left,
 * @line: pointer.
 * @size: size of line array
 */
void slide_left(int *line, size_t size)
{
	size_t i, p = 0;
	for (i = 0; i < size && p < size; i++)
	{
		while (line[p] == 0 && p < size && p + 1 < size)
			p++;
		if (line[i] == 0)
			swap(&line[p], &line[i]);
		p++;
	}
}

/**
 * slide_right - slides to the right,
 * @line: pointer.
 * @size: size of line array
 */
void slide_right(int *line, size_t size)
{
	size_t i, p = size - 1;

	for (i = size - 1; (int) i >= 0 && (int) p >= 0; i--)
	{
		while (line[p] == 0 && (int) p > 0)
			p--;
		if (line[i] == 0)
			swap(&line[p], &line[i]);
		p--;
	}
}

/**
 * slide_line - slides and merge integers
 * @line: points to the array
 * @size: number of elements of array
 * @direction: SLIDE_LEFT, SLIDE_RIGHT
 * Return: 1 or 0
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 0; i < size; i++)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] + line[i + 1];
				line[i + 1] = 0;
			}
		}
		slide_left(line, size);
		return (1);
	} else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; (int) i >= 0; i--)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] + line[i - 1];
				line[i - 1] = 0;
			}
		}
		slide_right(line, size);
		return (1);
	}
	return (0);
}