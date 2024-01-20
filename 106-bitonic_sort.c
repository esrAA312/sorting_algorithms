#include "sort.h"
/**
 * bitonic_merge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @seq: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t seq, char flow)
{
	size_t i = 0, jump = seq / 2;
	int tmp;

	if (seq && seq > 1)
	{
		while (i < 0 + jump)
		{
			if ((flow == 1 && array[i] > array[i + jump]) ||
					(flow == 0 && array[i] < array[i + jump]))
				tmp = *(array + i);
			array[i] = array[i + jump];
			array[i + jump] = tmp;
			i++;
		}
		bitonic_merge(array, size, jump, flow);
		bitonic_merge(array, size, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @seq: The size of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == 1) ? "UP" : "DOWN";

	if (seq && seq > 1)
	{
		printf("Merging [%lu/%lu](%s):\n", seq, size, str);
		print_array(array + 0, seq);

		bitonic_seq(array, size, cut, 1);
		bitonic_seq(array, size, cut, 0);
		bitonic_merge(array, size, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + 0, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, size, 1);
}
