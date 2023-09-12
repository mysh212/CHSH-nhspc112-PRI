# Author : ysh
# 2023/07/27 Thu 17:03:44
import sys

input = sys.stdin.readline
print = sys.stdout.write

b = [int(i) for i in input().split()][1]
for i in range(int(input())):
    n = int(input())
    if n < b:
        print('NO\n')
        continue
    if n & 1 == b & 1:
        print('YES\n')
    else:
        print('NO\n')
quit()
