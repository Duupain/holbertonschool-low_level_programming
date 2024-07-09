#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * alloc_grid - Alloue un tableau 2D d'entiers initialisés à 0.
 * @width: Largeur du tableau.
 * @height: Hauteur du tableau.
 *
 * Return: Un pointeur vers le tableau 2D alloué et initialisé à 0,
 *         ou NULL en cas d'échec d'allocation.
 */
int **alloc_grid(int width, int height)
{
	int i, j;
	int **grid;

	if (width <= 0)
	{
		return (NULL);
	}
	if (height <= 0)
	{
		return (NULL);
	}
	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(grid[j]);
			}
			free(grid);
			return (NULL);

			for (j = 0; j < width; j++)
			{
				grid[i][j] = 0;
			}
		}
		return (grid);
	}
