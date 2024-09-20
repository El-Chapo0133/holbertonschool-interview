#!/usr/bin/python3
"""
This module is documented
"""


import math


def minOperations(n):
    factors = []

    prime_factors = lambda n: [i for i in range(2, n+1) if n%i == 0 and all(i % j != 0 for j in range(2, int(i**0.5)+1))]

    while n > 1:
        for factor in prime_factors(n):
            factors.append(factor)
            n = n // factor

    return sum(factors)
