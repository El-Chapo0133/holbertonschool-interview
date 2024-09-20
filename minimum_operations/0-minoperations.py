#!/usr/bin/python3
"""
This module is documented
"""


import math


def minOperations(n):
    factors = []

    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)

    return sum(factors)
