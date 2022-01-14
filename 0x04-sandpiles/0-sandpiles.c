#include "sandpiles.h"
static void print_grid(int grid[3][3]);

/**
 * sandpiles_sum - Sums 2 grids, topples the appox pile & and prints stable pile
 * stable "sandpile" at the end.
 * @grid1:left 3x3 int grid
 * @grid2: right 3x3 int grid.
 */


void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;

	printf("=\n");
	while (stable(grid1) != 0)
	{
		for (i = 0; i <= 3; i++)
			for (j = 0; j <= 3; j++)
				grid1[i][j] += grid2[i][j];

		print_grid(grid1);
		topple(grid1, grid2);
		print_grid(grid1);

	}
	printf("=\n");
}

/**
 * topple - Shakes grid to move sand one step and calculates 
 * transform matrix for next.
 *  @grid1: 3x3 int grid.
 *  @grid2: 3x3 int grid.
 *
 *  Return: The new transform matrix calculated.
 */


void topple(int grid[3][3], int newGrid[3][3])
{
	int i = 0, j = 0, size = 3, minHeight = 3;

	/* for (i = 0; i <= size; i++) */
	/* 	for (j = 0; j <= size; j++) */
	/* 		newGrid[i][j] = 0; */

	for (i = 0; i <= size; i++)
		for (j = 0; j <= size; j++)
			if (grid[i][j] <= minHeight)
				newGrid[i][j] = grid[i][j];

	for (i = 0; i <= size; i++)
		for (j = 0; j <= size; j++)
		{
			if (grid[i][j] > minHeight)
			{
				newGrid[i][j] += grid[i][j] - 4;

				if (i + 1 < size)
					newGrid[i + 1][j]++;
				if (i - 1 >= 0)
					newGrid[i - 1][j]++;
				if (j + 1 < size)
					newGrid[i][j + 1]++;
				if (j - 1 >= 0)
					newGrid[i][j - 1]++;
			}
		}

	for (i = 0; i <= size; i++)
		for (j = 0; j <= size; j++)
			grid[i][j] = newGrid[i][j];
}

/**
 * stable - Checks if tgrid is stable
 * @grid: 3x3 int grid.
 * Return: 0 if stable(all numbers less than 3)
 *         1 if not.
 */
int stable(int grid[3][3])
{
	int i = 0, j = 0;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return(1);
	return(0);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
