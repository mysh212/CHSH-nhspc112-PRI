# Author : ysh
# 2023/08/03 Thu 13:40:17
n = int(input())
assert(1 <= n <= 2 * (10 ** 5))
for i in range(n):
    f = [int(i) for i in input().split()]
    assert(len(f) == 2)
    assert([i for i in f if -10 ** 6 <= i <= 10 ** 6] == f)
quit()