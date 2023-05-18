#include "sort.h"

void swap(int *n1, int *n2);

/**
 * selection_sort - Sorts an array of integers in ascending order
 *              using the Selection sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min, temp;

	if (array == NULL || size == 0)
		return;

	/* loop to access each array element */
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)		/* loop to access each array element */
		{
			if (array[j] < array[min])		/* Select the minimum element in each loop */
				min = j;
		}

		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}

}
