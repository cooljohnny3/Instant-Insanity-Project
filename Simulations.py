import random
import math

def checkAmount(listy):
    #print(listy)
    for i in range(0, 32):
        if listy[i] == 0:
            return False
    return True

def sum4(listy):
    count = 0
    for i in range(0, len(listy)):
        if listy[i] < 4:
            count += 1
    return count

def gen193():
    temp = [0] * 32
    for i in range(1, 193):
        num = random.randint(1, 32)
        temp[num - 1] += 1
    return temp


choice1 = input("1.A \n2.B\n")

if choice1 == 'A':
    nums = [0] * 32

    choice2 = input("1.PI \n2.e\n3.Random")

    if choice2 == "1":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.pi) % 32))
            nums[num - 1] += 1
            if i >= 32 and checkAmount(nums):
                print(i)
                break

    elif choice2 == "2":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.e) % 32))
            nums[num - 1] += 1
            if i >= 32 and checkAmount(nums):
                print(i)
                break

    else:
        sum = 0
        for j in range(1, 10000):
            nums = [0] * 32
            for i in range(1, 193):
                num = random.randint(1, 32)
                nums[num - 1] += 1
                if checkAmount(nums):
                    sum += i
                    break
        print(sum/10000)
        input()


if choice1 == 'B':
    nums = [0] * 32

    choice2 = input("1.PI \n2.e\n3.Random")

    if choice2 == "1":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.pi) % 32))
            nums[num - 1] += 1
        print(sum4(nums))

    elif choice2 == "2":
        for i in range(1, 193):
            num = 1 + ((math.floor(i * math.e) % 32))
            nums[num - 1] += 1
        print(sum4(nums))

    else:
        sum = 0
        for i in range(1, 100):
            sum += sum4(gen193())

        print(sum/100)
