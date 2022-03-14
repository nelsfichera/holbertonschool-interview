#!/usr/bin/python3
"""Solves the nqueens problem (see link in readme)"""
import sys


def solve_nqueens(n):
    '''solves the grid of queens'''
    '''makes the grid'''
    grid = []
    '''processes each row'''
    for row in range(0, n):
        solve_queen(n, 0, row, grid)
    '''prints each solution'''
    for solution in grid:
        print(solution)


def solve_queen(n, col, row, grid, qsol=[]):
    '''solves each queen'''
    '''checks if safe'''
    if palace_guard(col, row, qsol) is False:
        return
    '''places a queen'''
    s = qsol.copy()
    s.append([col, row])
    if col == n - 1:
        grid.append(s)
    '''adds queen to grid for solving'''
    for i in range(0, n):
        solve_queen(n, col + 1, i, grid, s)


def palace_guard(col, row, sol):
    '''makes sure a queen placement is safe'''
    for index in sol:
        '''checks for row&col attack'''
        if index[0] == col or index[1] == row:
            return False
        '''checks for diagonal attacks'''
        if index[0] - index[1] == col - row:
            return False
        if index[0] + index[1] == col + row:
            return False
    '''places a safe queen'''
    return True

'''does the whole thing, ykyk'''
if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        exit(1)
    if n < 4:
        print("N must be at least 4")
        exit(1)
    solve_nqueens(n)