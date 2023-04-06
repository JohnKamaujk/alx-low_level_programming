#include "main.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int limit;
	int moves;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (limit = n, moves = 0; (limit >>= 1) > 0; moves++)
	;
	for (; moves >= 0; moves--)
	{
		if ((n >> moves) & 1)
			printf("1");
		else
			printf("0");
	}
}
