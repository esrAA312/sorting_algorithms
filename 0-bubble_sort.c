#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int te;
	int swapp;

	if (array == NULL || size  == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{

				te = array[j];
				array[j] = array[j + 1];
				array[j + 1] = te;
				swapp = 1;
				print_array(array, size);
			}
		}


		if (swapp == 0)
			break;
	}
}
