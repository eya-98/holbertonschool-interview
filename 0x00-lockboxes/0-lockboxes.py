#!/usr/bin/python3
"""a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    newlist = []
    index = 0
    emptiness = 0
    for i in boxes:
        if (i == []):
            emptiness += 1
        if emptiness > 1:
            return False
    if emptiness == 1:
        index += 1
        newlist.append([])
    for j in boxes:
        for i in boxes:
            if (index in i):
                if (i in newlist):
                    continue
                else:
                    newlist.append(i)
                    index += 1
                    break
    if (len(newlist) == len(boxes)):
        return (True)
    else:
        return(False)
