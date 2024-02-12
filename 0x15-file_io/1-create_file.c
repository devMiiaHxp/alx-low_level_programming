#include "main.h"

/**
 * create_file - make file
 * @filename: ptr
 * @text_content: A ptr to final loop
 *
 * Return: If the function fails - -1.
 * Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, i, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	i = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	i = write(fd, text_content, len);

	if (fd == -1 || i == -1)
		return (-1);

	close(fd);

	return (1);
}

