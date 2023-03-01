#include "main.h"

/**
 * _strncat - concatenates n bytes from a string to another
 * @first: destination string
 * @src: source string
 * @n: number of bytes of str to concatenate
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *first, char *src, int n)
{
	int i, j;

	i = 0;
	j = 0;

	while (first[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		first[i] = src[j];
		i++;
		j++;
	}

	first[i] = '\0';

	return (first);
}
