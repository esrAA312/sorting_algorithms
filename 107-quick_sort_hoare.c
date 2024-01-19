#include <stdio.h>
#include "sort.h"

int partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;
	j = high + 1;

	while (i < j)
	{
		while (array[++i] < pivot)
			;

		while (array[--j] > pivot)
			;

		if (i < j)

		{
			temp = array[i];
			array[i] =array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	return (i);
}

void quick_sort_helper(int *array, size_t size, int low, int high) 
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size,  low, high);
		quick_sort_helper(array, size,  low, pivot_index - 1);
		quick_sort_helper(array, size, pivot_index, high);
	}
}

void quick_sort_hoare(int *array, size_t size) {
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, size, 0, size - 1);
}
