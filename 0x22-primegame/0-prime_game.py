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
                if(len(nums) > 1 and num != 0):
                    if (num % number == 0) :
                        game += 1
                        newList.remove(num)
            nums = newList.copy()
            if (game == 0):
                if (player % 2 == 0):
                    return 'Ben'
                else:   
                    return 'Maria'
            if (game != 0):
                if (len(nums) == 1):
                    if (player % 2 == 0):
                        return 'Maria'
                    else:
                        return 'Ben'
                if (len(nums) == 0):
                    if (player % 2 == 0):
                        return 'Ben'
                    else:
                        return 'Maria'
                else:
                    continue

    return None
