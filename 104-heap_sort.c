#include "sort.h"
#include <stdio.h>

/**
 * swap - function to swap to integers
 * @a: int a
 * @b: int b
 **/
void swap(int *a, int *b)
{
	int x = *a;

	*a = *b;
	*b = x;
}

/**
 * maxHeapify - The main function to heapify a Max Heap.
 * @array: array
 * @size: array size to print
 * @idx: index
 * @n: size of the array to run
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int larg = idx;		 /* Initialize largest as root*/
	int left = 2 * idx + 1;	 /* left = (idx << 1) + 1*/
	int right = 2 * idx + 2; /* right = (idx + 1) << 1*/

	if (left < (int)n && array[left] > array[larg])
		larg = left;

	if (right < (int)n && array[right] > array[larg])
		larg = right;

	if (larg != idx)
	{
		swap(&array[idx], &array[larg]);
		print_array(array, size);
		maxHeapify(array, size, larg, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: array size
 **/
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == '\0' || size < 2)
		return;

	for (x = (size - 2) / 2; x >= 0; --x)
		maxHeapify(array, size, x, size);

	for (x = (size - 1); x > 0; --x)
	{

		swap(&array[0], &array[x]);
		print_array(array, size);

		maxHeapify(array, size, 0, x);
	}
}
