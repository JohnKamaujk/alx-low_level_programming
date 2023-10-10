#include "search_algos.h"

/**
 * binary_searching - Searches for a value in a sorted array using binary algo.
 * @array: A pointer to the first element of the sorted array to search.
 * @left: left bound of subarray
 * @right: right bound
 * @value: The value to search for.
 *
 * Return: The index of 'value' is , or -1 if not found/ 'array' is NULL.
 *
 * Description:function prints the subarray every time it changes.
 */
int binary_searching(int *array, size_t left, size_t right, int value)
{
	size_t mid, i;

	if (array == NULL)
		return (-1);

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

/**
  * exponential_search - Searches for a value in a sorted array
  *                      of integers using exponential search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the index where the value is located.
  *
  * Description: Prints a value every time it is compared in the array.
  */
int exponential_search(int *array, size_t size, int value)
{
	size_t i = 0, right, left;

	if (array == NULL || size == 0)
		return (-1);

	if (array[0] != value)
	{
		for (i = 1; i < size && array[i] <= value; i = i * 2)
			printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	}

	right = i < size ? i : size - 1;
	left = i / 2;
	printf("Value found between indexes [%ld] and [%ld]\n", left, right);
	return (binary_searching(array, left, right, value));
}
