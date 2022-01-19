#include "sort.h"

/**
 * heap - Finds the biggest element
 * @array: Pointer to array
 * @n: size of array
 * @counter: index
 * @size: size
 */
void heap(int *array, size_t n, int counter, size_t size)
{
int bigger = counter;
int left = 2 * counter + 1;
int right = 2 * counter + 2;
int Element;
if (left < (int) n && array[left] > array[bigger])
bigger = left;
if (right < (int) n && array[right] > array[bigger])
bigger = right;
if (bigger != counter)
{
Element = array[counter];
array[counter] = array[bigger];
array[bigger] = Element;
print_array(array, size);
heap(array, n, bigger, size);
}
}

/**
 * heap_sort - sorts an array in ascending order
 * @array: array of integers to be sorted
 * @size: size of the array to be sorted
 */
void heap_sort(int *array, size_t size)
{
int counter, Element;
if (size == 0)
	return;
for (counter = size / 2 - 1; counter >= 0; counter--)
	heap(array, size, counter, size);
for (counter = size - 1; counter > 0; counter--)
	{
	Element = array[0];
	array[0] = array[counter];
	array[counter] = Element;
	print_array(array, size);
	heap(array, counter, 0, size);
	}
}
