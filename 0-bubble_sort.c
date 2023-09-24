#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - Implementation of the Bubble Sort Algorithm
 * @array: Array to be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int swap_flag;
	size_t i;

	if (size < 2)
		return;

	do {
		swap_flag = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				swap_flag = 1;

				print_array(array, size);
			}
		}

	} while (swap_flag);
}

/**
 * swap - Function to swap two indexes in an Array
 * @a: first index
 * @b: second index
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
