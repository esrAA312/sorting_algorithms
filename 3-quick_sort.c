#include "sort.h"

/**
 * sw_ap_int - Swap two integers in an array.
 * @es: The first integer to swap.
 * @yu: The second integer to swap.
 */
void sw_ap_int(int *es, int *yu)
{
	int te;

	te = *es;
	*es = *yu;
	*yu = te;
}

/**
 * par_t - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @fir: The starting index of the subset to order.
 * @las: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int par_t(int *array, size_t size, size_t fir, size_t las)
{
	int pivot;
	size_t up, dow;

	pivot = array[las];
	up = dow = fir;
	while(dow < las)
	{


		if (array[dow] < pivot)
		{
			if (up < dow)
			{
				sw_ap_int(array + dow, array + up);
				print_array(array, size);
			}
			up++;
		}

		dow++;
	}

	if (array[up] > pivot)
	{
		sw_ap_int(array + up, array + las);
		print_array(array, size);
	}

	return (up);
}

/**
 * sort_om - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @fir: The starting index of the array partition to order.
 * @las: The ending index of the array partition to order.
 *
 */
void sort_om(int *array, size_t size, int fir, int las)
{
	int pro;

	if (las - fir > 0)
	{
		pro = par_t(array, size, fir,las);
		sort_om(array, size, fir, pro - 1);
		sort_om(array, size, pro + 1, las);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_om(array, size, 0, size - 1);
}
