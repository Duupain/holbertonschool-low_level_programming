#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * print_error - Prints an error message to stderr.
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
 * open_files - Opens the source and destination files.
 * @file_from: The source file.
 * @file_to: The destination file.
 * @fd_from: Pointer to the source file descriptor.
 * @fd_to: Pointer to the destination file descriptor.
 */
void open_files(const char *file_from, const char *file_to, int *fd_from, int *fd_to)
{
	*fd_from = open(file_from, O_RDONLY);
	if (*fd_from == -1)
		print_error(98, "Error: Can't read from file", file_from);

	*fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (*fd_to == -1)
	{
		close(*fd_from);
		print_error(99, "Error: Can't write to", file_to);
	}
}

/**
 * close_file - Closes a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - Copies content from source to destination file.
 * @fd_from: The source file descriptor.
 * @fd_to: The destination file descriptor.
 * @buffer: The buffer to use for copying.
 */
void copy_content(int fd_from, int fd_to, char *buffer)
{
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close(fd_from);
			close(fd_to);
			print_error(99, "Error: Can't write to", "");
		}
	}

	if (bytes_read == -1)
		print_error(98, "Error: Can't read from file", "");
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
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		print_error(97, "Usage: cp file_from file_to", "");

	open_files(argv[1], argv[2], &fd_from, &fd_to);
	copy_content(fd_from, fd_to, buffer);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
