#!/usr/bin/python3
"""
Prime Game
"""


def isWinner(x, nums):
    """
    The prime Game
    """
    prime = 0
    notPrime = 0

    if nums:
        if x <= 0 or nums is None or min(nums) < 0:
            return None
        for num in nums:
            if (num > 0):
                if(num % 2 == 0):
                    prime += 1
                else:
                    notPrime += 1
        if prime >= notPrime:
            return "Maria"
        else:
            return "Ben"
    return None
