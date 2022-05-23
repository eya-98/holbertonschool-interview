#!/usr/bin/python3
""" list of lists of integers representing the Pascal’s triangle of n """


def pascal_triangle(n):
    """ print list of lists of pascal triangle """
    ListofLists = list()
    if (n <= 0):
        return ListofLists
    TheList = [1]
    for i in range(n):
        ListofLists.append(TheList)
        newlist = []
        newlist.append(1)
        for j in range(len(TheList)-1):
            newlist.append(TheList[j]+TheList[j+1])
        newlist.append(1)
        TheList = newlist
    return ListofLists
