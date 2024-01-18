#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, Idx;
	int temp;

	if (array == NULL || size == NULL)
		return ();
	i = 0;

	while (i < size - 1)
	{
		Idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[Idx])
				Idx = j;
		}

		if (Idx != i)
		{
			swap_ints(array[i], array[Idx]);
			print_array(array, size);
		}

		i++;
	}
}

/**
 * swap_ints - Swap two integers in an array.
 * @aX: The first integer to swap.
 * @bX: The second integer to swap.
 */
void swap_ints(int *aX, int *bX)
{
	int tmp;

	tmp = *aX;
	*aX = *bX;
	*bX = tmp;
}
