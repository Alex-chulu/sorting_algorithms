#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @size: size of the array
 * @array: an arry
 */
void selection_sort(int *array, size_t size)
{
	size_t x, index;
	int tmp, swap_element, indec = 0;

	if (array == NULL)
		return;
	for (x = 0; x < size; x++)
	{
		tmp = x;
		indec = 0;
		for (index = x + 1; index < size; index++)
		{
			if (array[tmp] > array[index])
			{
				tmp = index;
				indec += 1;
			}
		}
		swap_element = array[x];
		array[x] = array[tmp];
		array[tmp] = swap_element;
		if (indec != 0)
			print_array(array, size);
	}
}
