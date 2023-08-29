# Author : ysh
# 2023/07/27 Thu 17:46:54
a,b = [int(i) for i in input().split()]
assert(a == -1 or a == 1)
assert(-(10 ** 18) <= b <= (10 ** 18))
m = int(input())
assert(1 <= m <= (10 ** 5))
for i in range(m):
    assert(-(10 ** 18) <= int(input()) <= (10 ** 18))
quit()