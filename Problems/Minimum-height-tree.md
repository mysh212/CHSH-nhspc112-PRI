## **H. 最淺樹** ***<font color = '#AAAAAA'> Minimum Height Trees </font>***

`time limit` 1s
`memory limit` 1024MB

### ***Statement***

給定一棵樹，你可以選擇任意一點作為此樹的根。
現在定義$h_i$為：當以結點$i$為根時的高度
請你求出$min_{i=1}^{n}h_i$

- 一棵有根樹的高度定義為**根和所有葉節點的距離中的最大值**

### ***Input***

$n$\
$u_1,v_1$\
$u_2,v_2$\
$...$\
$u_{n-1},v_{n-1}$

- $n$為樹的節點樹
- $u_i,v_i$為一條相連兩點的樹邊

### ***Output***

$H$

- $H=min_{i=1}^nh_i$

<div style="page-break-after: always"></div>

### ***Sample Input 1***

```
4
1 2
2 3
2 4
```

### ***Sample Output 1***

```
1
```

### ***Sample Input 2***

```
6
4 1
4 2
4 3
4 5
6 5
```

### ***Sample Output 2***

```
2
```

### ***Note***

$1 \le n \le 2 \times 10^5$
$1 \le u_i,v_i \le n$

### ***Subtask***

 - ***subtask1***: $7 \\%$ 給定的樹為一條鏈
 - ***subtask2***: $22 \\%$ $1 \le n \le 10^4$
 - ***subtask3***: $71 \\%$ $\text As \space statement$

<div style="page-break-after: always"></div>
