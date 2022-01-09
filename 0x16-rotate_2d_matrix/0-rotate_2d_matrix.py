#!/usr/bin/python3
"""Rotate 2D Matrix"""


def rotate_2d_matrix(matrix):
    """rotate it 90 degrees clockwise"""
    start = 0
    end = len(matrix) - 1
    while (start < end):
        for i in range(start, end):
            new = matrix[i][end]
            matrix[i][end] = matrix[start][i]
            new2 = matrix[end][start + end - i]
            matrix[end][start + end - i] = new
            new = matrix[start + end - i][start]
            matrix[start + end - i][start] = new2
            matrix[start][i] = new
        start += 1
        end -= 1
