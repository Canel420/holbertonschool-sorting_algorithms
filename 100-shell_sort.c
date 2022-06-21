#include "sort.h"

/**
 * shell_sort - Function that sorts an array.
 *
 * @array: array to sort.
 * @size: size of the array.
 *
 * Description: sorts an array using shell sorting
 * with Knuth sequence as gaps.
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0, j = 0;
	int tmp = 0;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
