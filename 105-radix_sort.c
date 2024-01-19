#include "sort.h"

/**
 * radix_sort - Sorts using LSD radix sort
 * @array: The array to sort
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int MAX;
	int multe ;

	if (array == NULL || size < 2)
		return;

	MAX = Maxval(array, size);
	multe = 1;

	while (MAX / multe > 0)
	{
		CSort(array, size, multe);
		print_array(array, size);
		multe *= 10;
	}
}

/**
 * Maxval - Returns the maximum element from an array
 * @array: The array to find the maximum element from
 * @size: The size of the array
 * Return: The maximum element
 */
int Maxval(int *array, size_t size)
{
	int Mx_va = array[0];
	size_t X = 1;

	while (X < size)
	{
		if (array[X] > Mx_va)
			Mx_va = array[X];
		X++;
	}

	return (Mx_va);
}

/**
 * CSort - Performs counting sort
 * @array: The array to sort
 * @size: The size of the array
 * @multe: The current significant digit 
 */
void CSort(int *array, size_t size, int multe)
{
	int *mal, *cal, j;
	size_t i;

	mal = malloc(sizeof(int) * size);
	cal = calloc(10, sizeof(int));

	if (mal == NULL || !cal)
	{
		free(mal);
		free(cal);
		return;
	}

	i = 0;
	while (i < size)
	{
		cal[(array[i] / multe) % 10]++;
		i++;
	}

	j = 1;
	while (j < 10)
	{
		cal[j] += cal[j - 1];
		j++;
	}

	j = size - 1;
	while (j >= 0)
	{
		mal[cal[(array[j] / multe) % 10] - 1] = array[j];
		cal[(array[j] / multe) % 10]--;
		j--; }
	i = 0;
	while (i < size)
	{
		array[i] = mal[i];
		i++; }
	free(mal);
	free(cal);
}
