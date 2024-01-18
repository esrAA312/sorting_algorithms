#include "sort.h"

/**
 * MER - Merges two subarrays of the array.
 * @array: The array to be merged.
 * @te: Temporary array to store merged elements.
 * @arrle: Start index of the left subarray.
 * @Mle: End index of the left subarray.
 * @arri: End index of the right subarray.
 */
void MER(int *array, int *te, size_t arrle, size_t Mle, size_t arri)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + arrle, Mle - arrle);

	printf("[right]: ");
	print_array(array + Mle, arri - Mle);

	i = arrle;
	j = Mle;
	k = 0;

	while (i < Mle && j < arri)
	{
		if (array[i] <= array[j])
			te[k++] = array[i++];
		else
			te[k++] = array[j++];
	}

	while (i < Mle)
		te[k++] = array[i++];

	while (j < arri)
		te[k++] = array[j++];

	for (i = arrle, j = 0; i < arri; i++, j++)
		array[i] = te[j];

	printf("[Done]: ");
	print_array(array + arrle, arri - arrle);
}

/**
 * recsort - Recursively divides and merges the array.
 * @array: The array to be sorted.
 * @te: Temporary array to store merged elements.
 * @arrle: Start index of the subarray.
 * @arri: End index of the subarray.
 */
void recsort(int *array, int *te, size_t arrle, size_t arri)
{
	size_t Mle;

		if (arri - arrle > 1)
		{
			Mle = (arrle + arri) / 2;

			recsort(array, te, arrle, Mle);
			recsort(array, te, Mle, arri);

			MER(array, te, arrle, Mle, arri);
		}
}

/**
 * merge_sort - Sorts an array of integers using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{

	int *te;

	if (array == NULL || !size)
		return;

	te = malloc(size * sizeof(int));

	if (te == NULL)
		return;

	recsort(array, te, 0, size);

	free(te);
}
