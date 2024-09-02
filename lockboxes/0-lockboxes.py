#!/usr/bin/python3

"""
module is documented
"""

def canUnlockAll(boxes):
    """
    this module is documented
    """

    new_keys = boxes[0]
    temp_new_keys = []
    openned_boxes = [0]
    
    while True:
        for i in new_keys:
            if i not in openned_boxes and i < len(boxes):
                openned_boxes.append(i)
                for j in boxes[i]:
                    if j not in openned_boxes:
                        temp_new_keys.append(j)
        if temp_new_keys == []:
            break
        new_keys = temp_new_keys
        temp_new_keys = []

    return len(openned_boxes) == len(boxes)
