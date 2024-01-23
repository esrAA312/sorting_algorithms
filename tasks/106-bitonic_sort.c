#include "sort.h"
/**
 * merge - Sort a bitonic.
 * @array: An array of integers.
 * @size: The size of the array.
 * @S: The size of the sequence to sort.
 * @dr: The direction to sort in.
 */
void merge(int *array, size_t size, size_t S, int dr)
{
	size_t i = 0, H = S / 2;
	int t;

	if (S ? S > 1 : 0)

	{
		while (i < H)
		{
			if (dr == 1) {
				if (array[i] > array[i + H]) {
					t = array[i];
					array[i] = array[i + H];
					array[i + H] = t;
				}
			} else if (dr == 0) {
				if (array[i] < array[i + H]) {
					t = array[i];
					array[i] = array[i + H];
					array[i + H] = t;
				}
			}

			i++;
		}
		merge(array, size , H, dr);
		merge(array +H, size, H, dr);
	}
}

/**
 * bi_seq -into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @S: The size of a block 
 * @dr: The direction to sort the bitonic sequence block in.
 */
void bi_seq(int *array, size_t size, size_t S, int dr)
{
	size_t hal = S / 2;

	char *str;


	if (dr == 1) {
		str = "UP";
	} else {
		str = "DOWN";
	}

	if (S ? S > 1 : 0)

	{
		printf("Merging [%lu/%lu](%s):\n", S, size, str);
		print_array(array, S);

		bi_seq(array, size, hal, 1);
		bi_seq(array + hal, size,hal, 0);
		merge(array, size, S, dr);

		printf("Result [%lu/%lu] (%s):\n", S, size, str);
		print_array(array, S);
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

	bi_seq(array, size, size, 1);
}
