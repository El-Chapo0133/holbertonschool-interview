#ifndef SANDPILES
#define SANDPILES

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void next_step(int grid[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int is_grid_stable(int grid[3][3]);
static void print_grid(int grid[3][3]);


#endif
