import sys
from collections import Counter


def frequent_char(data: str) -> str:
    chardic = Counter(data)
    mostfreq = chardic.most_common()
    for temp in mostfreq[1:]:
        if mostfreq[0][1] == temp[1]:
            return '?'
    return mostfreq[0][0]


data: str = sys.stdin.readline().rstrip().upper()
sys.stdout.write(frequent_char(data) + '\n')
