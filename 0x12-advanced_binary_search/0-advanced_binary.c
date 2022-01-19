#include "search_algos.h"
/**
 * print_array - Prints an array of integers
 * @array: The first element of the array
 * @start: The start of printing
 * @end: The end of printing
 **/
void print_array(int *array, size_t start, size_t end)
{
size_t pointer = start;
printf("Searching in array: ");
while (pointer <= end)
{
printf("%d", array[pointer]);
if (pointer != end)
{
printf(", ");
}
pointer++;
}
printf("\n");
}
/**
 * binary_search - A function that finds the first item in
 * a sorted array
 * @array: The array to search in
 * @start: The start of searching
 * @end: The end of searching
 * @value: The item to be searched
 * Return: index of the finded element
 **/
int binary_search(int *array, size_t start, size_t end, int value)
{
size_t middle = (int)((start + end) / 2);
print_array(array, start, end);
if (value == array[start])
return (start);
else if (middle >= end)
return (-1);
else if (value <= array[middle - 1])
{
return (binary_search(array, start, middle, value));
}
else if (value >= array[middle + 1])
{
return (binary_search(array, middle + 1, end, value));
}
return (-1);
}
/**
 * advanced_binary - Searches for an item in a sorted array of integers.
 * @array: The array to search in
 * @size: length of the array
 * @value: is the value to be search
 * Return: returns the index of the item
 **/
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
return (binary_search(array, 0, size - 1, value));
}
