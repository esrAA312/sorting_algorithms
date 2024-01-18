#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t G, i, j;
	int te;

	if (array == NULL || !size)
		return;


	for (G = 1; G <= (size - 1) / 3; G = G * 3 + 1)
		;

	while (G > 0)
	{

		for (i = G; i < size; i++)
		{
			te = array[i];

			for (j = i; j >= G && array[j - G] > te; j -= G)
			{
				array[j] = array[j - G];
			}

			array[j] = te;
		}


		print_array(array, size);


		G = (G - 1) / 3;
	}
}

