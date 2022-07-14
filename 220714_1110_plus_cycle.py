import sys

def plus_cycle(number: str) -> int:
    newnumber: str = number
    temp: int = 0
    cycle: int = 0
    while True:
        if newnumber == number and cycle != 0:
            return cycle
        temp = f'{int(newnumber[0]) + int(newnumber[1]):0>2}' #8
        newnumber = f'{newnumber[1] + temp[1]:0>2}'
        cycle += 1
        
number = f'{sys.stdin.readline().rstrip():0>2}' #faster input

sys.stdout.write(str(plus_cycle(number)) + '\n')
