#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * creates_buffer - Gives 1024 bytes.
 * @file: file name
 * Return: Buffer ptr.
 */

char *creates_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - ends fd.
 * @fd: fd being ended.
 */

void close_file(int fd)
{
	int p;

	p = close(fd);

	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Transfers entries from one file to another
 * @argc: Arguments value supplied to the program.
 * @argv: An arr of pointers to the args.
 *
 * Return: 0 on success.
 *
 * Description: Different value codes are given for different scenarios.
 */

int main(int argc, char *argv[])
{
	int from, to, j, m;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	j = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || j == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		m = write(to, buffer, j);
		if (to == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		j = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (j > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}

