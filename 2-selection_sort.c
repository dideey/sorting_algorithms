#include "sort.h"
/**
 * get lenght of array(n)
 * iterate through the whole array
 * initialise the smallest number as the number in the first index(i)
 * compare (i) < (i + 1) update smallest
 * swap the smallest with (i)
 * now iterate through the array from (i + 1) till you reach last index then array is sorted
 * 
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, min;
    for(i = 0; i < size - 1; i++)
    {
    {

        min = i;
        for(j = i + 1; j < size; j++)
        {
            if(array[j] < array[min])
                min = j;
        }
    }
    
    if(min != i)
    {
        swap(&array[i], &array[min]);
        print_array(array, size);
    }

    }
}