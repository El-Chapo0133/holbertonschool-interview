#!/usr/bin/python3
"""
validUTF8
"""

def validUTF8(data):
    """Write a method that determines if a given data set represents a valid UTF-8 encoding"""
    if type(data) is not list:
        return False
    for i in data:
        if type(i) is not int:
            return False
    return True
