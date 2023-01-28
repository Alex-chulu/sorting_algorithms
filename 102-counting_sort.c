#include "sort.h"
#include <stdio.h>
/**
 *_calloc - calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int x = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return ('\0');
	p = malloc(nmemb * size);
	if (p == '\0')
		return ('\0');
	for (x = 0; x < (nmemb * size); x++)
		p[x] = '\0';
	return (p);
}
/**
 * counting_sort - counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int index, maximun = 0, *counter = '\0', *tmp = '\0';
	size_t x;

	if (array == '\0' || size < 2)
		return;
	/* find maximun number */
	for (x = 0; x < size; x++)
		if (array[x] > maximun)
			maximun = array[x];
	counter = _calloc(maximun + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));
	for (x = 0; x < size; x++)
		counter[array[i]]++;
	for (index = 1; index <= maximun; index++)
		counter[index] += counter[index - 1];
	print_array(counter, maximun + 1);
	for (x = 0; x < size; ++x)
	{
		tmp[counter[array[x]] - 1] = array[x];
		counter[array[x]]--;
	}
	for (x = 0; x < size; x++)
		array[x] = tmp[x];
	free(tmp);
	free(counter);

}
