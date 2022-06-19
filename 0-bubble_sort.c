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
 * bubble_sort - Function that sorts an array of integers. 
 * 
 * @array: array to sort.
 * @size: size of the array.
 * 
 * Description:  sorts an array of integers in 
 * ascending order using the Bubble sort algorithm. 
 */
void bubble_sort(int *array, size_t size)
{
    size_t i = 0, j = 0, swapped;

    if (array == NULL || size < 2)
        return;

    for (; i < size-1; i++)
    {
        swapped = 0;
        for (j = 0; j < size-i-1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j+1]);
                swapped = 1;
                print_array(array, size);
            }
        }
        if (swapped == 0)
            break;
    }
}