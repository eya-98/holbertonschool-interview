#!/usr/bin/python3
""" Prime game """
def checkprime(n):
    """check if the number is prime"""
    prime = 0
    if (n == 1):
        return True
    if (n == 0):
        return False
    for i in range(2, n):
        if (n % i) == 0:
            prime += 1
    if prime != 0:
        return False
    else:
        return True

def multiple(lists, n):
    """delete all the multiples of a number in a list"""
    newlist = lists.copy()
    for i in lists:
        if (i % n == 0):
            newlist.remove(i)
    return newlist


def isWinner(x, nums):
    """ return the name of the winner of the game"""
    player = -1
    nums = sorted(nums, reverse=True)
    if len(nums) > 1:
        for i in range(x):
            game = 0
            newList = nums.copy()
            player += 1
            for num in nums:
                if(checkprime(num) == True):
                    if (num == 1):
                        newList.remove(1)
                    else:
                        newList = multiple(nums, num) 
                    game += 1
                    break
                else:
                    continue
            nums = newList.copy()
            if (game == 0):
                if (player % 2 == 0):
                    return 'Ben'
                else: 
                    return 'Maria'
        return None
