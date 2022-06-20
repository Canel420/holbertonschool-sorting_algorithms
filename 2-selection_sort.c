#include "sort.h"

/**
 * swap - Swap to values
 *
 * @left: value on the left.
 * @right: value on the right.
 *
 * Description: Takes to values and exchange
 * its positions.
 */
void swap(int *left, int *right)
{
	int tmp = 0;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

/**
 * selection_sort - Function that sorts an array of integers.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description:  sorts in ascending order using
 * the Selection sort algorithm
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, jmin = 0;

	if (!array || size < 2)
		return;

	for (; i < size - 1; i++)
	{
		jmin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[jmin])
				jmin = j;
		}
		if (jmin != i)
		{
			swap(&array[i], &array[jmin]);
			print_array(array, size);
		}
	}
}
