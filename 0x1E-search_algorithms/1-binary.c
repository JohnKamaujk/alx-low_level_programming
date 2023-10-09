#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using binary search.
 * @array: A pointer to the first element of the sorted array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The index of 'value' is , or -1 if not found/ 'array' is NULL.
 *
 * Description:function prints the subarray every time it changes.
 */
int binary_search(int *array, size_t size, int value)
{
	int left, right, mid, i;

	if (array == NULL)
		return (-1);

	right = size - 1;
	left = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;

		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			if (i == left)
				printf("%d", array[i]);
			else
				printf(", %d", array[i]);
		}
		printf("\n");

		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}
