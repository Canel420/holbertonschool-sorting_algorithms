#include "sort.h"

/**
 * merge - function that sorts an array.
 *
 * @array: array to sort.
 * @start: start index of the array.
 * @middle: middle index of the array..
 * @end: endindex of the array.
 * @copy: array copy.
 *
 * Description: merge two arrays in ascending order.
 */

void merge(int *array, size_t start, size_t middle, size_t end, int *copy)
{
	size_t i = start, j = middle, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, middle - start);
	printf("[rigth]: ");
	print_array(array + middle, end - middle);

	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || array[i] <= array[j]))
		{
			copy[k] = array[i];
			i += 1;
		}
		else
		{
			copy[k] = array[j];
			j += 1;
		}
	}
	printf("[Done]: ");
	print_array(copy + start, end - start);
}

/**
 * split_merge - function that splits an array.
 *
 * @array: array to split.
 * @start: start index of the array.
 * @end: end index of the array.
 * @copy: copy of the array.
 *
 * Description: recursively split an array until each splitting
 * ended up with one element, then call the function merge to
 * order each splited block.
 */
void split_merge(int *array, size_t start, size_t end, int *copy)
{
	size_t middle = 0, i = 0;

	if (end - start < 2)
		return;

	middle  = (end + start) / 2;
	split_merge(array, start, middle, copy);
	split_merge(array, middle, end, copy);
	merge(copy, start, middle, end, array);
	for (i = start; i < end; i++)
		copy[i] = array[i];
}

/**
 * merge_sort - sorts an array.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description: makes a copy of the array to apply
 * merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *copy = NULL;
	size_t i = 0;

	if (!array || size < 2)
		return;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;
	for (; i < size; i++)
		copy[i] = array[i];

	split_merge(array, 0, size, copy);
	free(copy);
}
