#!/usr/bin/python3
"""returns the perimeter of the island described in grid:

    grid is a list of list of integers:0 represents water, 1 represents land
    Each cell is square, with a side length of 1
    Cells are connected horizontally/vertically (not diagonally).
    grid is rectangular, with its width and height not exceeding 100
    The grid is completely surrounded by water
    There is only one island (or nothing).
    The island doesn’t have “lakes”"""


def island_perimeter(grid):
    """return the perimeter of the island"""
    perimeter = x = n = check = 0

    for x in range(len(grid)):
        for n in range(len(grid[0])):
            if grid[x][n] == 1:
                if x - 1 == -1:
                    perimeter += 1
                elif grid[x - 1][n] == 0:
                    perimeter += 1
                if n - 1 == -1:
                    perimeter += 1
                elif grid[x][n - 1] == 0:
                    perimeter += 1
                if n + 1 == len(grid[0]):
                    perimeter += 1
                elif grid[x][n + 1] == 0:
                    perimeter += 1
                if x + 1 == len(grid):
                    perimeter += 1
                elif grid[x + 1][n] == 0:
                    perimeter += 1

    return perimeter
