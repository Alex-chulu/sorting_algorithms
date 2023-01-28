#include "sort.h"
/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t x, index, tmp = 0;

	if (size < 2)
		return;
	for (x = 0; x < size; x++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
}
