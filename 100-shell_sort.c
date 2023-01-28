#include "sort.h"

/**
*swap - positions of two elements into an array
*@array: an array
*@item1: array item 1
*@item2: array item 2
*/
void swap(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @size: arry size
 * @array: an arry
 */
void shell_sort(int *array, size_t size)
{
	size_t dif = 1, x, index = 0;

	if (array == NULL || size < 2)
		return;
	while (dif < size / 3)
		dif = 3 * dif + 1;
	while (dif >= 1)
	{
		for (x = dif; x < size; x++)
			for (index = x; index >= dif &&
			 (array[index] < array[index - dif]); index -= dif)
				swap(array, index, index - dif);
		print_array(array, size);
		dif /= 3;
	}
}
