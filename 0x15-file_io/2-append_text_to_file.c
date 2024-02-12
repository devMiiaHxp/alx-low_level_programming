#include "main.h"

/**
 * append_text_to_file - Adds text to end of file
 * @filename: pointer to file identification
 * @text_content: last stringg in title
 * Return: failure? filename is NULL - -1.
 *         File dont exist - -1.
 *         Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int o, w, x = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (x = 0; text_content[x];)
			x++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, x);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}

