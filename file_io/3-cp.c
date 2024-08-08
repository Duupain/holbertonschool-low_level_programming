#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * handle_error - Affiche un message d'erreur et quitte le programme.
 * @exit_code: Code de sortie à utiliser.
 * @message: Message d'erreur à afficher.
 * @filename: Nom du fichier lié à l'erreur.
 */
void handle_error(int exit_code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, "%s %s\n", message, filename);
	exit(exit_code);
}

/**
 * close_file - Ferme un descripteur de fichier et gère les erreurs.
 * @fd: Descripteur de fichier à fermer.
 * @filename: Nom du fichier lié au descripteur.
 */
void close_file(int fd, const char *filename)
{
	if (close(fd) == -1)
		handle_error(100, "Error: Can't close fd", filename);
}

/**
 * copy - Copie le contenu d'un fichier à un autre.
 * @fd_from: Descripteur de fichier source.
 * @fd_to: Descripteur de fichier destination.
 * @file_from: Nom du fichier source.
 * @file_to: Nom du fichier destination.
 */
void copy(int fd_from, int fd_to, const char *file_from, const char *file_to)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(fd_from, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			close_file(fd_from, file_from);
			close_file(fd_to, file_to);
			handle_error(99, "Error: Can't write to", file_to);
		}
	}

	if (bytes_read == -1)
		handle_error(98, "Error: Can't read from file", file_from);
}

/**
 * main - Copie le contenu d'un fichier vers un autre fichier.
 * @argc: Nombre d'arguments passés au programme.
 * @argv: Tableau d'arguments passés au programme.
 *
 * Return: 0 en cas de succès, ou un code d'erreur en cas d'échec
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		handle_error(98, "Error: Can't read from file", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close_file(fd_from, argv[1]);
		handle_error(99, "Error: Can't write to", argv[2]);
	}

	copy_content(fd_from, fd_to, argv[1], argv[2]);

	close_file(fd_from, argv[1]);
	close_file(fd_to, argv[2]);

	return (0);
}
