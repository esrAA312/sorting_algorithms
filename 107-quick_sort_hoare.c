#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort
 *                    with Hoare partition scheme.
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, 0, size - 1, size);
}

/**
 * hoare_quick_sort - Implements Quick sort with Hoare partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: Size of the array
 */
void hoare_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;


	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		hoare_quick_sort(array, low, pivot, size);
		hoare_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * hoare_partition - Partitions the array using Hoare partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do { i++; } while (array[i] < pivot);
		do { j--; } while (array[j] > pivot);

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
		else
			return(j);
	}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 * @size: Size of the array
 * Return: 1 if swapped, 0 otherwise
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
