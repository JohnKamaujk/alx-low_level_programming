#include "search_algos.h"

/**
 * linear_search - Search for a value in an integer array using linear search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of 'value' in 'array' if found,
 *         or -1 if 'value' is not present or 'array' is NULL.
 *
 * Description: function prints each value checked during the search process.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

	if (array == NULL)
		return (-1);

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}

	return (-1);
}
