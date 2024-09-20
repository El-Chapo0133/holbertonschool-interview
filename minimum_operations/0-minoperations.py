#!/usr/bin/python3
"""
This module is documented
"""


import math


def minOperations(n):
    factors = []

    while n % 2 == 0:
        factors.append(2)
        n = n // 2

    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            factors.append(i)
            n = n // i

    return sum(factors)
