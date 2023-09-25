#include "sort.h"
/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	int max, i, j;

	if (array == NULL || size < 2)
		return;
	max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(int) * size);

	if (count_array == NULL || output_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (j = 0; j < (int)size; j++)
		count_array[array[j]]++;

	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	for (j = (int)size - 1; j >= 0; j--)
	{
		output_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	for (j = 0; j < (int)size; j++)
		array[j] = output_array[j];

	printf("Counting array: ");
	for (i = 0; i <= max; i++)
		printf("%d%c", count_array[i], (i == max) ? '\n' : ',');
	free(count_array);
	free(output_array);
}
