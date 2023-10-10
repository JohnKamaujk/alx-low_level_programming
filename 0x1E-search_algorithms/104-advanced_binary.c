#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursive function advanced binary search
 * @array: A pointer to the first element of the array to search.
 * @low: The low index of the search range.
 * @high: The high index of the search range.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of 'value', or -1 if not found.
 */
int advanced_binary_recursive(int *array, size_t low, size_t high, int value)
{
	size_t mid, i;

	if (low > high)
		return (-1);

	mid = low + (high - low) / 2;

	printf("Searching in array: ");
	for (i = low; i <= high; i++)
	{
		printf("%d", array[i]);
		if (i < high)
			printf(", ");
		else
			printf("\n");
	}

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive(array, low, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive(array, mid + 1, high, value));
	else
		return (advanced_binary_recursive(array, low, mid, value));
}

/**
 * advanced_binary - Searches a value in a sorted array usin advanced binary.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of the first occurrence of 'value', or -1 if not found.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
