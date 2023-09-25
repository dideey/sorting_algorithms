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
