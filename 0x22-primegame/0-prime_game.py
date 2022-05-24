#!/usr/bin/python3
""" Prime game """


def isWinner(x, nums):
    """ return the name of the winner of the game"""
    player = -1
    nums = sorted(nums, reverse=True)
    if (len(nums) >= 2):
        for i in range(x):
            game = 0
            newList = nums.copy()
            number = nums[0]
            player += 1
            for num in nums:
                if (num % number == 0):
                    newList.remove(num)
                    game += 1
            print(nums)
            nums = newList
            if (game == 0) or (len(nums) <= 1):
                if (player % 2 == 0):
                    return 'Maria '
                else:
                    return 'Ben '
    return None
