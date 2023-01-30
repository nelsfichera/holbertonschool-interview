#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ returns a list of lists of integers
    representing pascal's triangle """
    triangle_list = []

    for x in range(1, n + 1, 1):
        row = [1] * x
        for i in range(x):
            if i != 0 and i != x - 1:
                row[i] = list[x - 2][i] + list[x - 2][i - 1]
        triangle_list.append(row)

    return triangle_lists
