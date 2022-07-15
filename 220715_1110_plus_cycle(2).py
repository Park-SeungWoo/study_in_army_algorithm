import sys

def plus_cycle(number: int) -> int:
    newnumber: int = number
    cycle: int = 0
    while True:
        if number == newnumber and cycle != 0:
            return cycle
        newnumber = (newnumber % 10) * 10 + (newnumber // 10 + newnumber % 10) % 10 #main algorithm
        cycle += 1

number:int  = int(sys.stdin.readline())
sys.stdout.write(str(plus_cycle(number)) + '\n')﻿​
