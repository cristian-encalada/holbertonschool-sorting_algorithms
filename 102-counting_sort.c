#include "sort.h"

/**
 * counting_sort - Sorts an array of integers
 *			in ascending order using the Counting sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 * Assume that array will contain only numbers >= 0
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count;	/* auxiliar arrays */
	int i, max;

	max = array[0];
	for (size_t i = 1; i < size; i++)	/* Find the max value in the input array */
	{
		if (array[i] > max)
			max = array[i];
	}
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
		free(output);
	}
	/* Initialize all the elements of the count array to 0 */
	for (i = 0; i <= max; i++)
		count[i] = 0;
	/* Increment the count for each encountered element */
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	/* Update the count array by adding the count of the previous element */
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	/* Place each element in its correct position in the output array */
	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* Copy the sorted elements from the output array back to the input array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	print_array(count, max + 1);
	free(output);
	free(count);
}
