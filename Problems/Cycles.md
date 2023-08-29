## **I. 環** ***<font color = '#AAAAAA'> Cycles </font>***

`time limit` 1s
`memory limit` 1024MB

### ***Statement***

給定一個$n$點的無向完全圖和$k$個封閉的邊。

現在需要你求出在不使用任何封閉的邊的情況下，共有幾條哈密頓迴路($\text Hamiltonian \space cycle$)。哈密頓迴路為一個環，其剛好經過每一個點各一次。注意到，擁有相同邊集合的環只會被計算一次。舉個例子，環$\\{1\rightarrow2\rightarrow3\rightarrow4\rightarrow1\\}$和$\\{1\rightarrow4\rightarrow3\rightarrow2\rightarrow1\\}$, $\\{2\rightarrow3\rightarrow4\rightarrow1\rightarrow2\\}$皆相同，但和$\\{1\rightarrow3\rightarrow2\rightarrow4\rightarrow1\\}$不同。

因為答案很大，所以請輸出答案除以$9901$的餘數。

- 無向完全圖: 對於圖中任意相異兩點皆存在一條無向邊

### ***Input***

$n, \space k$\
$u_1, v_1$\
$u_2, v_2$\
$...$\
$u_k, v_k$

- $n$為無向完全圖點的數量
- $k$為封閉邊的數量
- $u_i, v_i$代表這兩點相連的邊為封閉邊

### ***Output***

$Ans \space \\% \space 9901$

<div style="page-break-after: always"></div>

### ***Sample Input 1***

```
4 1
1 2
```

### ***Sample Output 1***

```
1
```

### ***Sample Input 2***

```
8 4
1 2
2 3
4 5
5 6
```

### ***Sample Output 2***

```
660
```

### ***Note***

$3 \le n \le 300$\
$0 \le k \le 15$\
$1 \le u_i, v_i \le n$

### ***Subtask***

- ***subtask1***: $10\\%$ $3 \le n \le 10$
- ***subtask2***: $90\\%$ ***As statement***

<div style="page-break-after: always"></div>
