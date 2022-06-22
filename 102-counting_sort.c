#include "sort.h"

/**
 * counting_sort - Function that sorts an array.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description: sorts an array using counting sorting.
 *
 */
void counting_sort(int *array, size_t size)
{
	int max = array[0], *count = NULL, *output = NULL, j = 0;
	size_t i = 0;

	if (!array || size < 2)
		return;

	for (; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max++;
	count = malloc(max * sizeof(int));
	if (count == NULL)
		return;
	for (; j <= max; j++)
		count[j] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (j = 1; j <= max; j++)
		count[j] += count[j - 1];
	print_array(count, max);

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]++;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
