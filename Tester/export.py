# Author : ysh
# 2023/09/12 Tue 22:37:10
import os

print('# Testers\' Code\n這裡放了所有Tester的AC Code，歡迎大家參考。\n\n| Problem | Tester | Date | Time | Result | Language |\n|:-:|:-:|:-:|:-:|:-:|:-:|')

os.system('dir /B > 1.tmp')
f = open('1.tmp','r')

for i in f:
    # Derek0.Practice.199116021.Mar-25-2023.23_15.AC.cpp
    i = i.replace('\n','')
    # username, problem, id, date, time, result, language = i.split('.')
    for j in i.split('.'):
        print(f'| [{j.replace("_",":")}]({i}) ',end = '')
    print('|')

os.system('del 1.tmp')
quit()