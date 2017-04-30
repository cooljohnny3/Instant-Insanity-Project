import random
import sys
import math

f = open("Threads.txt", 'w')

choice = input("1.PI \n2.e\n")

if choice == "1":
    for i in range(1, 193):
        f.write(str(1 + ((math.floor(i * math.pi) % 32))) + " ")
        if i % 2 == 0:
            f.write("  ")
        if i % 6 == 0:
            f.write("\n")

else:
    for i in range(1, 193):
        f.write(str(1 + ((math.floor(i * math.e) % 32))) + " ")
        if i % 2 == 0:
            f.write("  ")
        if i % 6 == 0:
            f.write("\n")


f.close()
