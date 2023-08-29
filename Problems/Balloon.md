## **J. 氣球** ***<font color = '#AAAAAA'> Balloon </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

給你共 $n$ 個氣球，玩第 $i$ 個能獲得 $a_i,\ 1 \leq i \leq n$ 的快樂度，但因為太快樂了，所以最讓人快樂的氣球會破掉。

於是聰明的你想了個辦法，你只挑 **一個區間** 的氣球玩，具體來說，你選了兩個整數 $l,r$ ， $1 \leq l \leq r \leq n$ ，並且把編號 $[l,r]$ 的氣球帶回家玩。

現在請問你能獲得最大的快樂度。

換句話說，即是:

給你有 $n$ 項的數列 $a_i, 1 \leq i \leq n$
請找出
$$
\max_{1 \leq l \leq r \leq n\ \land\ l,r \in N} (\sum_{k = l}^r f_k) - \max_{t = l}^r f_t
$$

### ***Input***

$n$\
$a_1$ $a_2$ ... $a_n$

### ***Output***

$Ans$

### ***Sample Input***

```
10
7 10 -4 6 6 10 3 3 -5 7
```

### ***Sample Output***

```
33
```

### ***Note***

$1 \leq n \leq 10^5$\
$10^{-9} \leq a_i \leq 10^9,\ \forall\ 1 \leq n$

### ***Subtask***

 - ***subtask1***: $3\\%$ $n \leq 100$
 - ***subtask2***: $7\\%$ $n \leq 10^3$
 - ***subtask3***: $20\\%$ $n \leq 10^5$, $-30 \leq a_i \leq 30,\ \forall\ 1 \leq i \leq n$
 - ***subtask4***: $10\\%$ $n \leq 10^5$, $0 \leq a_i \leq 10^9,\ \forall\ 1 \leq i \leq n$
 - ***subtask5***: $60\\%$ ***As statement***

<div style="page-break-after: always"></div>
