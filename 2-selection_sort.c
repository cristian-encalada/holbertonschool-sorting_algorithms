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
	size_t i, step, min_idx;

	if (array == NULL || size == 0)
		return;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			/* Select the minimum element in each loop */
			if (array[i] < array[min_idx])
			min_idx = i;
		}

		/* put min at the correct position */
		swap(&array[min_idx], &array[step]);
		print_array(array, size);
	}

}

/**
 * swap - Helper function to swap two numbers
 *
 * @n1: First integer to be swapped
 * @n2: Second integer to be swapped
 *
 * Return: void
 */
void swap(int *n1, int *n2)
{
	int aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}
