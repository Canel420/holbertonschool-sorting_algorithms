#include "sort.h"

/**
 * partition - Function defines and sets a pivot for array splitting.
 *
 * @array: array to split.
 * @low: index of first element.
 * @high: index of last element.
 * @size: array size.
 *
 * Description: takes an array and finds a pivot element
 * according to lomuto's scheme.
 *
 * Return: index of split pivot element.
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t i = 0, j = 0;
	int tmp = 0, pivot = 0;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (array[high] < array[i])
	{
		tmp = array[i];
		array[i] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * q_sort - Function that sorts an array of integers.
 *
 * @array: array to sort.
 * @low: first element index.
 * @high: last element index
 * @size: size of the array.
 *
 * Description: sorts each part of a partitioned array.
 *
 */
void q_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if  (low < high)
	{
		pivot = partition(array, low, high, size);
		q_sort(array, low, pivot - 1, size);
		q_sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Function that make a call to quick sort.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description: checks that the array has more than 2 elements
 * and call the quick sort function.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
