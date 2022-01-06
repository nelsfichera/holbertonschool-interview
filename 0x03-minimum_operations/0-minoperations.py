#!/usr/bin/python3
"""gets min operations to print n characters w/ copy all & paste"""
import sys


def minOperations(n):
    ''' gets min ops'''

    if (n < 2):
        return 0
    for i in range(n // 2, 0, -1):
        if n % i == 0:
            return n // i + minOperations(i)
