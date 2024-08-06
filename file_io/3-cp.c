#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * print_error - Prints an error message to stderr and exits.
 * @exit_code: The exit code to use when exiting the program.
 * @message: The error message to print.
 * @filename: The filename to include in the error message.
 */
void print_error(int exit_code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	exit(exit_code);
}

/**
 * write_in_file - Write text from "file_from" to "file_to".
 * @file_from: The file descriptor to read from.
 * @file_to: The file descriptor to write to.
 * @args: Arguments of the program.
 */
void write_in_file(int file_from, int file_to, char **args)
{
	ssize_t readBytes, writeBytes;
	char buffer[1024];

	while ((readBytes = read(file_from, buffer, 1024)) > 0)
	{
		writeBytes = write(file_to, buffer, readBytes);
		if (writeBytes != readBytes)
		{
			print_error(99, "Error: Can't write to", args[2]);
		}
	}

	if (readBytes == -1)
	{
		print_error(98, "Error: Can't read from file", args[1]);
	}
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, otherwise the respective error code.
 */
int main(int argc, char **argv)
{
	int file_from, file_to;

	if (argc != 3)
	{
		print_error(97, "Usage: cp file_from file_to", "");
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		print_error(98, "Error: Can't read from file", argv[1]);
	}

	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close(file_from);
		print_error(99, "Error: Can't write to", argv[2]);
	}

	write_in_file(file_from, file_to, argv);

	if (close(file_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	if (close(file_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}

	return (0);
}
