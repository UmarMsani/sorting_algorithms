#include "sort.h"

/**
 * bubble_sort - Sorts array of integers in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /*Flag to check if any swaps were made in this pass*/

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				/*Swap elements*/
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1; /*Set the flag to true if a swap was made*/
				print_array(array, size);
			}
		}

		/*If no swaps were made in this pass, the array is already sorted*/
		if (swapped == 0)
			break;
	}
}
