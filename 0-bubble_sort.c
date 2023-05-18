#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp, swap;

	if (array == NULL || size == 0)
		return;

	/* loop to access each array element */
	for (j = 0; j < size - 1; j++)
	{
		swap = 0;
		/* loop to compare array elements */
		for (i = 0; i < size - j - 1; i++)
		{
			/* compare two adjacent elements (ascending order) */
			if (array[i] > array[i + 1])
			{
				/* swap if elements are not in the intended order */
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}

		if (swap == 0)
			break;
	}
}
