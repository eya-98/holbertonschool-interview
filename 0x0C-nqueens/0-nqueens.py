#!/usr/bin/python3
import sys
if len(sys.argv) != 2:
    print('Usage: nqueens N')
    exit(1)
if sys.argv[1].isdigit() is False:
    print('N must be a number')
    exit(1)
N = int(sys.argv[1])
if (N < 4):
    print('N must be at least 4')
    exit(1)
y = 0
frequence_y = 2
for i in range(N - 2):
    Lists = []
    y += 1
    n = y
    for x in range(N):
        Lists.append([x, y])
        if (y + frequence_y > N-1):
            y += frequence_y - 1 - N
        else:
            y += frequence_y
    print(Lists)
    frequence_y += 1
    y = n
exit(0)
