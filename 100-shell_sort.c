#include "sort.h"

void swap(int *n1, int *n2);

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval, temp;

	if (array == NULL || size == 0)
		return;

	/* Rearrange elements at each n/2, n/4, n/8, ... intervals */
	for (interval = size / 2; interval > 0; interval /= 2)
	{
		for (i = interval; i < size; i += 1)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > (int)temp; j -= interval)
			{
				array[j] = array[j - interval];
				print_array(array, size);
			}
			array[j] = temp;
		}
	}
}
