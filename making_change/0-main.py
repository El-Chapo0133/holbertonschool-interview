

def makeChange(coins, total):
    acc = 0
    i = 0
    remain = total

    coins.reverse()
    while remain != 0:
        while remain < coins[i]:
            i += 1
            if i >= len(coins):
                return -1
        acc += 1
        remain -= coins[i]
    return acc

print(makeChange([1, 2, 25], 37))
print(makeChange([1256, 54, 48, 16, 102], 1453))

