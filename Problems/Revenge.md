## **C. E班的復仇** ***<font color = '#AAAAAA'> The revenge of class E</font>***

`time limit` 2s
`memory limit` 256MB

### ***Statement***

這次的期末考數學科有史以來範圍最多，題目最難，只有淺野跟赤羽有能力奮戰到最後一題，然而最後一題卻極其毒瘤有100個小題每一題都是以下形式

***你有 a, b, c 三個介於 1~9 的位數 $(digit)$ ，利用這三個數字和 +, -, \*運算子組成運算式請問可以產生多少不一樣的非負整數？***

注意！位數(digit)是可以合併再一起的，兩個1可以組成11
由於淺野的計算速度非常快，你可以寫個程式幫助赤羽讓他能贏下這場考試嗎？

現在給你一個正整數$T$代表有$T$筆測資
每筆測資有三個正整數$a, b, c$
請對於每筆測資回答可以產生多少不一樣的非負整數

![](Pictures/E1.png)

![](Pictures/E2.png)




### ***Input***

$T$\
$a_1 \space b_1 \space c_1$\
$a_2 \space b_2 \space c_2$\
.\
.\
.\
$a_T \space b_T \space c_T$

### ***Output***

$ans_1$
$ans_2$
.
.
.
$ans_T$

<div style="page-break-after: always"></div>

### ***Sample Input***
```
2
1 1 1
2 1 2
```
### ***Sample Output***
```
7
13
```
### ***Note***

$1 \leq a, b, c \leq 9$\
$1 \leq T \leq 729$

第一筆測資可以組成運算結果非負的運算式:\
$1+1+1=3$

$1+1-1=1$

$1+1 \times 1=2$

$1-1+1=1$

$1-1 \times 1=0$

$1 \times 1+1=2$

$1 \times 1-1=0$

$1 \times 1 \times 1=1$

$1+11=12$

$1 \times 11=11$

$11+1=12$

$11-1=10$

$11 \times 1=11$

共有7個不同的答案

<div style="page-break-after: always"></div>

### ***Subtask***

 

| $a, b, c \leq X$ | 分數
| -------- | -------- |
| $X  = 1$ | $1\\%$     |
| $X  = 2$ | $2\\%$     |
| $X  = 3$ | $3\\%$     |
| $X  = 4$ | $5\\%$     |
| $X  = 5$ | $7\\%$     |
| $X  = 6$ | $9\\%$     |
| $X  = 7$ | $11\\%$     |
| $X  = 8$ | $15\\%$     |
| $X  = 9$ | $47\\%$     |


<div style="page-break-after: always"></div>
