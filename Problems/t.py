import os
os.system('dir /B *.md > 1')

s = ''
f = open('1','r')
fff = open('Rule.md','r',encoding = 'UTF-8')
for i in fff:
    s = s + i
fff.close()

tmp = []
for i in f:
    tmp.append(i)

for i in tmp[::-1]:
    print(i)
    if i == 'Rule.md\n':
        continue
    s = s + '\n'
    ff = open(i.replace('\n',''),'r',encoding = 'UTF-8')
    for j in ff:
        s = s + j

ans = open('Problems.md','w',encoding = 'UTF-8')
ans.write(s)

quit()