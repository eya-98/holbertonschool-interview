#!/usr/bin/python3
"""calculate how many square units of water"""


def rain(walls):
    """def rain function"""
    counterWidth = 0
    Square = 0
    i = 0
    while (i in range(len(walls) - 1)):
        if walls[i] == 0:
            if i == 0:
                heightLeft = None
            else:
                heightLeft = walls[i - 1]
            while(walls[i] == 0):
                counterWidth += 1
                i += 1
            heightRight = walls[i]
            if heightRight is not None and heightLeft is not None:
                if heightRight < heightLeft:
                    Square += (heightRight * counterWidth)
                else:
                    Square += (heightLeft * counterWidth)
            counterWidth = 0
        else:
            i += 1
    return Square
