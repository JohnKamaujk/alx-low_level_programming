#include "search_algos.h"

/**
 * linear_skip - Searches for an algorithm in a sorted singly
 *               linked list of integers using linear skip.
 * @list: A pointer to the head of the linked list to search.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jump step.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *ex_lane;

	if (list == NULL)
		return (NULL);

	for (node = ex_lane = list; ex_lane->next != NULL && ex_lane->n < value;)
	{
		node = ex_lane;
		if (ex_lane->express != NULL)
		{
			ex_lane = ex_lane->express;
			printf("Value checked at index [%ld] = [%d]\n",
				   ex_lane->index, ex_lane->n);
		}
		else
		{
			while (ex_lane->next != NULL)
				ex_lane = ex_lane->next;
		}
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
		   node->index, ex_lane->index);

	while (node->index < ex_lane->index && node->n < value)
	{
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
