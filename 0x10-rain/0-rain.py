#!/usr/bin/python3
"""calculate how many square units of water"""


def rain(walls):
    """def rain function"""
    counterWidth = 0
    Square = 0
    i = 1
    while (i < len(walls) - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for counter in range(i + 1, len(walls)):
            right = max(right, walls[counter])
        Square += (min(left, right) - walls[i])
        i += 1
    return Square
