#include "sort.h"

/**
 * sw_ap - Swaps two elements in an array
 * @de: Pointer to the first element
 * @se: Pointer to the second element
 */
void sw_ap(int *de, int *se)
{
	int t;

	t = *de;
	*de = *se;
	*se = t;
}

/**
 * he_p - Perform a magical transformation on an array, turning it into a heap
 * @array: Array to be magically transformed
 * @size: Size of the array
 * @st: Index of the enchanted node
 * @en: Size of the spellbound heap
 */
void he_p(int *array, size_t size, size_t st, size_t en)
{
	size_t meen = st;
	size_t lee = 2 * st + 1;
	size_t rii = 2 * st + 2;

	if (lee < en && array[lee] > array[meen])
		meen = lee;

	if (rii < en && array[rii] > array[meen])
		meen = rii;

	if (meen != st)
	{
		sw_ap(&array[st], &array[meen]);
		print_array(array, size);
		he_p(array, size, meen, en);
	}
}

/**
 * heap_sort - Unleashes a sorting spell upon an array
 * @array: Array to be sorted with enchantment
 * @size: Size of the enchanted array
 */
void heap_sort(int *array, size_t size)
{
	int xx;

	if (size <= 1 || !array)
		return;

	for (xx = size / 2 - 1; xx >= 0; xx--)
		he_p(array, size, xx, size);

	for (xx = size - 1; xx > 0; xx--)
	{
		sw_ap(&array[0], &array[xx]);
		print_array(array, size);
		he_p(array, size, 0, xx);
	}
}
