#include "sort.h"

/**
 * selection_sort - the implementation of this algorithm
 * @array: input array
 * @size: size of array
 * return: void
 */

void selection_sort(int *array, size_t size)
{

	size_t i, j, min;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{

		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}

	}
}

/**
 * swap - function to swap between two indexes of an array
 * @a: first index for swapping
 * @b: second index for swapping
 *
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
