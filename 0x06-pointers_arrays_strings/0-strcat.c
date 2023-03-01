#include "main.h"

/**
 * _strcat - concatenates two strings
 * @first: string to append to
 * @add: string to add
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *first, char *add)
{
	int i, j;

	i = 0;
	j = 0;

	while (first[i] != '\0')
		i++;

	while (add[j] != '\0')
	{
		first[i] = add[j];
		j++;
		i++;
	}

	first[i] = '\0';

	return (first);
}
