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
 * 
 * Return: The partition index.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low;

	for (int j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			i++;
		}
	}

	swap(&array[i], &array[high]);
	print_array(array, high - low + 1);

	return i;
}

/**
 * quicksort - Recursive function to perform quicksort.
 * 
 * @array: The array to be sorted.
 * @low: The starting index of the range to be sorted.
 * @high: The ending index of the range to be sorted.
 */
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high);

		quicksort(array, low, partition_index - 1);
		quicksort(array, partition_index + 1, high);
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
	quicksort(array, 0, size - 1);
}
