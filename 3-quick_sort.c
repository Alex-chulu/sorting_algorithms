#include "sort.h"
/**
*swap - positions of two elements in an array
*@array: an array
*@item1: array item 1
*@item2: array item 2
*/
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - partition sorting method
 *@array: an array
 *@first: array item 1
 *@last: last array item
 *@size: size of the array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current_arr = first, arr_finder;

	for (arr_finder = first; arr_finder < last; arr_finder++)
	{
		if (array[arr_finder] < pivot)
		{
			if (array[current_arr] != array[arr_finder])
			{
				swap(array, current_arr, arr_finder);
				print_array(array, size);
			}
			current_arr++;
		}
	}
	if (array[current_arr] != array[last])
	{
		swap(array, current_arr, last);
		print_array(array, size);
	}
	return (current_arr);
}
/**
 *qs - quicksort algorithm
 *@array: an array
 *@first: 1st array item
 *@last: last array item
 *@size: size of the array
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pos = 0;


	if (first < last)
	{
		pos = lomuto_partition(array, first, last, size);

		qs(array, first, pos - 1, size);
		qs(array, pos + 1, last, size);
	}
}
/**
 *quick_sort - prepalation for the quicksort algorithm
 *@array: an array
 *@size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
