#!/usr/bin/python3
"""
Documented yes
"""

def makeChange(coins, total):
    if total < 0:
        return 0
    acc = 0
    i = len(coins) - 1
    remain = total

    if i < 0:
        return -1
    print ("startup coins: " + str(coins) + " startup total: " + str(total))
    while remain != 0:
        while remain < coins[i]:
            print ("coin too big: " + str(coins[i]) + "moving i: " + str(i))
            i -= 1
            if i < 0:
                return -1
        acc += 1
        remain -= coins[i]
        print ("remain at end of loop: " + str(remain))
    return acc
