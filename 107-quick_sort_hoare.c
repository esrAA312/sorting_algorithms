#include "sort.h"

/**
 * par - Implements the partition step in Hoare's QuickSort algorithm.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @L: The lower index of the partition.
 * @H: The higher index of the partition.
 * Return: The index of the pivot after partitioning.
 */
int par(int *array, size_t size, int L, int H)
{
	int P, i, j, te;

	P = array[H];
	i = L - 1;
	j = H + 1;

	while (i < j)
	{
		while (array[++i] < P)
			;

		while (array[--j] > P)
			;

		if (i < j)

		{
			te = array[i];
			array[i] = array[j];
			array[j] = te;
			print_array(array, size);
		}
	}

	return (i);
}
/**
 * elp - Recursive function for QuickSort.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 * @L: The lower index of the current subarray.
 * @H: The higher index of the current subarray.
 */

void elp(int *array, size_t size, int L, int H)
{
	int P_in;

	if (L < H)
	{
		P_in = par(array, size,  L, H);
		elp(array, size, L, P_in - 1);
		elp(array, size, P_in, H);
	}
}
/**
 * quick_sort_hoare - Hoare's QuickSort Implementation.
 * @array: The array of integers to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	elp(array, size, 0, size - 1);
}
