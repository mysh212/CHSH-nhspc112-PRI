# Author : ysh
# 2023/08/24 Thu 17:39:44
n = int(input())
assert(1 <= n <= 10 ** 5)
f = [int(i) for i in input().split()]
assert(len(f) == n)
assert([i for i in f if -10 ** 9 <= i <= 10 ** 9] == f)
quit()