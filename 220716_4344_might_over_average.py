import sys

def get_percents(case: int) -> list:  # To use '-> list[str]' this, I have to import List in typing module.
    scores: list[int] = []
    percents: list[str] = []
    for _ in range(case):
        scores = list(map(int, sys.stdin.readline().rstrip().split(' '))) # Input
        average: float = sum(scores[1:]) / scores[0]
        count: int = len(list(filter(lambda x: x > average, scores[1:]))) # count people who scored upper than the average
        percents.append(f'{((count / scores[0]) * 100):.3f}%') # Store percents in list
    return percents

case: int = int(sys.stdin.readline())
percents: list = get_percents(case)
sys.stdout.write('\n'.join(percents)) # Print all elements into a single string with '\n' between them.
