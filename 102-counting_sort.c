#include "sort.h"

#define MAX_VALUE 100  /* Adjust the maximum value as needed */

/**
 * counting_sort - Sorts an array of integers
 *			in ascending order using the Counting sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	char output[size];
	int *count = (int *)malloc((MAX_VALUE + 1) * sizeof(int));
	int i;

	if (count == NULL)
	{
		fprintf(stderr, "Failed to allocate memory\n");
		return;
	}

	for (i = 0; i <= MAX_VALUE; ++i)
		count[i] = 0;

	for (i = 0; i < (int)size; ++i)
		++count[array[i]];

	for (i = 1; i <= MAX_VALUE; ++i)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; --i)
	{
		output[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < (int)size; ++i)
		array[i] = output[i];


	/* Print the count array */
	print_array(count, MAX_VALUE + 1);
}
