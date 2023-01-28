#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble sort algorithm
 * @array: array to be printed
 * @size: array size
 */

void bubble_sort(int *array, size_t size)
{

	size_t x, idx, tmp = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		for (idx = 0; idx < size; idx++)
		{
			if (array[idx] > array[idx + 1] && array[idx + 1])
			{
			tmp = array[idx];
			array[idx] = array[idx + 1];
			array[idx + 1] = tmp;
			print_array(array, size);
			}
		}
}
