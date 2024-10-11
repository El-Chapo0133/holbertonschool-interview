#include "sandpiles.h"


/**
 * sandpiles_sum - add two sandpiles
 * @grid1: first grid
 * @grid2: second grid
 *
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int is_stable;

	add_grids(grid1, grid2);
	is_stable = is_grid_stable(grid1);
	while (!is_stable)
	{
		is_stable = is_grid_stable(grid1);
			print_grid(grid1);
		next_step(grid1);
	}
}

/**
 * next_step - calculate next step of the sandpile
 * @grid: grid to calculate
 *
 * Return: void
 */
void next_step(int grid[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
			{
				if (i > 0)
					grid[i-1][j] += 1;
				if (i < 2)
					grid[i+1][j] += 1;
				if (j > 0)
					grid[i][j-1] += 1;
				if (j < 2)
					grid[i][j+1] += 1;
				
				grid[i][j] -= 4;
				print_grid(grid);
			}
}

/**
 * add_grids - calculate the absolute sum of two grids
 * @grid1: first grid
 * @grid2: second grid
 *
 * Return: void
 */
void add_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];	
}

/**
 * is_grid_stable - check if grid contains one element > 3
 * @grid: grid to check
 *
 * Return: 1 if stable, 0 if not
 */
int is_grid_stable(int grid[3][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return 0;
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
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
