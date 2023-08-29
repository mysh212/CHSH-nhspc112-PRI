f = open('result.log','r',encoding = 'UTF-8')
ff = open('Rule.md','r',encoding = 'UTF-8')
ans = open('Public.md','w',encoding = 'UTF-8')
bk = '\n\n\n<div style="page-break-after: always"></div>\n'

pre = []
for i in f:
    pre.append(i.replace('\n','').split('\t'))
f.close()

s = ''
for i in ff:
    s = s + i
ff.close()

for i in pre:
    tmp = s
    tmp = tmp.replace('<name>',i[0])
    tmp = tmp.replace('<class>',i[1])
    tmp = tmp.replace('<username>',i[2])
    tmp = tmp.replace('<password>',i[3])
    ans.write(tmp)
ans.close()

quit()