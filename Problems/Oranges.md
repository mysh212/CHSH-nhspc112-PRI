## **G. 橘子** ***<font color = '#AAAAAA'> Oranges </font>***

`time limit` 1s
`memory limit` 1024MB

### ***Statement***

現在有$n$個盤子，第$i$個盤子上有$a_i$橘子。
你可以選擇任意一個數對($l, r, x$)滿足以下條件：

- $1 \le l \le r \le n$
- $1 \le x$
- $x \le a_i$，其中$l \le i \le r$

你可以從$l$到$r$的盤子上各拿走$x$棵橘子來吃。
請問你最多可以吃到幾顆橘子？

### ***Input***

$n$\
$a_1, a_2, ..., a_n$

- $n$為盤子的數量
- $a_i$為第$i$個盤子的橘子數量

### ***Output***

$Ans$

- 你可以吃到的橘子數量的**最大值**

<div style="page-break-after: always"></div>

### ***Sample Input 1***

```
6
2 4 4 9 4 9
```

### ***Sample Output 1***

```
20
```

### ***Sample Input 2***

```
6
200 4 4 9 4 9
```

### ***Sample Output 2***

```
200
```

### ***Note***

$1 \le n \le 10^4$\
$1 \le a_i \le 10^5$


<div style="page-break-after: always"></div>
