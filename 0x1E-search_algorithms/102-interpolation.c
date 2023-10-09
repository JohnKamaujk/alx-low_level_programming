#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array
 *                        of integers using interpolation search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t left = 0, right = size - 1, pos;

	if (array == NULL)
		return (-1);

	while (left <= right)
	{
		pos = left + (((double)(right - left) / (array[right] - array[left]))
			* (value - array[left]));

		if (pos < size)
		{
			printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

			if (array[pos] == value)
				return (pos);

			if (array[pos] > value)
				right = pos - 1;
			else
				left = pos + 1;
		}
		else
		{
			printf("Value checked array[%lu] is out of range\n", pos);
			break;
		}
	}

	return (-1);
}
