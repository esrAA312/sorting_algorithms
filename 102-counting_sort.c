#include "sort.h"
/**
 * find_maximum - Find the maximum value in array
 * @arr: An array of integers.
 * @len: The length of the array.
 * Return: The maximum integer in the array.
 */
int find_maximum(int *arr, int len)
{
	int maximumee, idxee;

	maximumee = arr[0];
	idxee = 1;
	while (idxee < len)
	{
		if (arr[idxee] > maximumee)
			maximumee = arr[idxee];
		idxee++; }
	return (maximumee); }
/**
 * counting_sort - Arrange an array of integers in ascending order
 * @array: An array of integers.
 * @size: The length of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counteryy, *sorted_arryy, maximumyy, idxyy;

	if (array == NULL || size < 2 || !size)
		return;
	sorted_arryy = malloc(sizeof(int) * size);
	if (sorted_arryy == NULL)
		return;
	maximumyy = find_maximum(array, size);
	counteryy = malloc(sizeof(int) * (maximumyy + 1));
	if (counteryy == NULL)
	{
		free(sorted_arryy);
		return; }
	idxyy = 0;
	while (idxyy < (maximumyy + 1))
	{
		counteryy[idxyy] = 0;
		idxyy++; }
	idxyy = 0;
	while (idxyy < (int)size)
	{
		counteryy[array[idxyy]] += 1;
		idxyy++; }
	idxyy = 0;
	while (idxyy < (maximumyy + 1))
	{
		counteryy[idxyy] += counteryy[idxyy - 1];
		idxyy++; }
	print_array(counteryy, maximumyy + 1);
	idxyy = 0;
	while (idxyy < (int)size)
	{
		sorted_arryy[counteryy[array[idxyy]] - 1] = array[idxyy];
		counteryy[array[idxyy]] -= 1;
		idxyy++; }
	idxyy = 0;
	while (idxyy < (int)size)
	{array[idxyy] = sorted_arryy[idxyy];
			idxyy++; }
	free(sorted_arryy);
	free(counteryy); }
