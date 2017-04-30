import random
import math

def checkAmount(listy):
    for i in range(0, len(listy)):
        if listy[i] == 0:
            return False
    return True

def sum4(listy):
    count = 0
    print(listy)
    for i in range(0, len(listy)):
        if listy[i] < 4:
            count += 1
    return count

choice1 = input("1.A \n2.B\n")

if choice1 == 'A':
    nums = [0] * 32

    choice2 = input("1.PI \n2.e\n")

    if choice2 == "1":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.pi) % 32))
            nums[num - 1] += 1
            if i >= 32 and checkAmount(nums):
                print(i)
                break
                
    else:
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.e) % 32))
            nums[num - 1] += 1
            if i >= 32 and checkAmount(nums):
                print(i)
                break

if choice1 == 'B':
    nums = [0] * 32

    choice2 = input("1.PI \n2.e\n")

    if choice2 == "1":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.pi) % 32))
            nums[num - 1] += 1
        print(sum4(nums))

    else:
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.e) % 32))
            nums[num - 1] += 1
        print(sum4(nums))
