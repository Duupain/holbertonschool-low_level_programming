#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * write_in_file - Write text of "file_to" in "file_from"
 * @file_to: Read the content
 * @file_from: Write the content
 * @args: Arguments of program
 */
void write_in_file(int file_to, int file_from, char **args)
{
	int readBytes;
	char buffer[1024];

	while ((readBytes = read(file_from, buffer, 1024)) > 0)
	{
		if (write(file_to, buffer, readBytes) != readBytes)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", args[2]);
			close(file_to);
			close(file_from);
			exit(99);
		}
	}

	if (readBytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", args[1]);
		close(file_to);
		close(file_from);
		exit(98);
	}
}

/**
 * main - Copie content of a file in other file
 * @argc: Number of arguments
 * @argv: Program arguments
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	int file_to, file_from;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(file_from);
		exit(99);
	}

	write_in_file(file_to, file_from, argv);

	if (close(file_from) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
