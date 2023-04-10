#include "main.h"

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: A pointer to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Return: If the function fails or filename is NULL - -1.
 *         If the file does not exist the user lacks write permissions - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int opened, written, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
		{
			length++;
		}
	}

	opened = open(filename, O_WRONLY | O_APPEND);
	written = write(opened, text_content, length);

	if (opened == -1 || written == -1)
		return (-1);

	close(opened);

	return (1);
}
