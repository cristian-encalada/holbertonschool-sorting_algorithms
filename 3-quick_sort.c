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
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, size);

	return i;
}

/**
 * quicksort - Recursive function to perform quicksort.
 * 
 * @array: The array to be sorted.
 * @low: The starting index of the range to be sorted.
 * @high: The ending index of the range to be sorted.
 * @size: The size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int partition_i;

	if (low < high)
	{
		partition_i = lomuto_partition(array, low, high, size);

		quicksort(array, low, partition_i - 1, size);
		quicksort(array, partition_i + 1, high, size);
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
