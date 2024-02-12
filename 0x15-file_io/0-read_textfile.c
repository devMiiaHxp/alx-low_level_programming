#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Send text to STDOUT.
 * @filename: file to take acton on
 * @letters: amount of times to be read
 * Return:amount of bytes read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *x;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	x = malloc(sizeof(char) * letters);
	t = read(fd, x, letters);
	w = write(STDOUT_FILENO, x, t);

	free(x);
	close(fd);
	return (w);
}

