#include "main.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * open_file - Opens a file.
 * @filename: The name of the file to open.
 *
 * Return: The file descriptor or -1 if it fails.
 */
int open_file(const char *filename)
{
  if (filename == NULL)
    return (-1);

  return (open(filename, O_RDONLY));
}

/**
 * allocate_buffer - Allocates memory for the buffer.
 * @letters: The number of letters to read and print.
 *
 * Return: The buffer or NULL if it fails.
 */
char *allocate_buffer(size_t letters)
{
  return (malloc(sizeof(char) * letters));
}

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print,
 * or 0 if the file cannot be opened or read, or if filename is NULL,
 * or if write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
  int fd;
  ssize_t bytes_read, bytes_written;
  char *buffer;

  if (filename == NULL)
    return (0);

  fd = open_file(filename);
  if (fd == -1)
    return (0);

  buffer = allocate_buffer(letters);
  if (buffer == NULL)
  {
    close(fd);
    return (0);
  }

  bytes_read = read(fd, buffer, letters);
  if (bytes_read == -1)
  {
    free(buffer);
    close(fd);
    return (0);
  }

  bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
  if (bytes_written == -1 || bytes_written != bytes_read)
  {
    free(buffer);
    close(fd);
    return (0);
  }

  free(buffer);
  close(fd);

  return (bytes_written);
}
