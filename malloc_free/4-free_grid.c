#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * free_grid - Libère la mémoire allouée pour un tableau 2D d'entiers.
 * @grid: Pointeur vers le tableau 2D d'entiers à libérer.
 * @height: Nombre de lignes dans le tableau 2D.
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
	{
		return;
	}
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
