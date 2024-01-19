
#include "sort.h"
/**
 * get_max - Helper function to find the maximum value in an array
 * @array: Array to find the maximum value from
 * @size: Size of the array
 * Return: Maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * counting_sort - Helper function to perform counting sort on the given digit
 * @array: Array to sort
 * @size: Size of the array
 * @exp: Exponent to get the current digit
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output, *count;
	size_t i;

	output = malloc(sizeof(int) * size);
	count = calloc(10, sizeof(int));


	if (!output || !count)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}

/**
 * radix_sort - Radix sort algorithm (LSD)
 * @array: Array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
		print_array(array, size);
	}
}

