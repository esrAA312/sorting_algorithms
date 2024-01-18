#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_ints(int *a, int *b);
void selection_sort(int *array, size_t size);
void sw_ap_int(int *es, int *yu);
int par_t(int *array, size_t size, size_t fir, size_t las);
void sort_om(int *array, size_t size, int fir, int las);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void MER(int *array, int *te, size_t arrle, size_t Mle, size_t arri);
void recsort(int *array, int *te, size_t arrle, size_t arri);
void merge_sort(int *array, size_t size);
#endif
