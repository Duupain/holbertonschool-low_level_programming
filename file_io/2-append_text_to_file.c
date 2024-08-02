#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename: The name of the file.
 * @text_content: The NULL terminated string to add at the end of the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t bytes_written, len = 0;

	/* Check if filename is NULL */
	if (filename == NULL)
		return (-1);

	/* Open the file in append mode */
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	/* If text_content is NULL, return 1 as there's nothing to append */
	if (text_content == NULL)
	{
		close(fd);
		return (1);
	}

	/* Calculate the length of text_content */
	while (text_content[len] != '\0')
		len++;

	/* Write the text_content to the file */
	bytes_written = write(fd, text_content, len);
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	/* Close the file descriptor */
	close(fd);

	return (1);
}
