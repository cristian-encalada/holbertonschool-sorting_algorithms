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
	size_t i, step, aux;

	/* loop to access each array element */
	for (step = 0; step < size - 1; step++)
	{
		/* loop to compare array elements */
		for (i = 0; i < size - step - 1; i++)
		{
			/* compare two adjacent elements (ascending order) */
			if (array[i] > array[i + 1])
			{
				/* swap if elements are not in the intended order */
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				print_array(array, size);
			}
		}
	}
}