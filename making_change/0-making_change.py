#!/usr/bin/python3
"""
Documented yes
"""

def makeChange(coins, total):
    acc = 0
    i = len(coins) - 1
    remain = total

    while remain != 0:
        while remain < coins[i]:
            i -= 1
            if i < 0:
                return -1
        acc += 1
        remain -= coins[i]
    return acc

