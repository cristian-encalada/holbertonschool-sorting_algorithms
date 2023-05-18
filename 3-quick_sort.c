#include "sort.h"

/**
 * swap - Swaps two integers.
 * 
 * @a: The first integer.
 * @b: The second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme.
 * 
 * @array: The array to be partitioned.
 * @low: The starting index of the partition range.
 * @high: The ending index of the partition range.
 * @size: The size of the array.
 * 
 * Return: The partition index.
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i, j;
	int pivot;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[high], &array[i + 1]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort.
 * 
 * @array: The array to be sorted.
 * @low: The starting index of the range to be sorted.
 * @high: The ending index of the range to be sorted.
 * @size: The size of the array.
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order
 *							using the QuickSort algorithm.
 * 
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
