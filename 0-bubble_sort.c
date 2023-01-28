#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, idx, tmp = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
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
