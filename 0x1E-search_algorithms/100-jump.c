#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array
 *               of integers using jump search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 *              Uses the square root of the array size as the jump step.
 */
int jump_search(int *array, size_t size, int value)
{
	int jump_step, prev_index, current_index;

	if (array == NULL || size == 0)
		return (-1);

	jump_step = (int)sqrt(size);
	prev_index = 0;
	current_index = 0;

	while (current_index < (int)size && array[current_index] < value)
	{
		printf("Value checked array[%d] = [%d]\n",
			current_index, array[current_index]);
		prev_index = current_index;
		current_index += jump_step;
	}

	printf("Value found between indexes [%d] and [%d]\n",
		prev_index, current_index);

	/* Ensure we don't go beyond the array size */
	current_index = current_index < (int)size ? current_index : (int)size - 1;

	while (prev_index < current_index && array[prev_index] < value)
	{
		printf("Value checked array[%d] = [%d]\n", prev_index, array[prev_index]);
		prev_index++;
	}
	printf("Value checked array[%d] = [%d]\n", prev_index, array[prev_index]);

	if (array[prev_index] == value)
		return (prev_index);

	return (-1);
}
