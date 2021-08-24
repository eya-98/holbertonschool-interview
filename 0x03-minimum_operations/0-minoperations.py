#!/usr/bin/python3
"""Minimum operations"""


def prem(n):
    for i in range(2, n):
        if (n % i == 0):
            return(False)
    return(True)


def minOperations(n):
    if (n <= 0):
        return (0)
    i = 2
    opp = 0
    while(n != 1):
        if prem(i):
            if (n % i == 0):
                n = n / i
                opp = opp + i
            else:
                i += 1
        else:
            i += 1
    return(opp)
