#!/usr/bin/python3
"""
Documented lol
"""


def make_matrix(set_of_coins, r: int):
    """
    Documented lol
    """
    m = [[0 for _ in range(r + 1)] for _ in range(len(set_of_coins) + 1)]
    for i in range(1, r + 1):
        m[0][i] = float("inf")
    return m


def makeChange(coins, n: int):
    """
    Documented lol
    """
    if n < 0:
        return 0
    m = make_matrix(coins, n)
    for c, coin in enumerate(coins, 1):
        for r in range(1, n + 1):
            if coin == r:
                m[c][r] = 1
            elif coin > r:
                m[c][r] = m[c - 1][r]
            else:
                m[c][r] = min(m[c - 1][r], 1 + m[c][r - coin])
    return m[-1][-1] if m[-1][-1] != float('inf') else -1
