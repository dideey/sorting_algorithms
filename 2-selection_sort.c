#include "sort.h"

/**
 * selection_sort - the implimentation of this algorithm
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
		{

			min = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min])
					min = j;
			}
		}

		if (min != i)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
		}

	}
}
