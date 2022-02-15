#!/usr/bin/python3
"""determine the fewest number of coins needed to meet a given amount"""


def makeChange(coins, total):
    """makeChange"""
    if total is None or total <= 0:
        return 0
    sum = 0
    coins = sorted(coins, reverse=True)
    while(total):
        for i in coins:
            if (i <= total):
                sum += 1
                total -= i
                break
            if coins[-1] > total:
                return -1
    return sum