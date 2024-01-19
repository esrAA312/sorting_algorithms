#include "sort.h"

/**
 * radix_sort - Sorts using LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max_element;
	int exp;

	if (array == NULL || size < 2)
		return;

	max_element = getMax(array, size);
	exp = 1;

	while (max_element / exp > 0)
	{
		countSort(array, size, exp);
		print_array(array, size);
		exp *= 10;
	}
}

/**
 * getMax - Returns the maximum element from an array
 * @array: The array to find the maximum element from
 * @size: The size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
	int max_val = array[0];
	size_t i = 1;

	while (i < size)
	{
		if (array[i] > max_val)
			max_val = array[i];
		i++;
	}

	return (max_val);
}

/**
 * countSort - Performs counting sort on an array by a given digit (exp)
 * @array: The array to sort
 * @size: The size of the array
 * @exp: The current significant digit to consider
 */
void countSort(int *array, size_t size, int exp)
{
	int *output, *count, j;
	size_t i;

	output = malloc(sizeof(int) * size);
	count = calloc(10, sizeof(int));

	if (output == NULL || !count)
	{
		free(output);
		free(count);
		return;
	}

	i = 0;
	while (i < size)
	{
		count[(array[i] / exp) % 10]++;
		i++;
	}

	j = 1;
	while (j < 10)
	{
		count[j] += count[j - 1];
		j++;
	}

	j = size - 1;
	while (j >= 0)
	{
		output[count[(array[j] / exp) % 10] - 1] = array[j];
		count[(array[j] / exp) % 10]--;
		j--; }
	i = 0;
	while (i < size)
	{
		array[i] = output[i];
		i++; }
	free(output);
	free(count);
}
