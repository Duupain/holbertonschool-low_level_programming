#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_error - Prints an error message to stderr and exits.
 * @exit_code: The exit code to use when exiting the program.
 * @message: The error message to print.
 * @filename: The filename to include in the error message.
 */
void print_error(int exit_code, const char *message, const char *filename)
{
	if (filename[0] != '\0')
		dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	else
		dprintf(STDERR_FILENO, "%s\n", message);
	exit(exit_code);
}

/**
 * write_in_file - Write content from one file descriptor to another.
 * @fd_from: The file descriptor to read from.
 * @fd_to: The file descriptor to write to.
 * @filename_to: The name of the file to write to, used for error messages.
 */
void write_in_file(int fd_from, int fd_to, const char *filename_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
			print_error(99, "Error: Can't write to", filename_to);
	}

	if (bytes_read == -1)
		print_error(98, "Error: Can't read from file", filename_to);
}

/**
 * main - Copies the content of one file to another.
 * @argc: The number of arguments.
 * @argv: The argument vector.
 *
 * Return: 0 on success, otherwise the respective error code.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", "");

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error(98, "Error: Can't read from file", argv[1]);

	// Open the file for writing with the correct permissions
	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_error(99, "Error: Can't write to", argv[2]);
	}

	write_in_file(fd_from, fd_to, argv[2]);

	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);

	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);

	return (0);
}
