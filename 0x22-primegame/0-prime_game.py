#!/usr/bin/python3
""" Prime game """


def isWinner(x, nums):
    """ return the name of the winner of the game"""
    player = -1
    nums = sorted(nums, reverse=True)
    if (len(nums) >= 2):
        for i in range(x):
            game = 0
            print(nums)
            newList = list()
            for num in nums:
                player += 1
                number = nums[0]
                if (num % number == 0):
                    nums.remove(num)
                    game += 1
            if (game == 0) or (len(nums) == 1):
                if (player % 2 == 0):
                    return 'Maria'
                else:
                    return 'Ben'
    return None
