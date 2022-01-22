#include "holberton.h"

/**
 * printerror - Prints message when an error occurs.
 **/
void printerror(void)
{
	int pointer = 0;
	char *error = "Error";

	while (error[pointer] != '\0')
	{
		_putchar(error[pointer]);
		pointer++;
	}

	_putchar('\n');
	exit(98);
}

/**
 * _isDigit - Checks if the character is a digit.
 * @character: Character to check
 * Return: 1 if the character is a digit, 2 if
 * the character equal to 45 otherwise 0
 **/
int _isDigit(char character)
{
	if (character >= 48 && character <= 57)
		return (1);
	if (character == 45)
		return (2);
	return (0);
}

/**
 * _strlen - returns the length of a string
 * @string: The string
 * Return: length of the string
 **/
int _strlen(char *string)
{
	int pointer = 0;

	while (string[pointer] != '\0')
		pointer++;

	return (pointer);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: the arguments
 * Return: returns 0 if everything is fine otherwise 98
 **/
int main(int argc, char **argv)
{
	int charpointer, num, first, second, zero;

	if (argc != 3)
		printerror();

	first = _strlen(argv[1]);
	second = _strlen(argv[2]);

	for (num = 1; num <= 2; num++)
	{
		charpointer = 0;
		zero = 0;
		while (argv[num][charpointer] != '\0')
		{
			if ((_isDigit(argv[num][charpointer]) == 0) ||
					(_isDigit(argv[num][charpointer]) == 2 && charpointer != 0) ||
					(_isDigit(argv[num][charpointer]) == 2 && _strlen(argv[num]) == 1))
				printerror();
			if (argv[num][charpointer] != '0')
				zero++;
			charpointer++;
		}
		if (zero == 0)
		{
			_putchar('0');
			_putchar('\n');
			return (0);
		}
	}

	multiply(argv[1], argv[2], first, second);
	return (0);
}

/**
 * multiply - Multiply two numbers and return the res as a string
 * @nb1: first number
 * @nb2: second number
 * @firstlength: length of first number
 * @secondlength: length of second number
 **/
void multiply(char *nb1, char *nb2, int firstlength, int secondlength)
{
	int *res = NULL;
	int a = 0, b = 0, counter = 0, counter2 = 0;
	int _nb1 = 0, _nb2 = 0, sum = 0, next = 0, i = 0;

	res = malloc(sizeof(int) * (firstlength + secondlength + 1));

	for (a = firstlength - 1, b = secondlength - 1, counter = 0, counter2 = 0;
			a >= 0; counter++, a--, counter2 = 0)
	{
		_nb1 = nb1[a] - '0';

		for (b = secondlength - 1, next = 0; b >= 0; b--, counter2++)
		{
			_nb2 = nb2[b] - '0';

			sum = _nb1 * _nb2 + next + res[counter + counter2];
			next = sum / 10;

			res[counter + counter2] = sum % 10;
		}

		if (next > 0)
			res[counter + counter2] += next;
	}

	i = firstlength + secondlength + 1;

	while (res[i] == 0)
		i--;

	for (; i >= 0; i--)
		_putchar(res[i] + '0');
	_putchar('\n');
}

