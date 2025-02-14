#!/usr/bin/python3
"""
Documented yes
"""

import os


def makeChange(coins, total):
    if total <= 0:
        return 0

    print (os.path.basename(__file__))

    # verify coins is a valid
    if (coins is None or len(coins) == 0):
        return -1

    change = 0
    my_coins = sorted(coins, reverse=True)
    money_left = total

    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            change += int(money_left / coin)
            money_left = money_left % coin

    change = change if money_left == 0 else -1

    return change
