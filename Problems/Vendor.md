## **B. 專賣店** ***<font color = '#AAAAAA'>Vendor</font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

因為 ***Mingyee*** 訂冰炫風的時候沒有準備 ***ysh*** 的份，
所以 ***ysh*** 打算把所有口味一次訂來炫耀給 ***Mingyee*** 看。

而每間專賣店都販售的自己的獨家口味，也就是說，找不到另一間專賣店與任何一家專賣店口味相同。

為了達成目標， ***ysh*** 整理好了附近所有專賣店的位置，將這 $n$ 家專賣店繪於二維平面，並對第 $i$ 間專賣店賦予座標 $(x_i,y_i)$ ，其中 $1 \leq i \leq n$ 。

不過可悲的是因為他沒有駕照，只能訂外送，於是他決定移動到某個點 $(x,y),\ x,y \in Z$，並一次下訂這 $n$ 家冰炫風，運送到目前位置。

假設目的地座標為 $(a,b)$ ，專賣店位置為 $(c,d)$ ，則外送的運費為 $\sqrt{(a - c) ^ 2 + (b - d) ^ 2}$ 。

但是 ***ysh*** 錢包裡的錢比某 ***HARC*** 線上賽題目給的記憶體還少，所以請你幫他找出 **運費最低** 的目的地。

**註： 外賣系統很厲害，可以收取小數的金額，而且精度達到了驚人的 $10^{-19}$ ，雖然這並沒甚麼用**

![](Pictures/Straight.jpg)

### ***Input***

$n$\
$x_1$ $y_1$\
...\
$x_n$ $y_n$

### ***Output***

$x$ $y$

<div style="page-break-after: always"></div>

### ***Sample Input 1***

```
1
20 23
```

### ***Sample Output 1***

```
20 23
```

### ***Sample Input 2***

```
3
-15 -93
55 51
95 73
```

### ***Sample Output 2***

```
55 51
```

### ***Sample Input 3***

```
4
-47 13
-20 35
1 21
-76 -100
```

### ***Sample Output 3***

```
-28 16
```

<div style="page-break-after: always"></div>

### ***Note***

#### ***Input Restriction***

$1 \leq n \leq 2 \times 10^5$

$-10^6 \leq x_i,y_i \leq 10^6,\ \forall\ 1 \leq i \leq n$

#### ***Output Restriction***

$-10^6 \leq x,y \leq 10^6$

$x,y \in Z$

只要你的答案合法(如上)且 **你的答案所成的距離總和** $-$ **官解的距離總和** $<$ $1$,答案將被判定為 **<font color = '#55AA55'>答案正確</font>**

若答案並不符合上述規則，你有可能獲得

 - **輸出格式錯誤**
 - **答案錯誤**

### ***Subtask***

 - ***subtask1***: $1\\%$ $n \leq 1,\ -10^2 \leq x_i,y_i \leq 10^2$
 - ***subtask2***: $2\\%$ $n \leq 2,\ -10^2 \leq x_i,y_i \leq 10^2$
 - ***subtask3***: $3\\%$ $n \leq 3,\ -10^2 \leq x_i,y_i \leq 10^2$
 - ***subtask4***: $4\\%$ $n \leq 10,\ -10^2 \leq x_i,y_i \leq 10^2$
 - ***subtask5***: $20\\%$ $n \leq 10^3,\ -10^3 \leq x_i,y_i \leq 10^3$
 - ***subtask6***: $10\\%$ $(x_i \in \{r|r = x_1\}, 1 \leq i \leq n) \vee (y_i \in \{r|r = y_1\}, 1 \leq i \leq n)$
 - ***subtask7***: $30\\%$ $n \leq 2 \times 10^4$
 - ***subtask8***: $30\\%$ ***As statement***

<div style="page-break-after: always"></div>
