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
	int i, j, temp;
	size_t interval = 1;

	if (array == NULL || size == 0)
		return;

	/* Calculate the initial interval using Knuth's sequence */
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= (int)interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}

			array[j] = temp;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}

