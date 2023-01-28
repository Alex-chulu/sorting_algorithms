#include "sort.h"
#include <stdio.h>
/**
* getMax - function to get maximum value in arr
* @arr: array
* @n: size of the array
* Return: array
*/
int getMax(int *arr, int n)
{
	int x, max = arr[0];

	for (x = 1; x < n; x++)
		if (arr[x] > max)
			max = arr[x];
	return (max);
}

/**
* countSort - A function to do counting sort of arr
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void countSort(int *arr, size_t n, int exp, int *output)
{
	int x;
	int num[10] = {0};

	for (x = 0; x < (int)n; x++)
		num[(arr[x] / exp) % 10]++;

	for (x = 1; x < 10; x++)
		num[x] += num[x - 1];

	for (x = n - 1; x >= 0; x--)
	{
		output[num[(arr[x] / exp) % 10] - 1] = arr[x];
		num[(arr[x] / exp) % 10]--;
	}

	for (x = 0; x < (int)n; x++)
		arr[x] = output[x];
}

/**
* radix_sort - main function that sorts arr
* @array: array
* @size: array size
*/
void radix_sort(int *array, size_t size)
{

	int exp, maximum = 0;
	int *output = '\0';

	if (array == '\0' || size < 2)
		return;

	maximum = getMax(array, size);
	output = malloc(size * sizeof(int));
	if (output == '\0')
		return;

	for (exp = 1; maximum / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
