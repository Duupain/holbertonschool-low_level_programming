#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * handle_error - Affiche un message d'erreur et quitte le programme.
 * @exit_code: Code de sortie à utiliser.
 * @message: Message d'erreur à afficher.
 * @filename: Nom du fichier lié à l'erreur.
 *
 * Description: Affiche un message d'erreur formaté sur stderr, suivi du nom
 * du fichier concerné. Ensuite, quitte le programme avec le code de sortie
 * spécifié.
 */
void handle_error(int exit_code, const char *message, const char *filename)
{
  dprintf(STDERR_FILENO, "%s %s\n", message, filename);
  exit(exit_code);
}

/**
 * main - Copie le contenu d'un fichier vers un autre fichier.
 * @argc: Nombre d'arguments passés au programme.
 * @argv: Tableau d'arguments passés au programme.
 *
 * Description: Le programme copie le contenu de `file_from` vers `file_to`.
 * Si `file_to` existe, il est tronqué avant l'écriture. Si des erreurs se
 * produisent lors de l'ouverture, la lecture, l'écriture ou la fermeture des
 * fichiers, le programme affiche un message d'erreur approprié et quitte avec
 * un code d'erreur spécifique.
 *
 * Return: 0 en cas de succès, ou un code d'erreur spécifique en cas d'échec.
 */
int main(int argc, char *argv[])
{
  int fd_from, fd_to;
  ssize_t bytes_read, bytes_written;
  char buffer[1024]; /* Taille du buffer fixée à 1024 octets */

  /* Vérifie si le nombre d'arguments est correct */
  if (argc != 3)
  {
    dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
    exit(97);
  }

  /* Ouvre le fichier source en lecture seule */
  fd_from = open(argv[1], O_RDONLY);
  if (fd_from == -1)
  {
    handle_error(98, "Error: Can't read from file", argv[1]);
  }

  /* Ouvre ou crée le fichier de destination en écriture avec les permissions rw-rw-r-- */
  fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
  if (fd_to == -1)
  {
    close(fd_from);
    handle_error(99, "Error: Can't write to", argv[2]);
  }

  /* Lit le contenu du fichier source et l'écrit dans le fichier de destination */
  while ((bytes_read = read(fd_from, buffer, 1024)) > 0)
  {
    bytes_written = write(fd_to, buffer, bytes_read);
    if (bytes_written == -1)
    {
      close(fd_from);
      close(fd_to);
      handle_error(99, "Error: Can't write to", argv[2]);
    }
  }

  /* Si une erreur de lecture s'est produite */
  if (bytes_read == -1)
  {
    handle_error(98, "Error: Can't read from file", argv[1]);
  }

  /* Ferme les descripteurs de fichiers */
  if (close(fd_from) == -1)
  {
    handle_error(100, "Error: Can't close fd", argv[1]);
  }

  if (close(fd_to) == -1)
  {
    handle_error(100, "Error: Can't close fd", argv[2]);
  }

  return (0);
}
