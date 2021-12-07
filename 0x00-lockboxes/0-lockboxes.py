#!/usr/bin/python3
'''coding challenge'''


def canUnlockAll(boxes):
    '''can all the boxes be unlocked?'''
    if (boxes is None):
        return False
    boxCount = len(boxes)
    if boxCount <= 1:
        return True
    keys = [0]
    scout = 0
    while (scout < len(keys)):
        for key in boxes[keys[scout]]:
            if key not in keys and key < boxCount:
                keys.append(key)
        scout += 1

    if (len(keys) == boxCount):
        return True
    return False
