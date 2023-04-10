#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_content(char *file);
void close_file(int fd);

/**
 * create_content - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_content(char *file)
{
	char *content = malloc(sizeof(char) * 1024);

	if (content == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (content);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int value = close(fd);

	if (value == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int origin, destination, r, w;
	char *content;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	content = create_content(argv[2]);
	origin = open(argv[1], O_RDONLY);
	r = read(origin, content, 1024);
	destination = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);


	do {
		if (origin == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(content);
			exit(98);
		}

		w = write(destination, content, r);
		if (destination == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(content);
			exit(99);
		}

		r = read(origin, content, 1024);
		destination = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(content);
	close_file(origin);
	close_file(destination);

	return (0);
}
