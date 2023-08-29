# Author : ysh
# 03/23/2023 Thu 13:56:24.23
import sys
R = int(1e9) + 7
a = [1,2]
n = int(sys.stdin.readline())
if n == 1:
    sys.stdout.write('0')
    quit()
if n == 2:
    sys.stdout.write('1')
    quit()
for i in range(2,n):
    a.append((a[len(a) - 2] + a[len(a) - 1]) % R)
ans = 0
for i in range(1,n - 2):
    ans = (ans + (a[i - 1] * a[n - i - 3]))
ans = ans + (a[n - 3] << 1)
ans = ans % R
sys.stdout.write(str(ans))