#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted singly linked list
 *             of integers using the jump search algorithm.
 * @list: A pointer to the head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: (NULL) If the value is not present or the head of the list is NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t jump_step, i;
	listint_t *current, *prev;

	if (list == NULL || size == 0)
		return (NULL);

	jump_step = sqrt(size);
	current = list;
	prev = NULL;

	while (current != NULL && current->n < value)
	{
		prev = current;
		for (i = 0; i < jump_step && current->next != NULL; i++)
			current = current->next;

		printf("Value checked at index [%ld] = [%d]\n", current->index, current->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
	       prev->index, current->index);

	while (prev != NULL && prev->index <= current->index)
	{
		printf("Value checked at index [%ld] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
