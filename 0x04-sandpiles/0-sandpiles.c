#include "sandpiles.h"
/**
 * stable - Checks if tgrid is stable
 * @grid: 3x3 int grid.
 * Return: 1 if stable -1 if not
 */

int stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (-1);
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * sandpiles_sum - Calculates sandpiles
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int temp[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	while (stable(grid1) < 1)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (grid1[i][j] > 3)
				{
					temp[i][j] -= 4;
					if (i > 0)
						temp[i - 1][j] += 1;
					if (i < 2)
						temp[i + 1][j] += 1;
					if (j > 0)
						temp[i][j - 1] += 1;
					if (j < 2)
						temp[i][j + 1] += 1;
				}
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
			{
				grid1[i][j] += temp[i][j];
				temp[i][j] = 0;
			}
	}
}
