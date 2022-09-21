import sys


def the_end_of_the_earth(num: int) -> int:
    threesix: int = 666
    count: int = 1
    while True:
        if count == num:
            return threesix
        threesix += 1
        if '666' in str(threesix):
            count += 1

num = int(sys.stdin.readline())
print(the_end_of_the_earth(num))
