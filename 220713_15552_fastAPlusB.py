import sys
T = int(sys.stdin.readline())
for _ in range(T):
    a, b = map(int, sys.stdin.readline().split())
    sys.stdout.write(str(a + b) +'\n')
