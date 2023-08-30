## **A. 二維座標** ***<font color = '#AAAAAA'> Walk </font>***

`time limit` 1s
`memory limit` 256MB

### ***Statement***

***ysh*** 正在和 ***Cyana*** 玩一種遊戲

***Cyana*** 一開始須站在座標 $(0,0)$ ，每回合 ***Cyana*** 須向 $+x, -x, +y, -y$ 四種方向中挑一種並移動一單位。

給定一條直線 $y = ax + b, a \in \\{-1,1\\}$

經過 $k$ 個回合後，如果 ***Cyana*** 在該線上則獲勝

但是因為 ***Cyana*** 被 ***ysh*** 施加了 **智商下降** 的 ***buff***

所以現在請你答出 $k$ 個回合以後， ***Cyana*** 是否有獲勝的可能?


![](Pictures/fool.png)


:::spoiler ***easier version***
有一個遊戲，玩家須站在座標 $(0,0)$ ，每回合玩家須向 $+x, -x, +y, -y$ 方向移動一單位。

給定一條直線 $y = ax + b, a \in \\{-1,1\\}$

現在請你答出 $k$ 個回合以後，玩家是否有任何在線上的可能?
:::

<div style="page-break-after: always"></div>

### ***Input***

$a$ $b$
$m$
$k_1$
...
$k_m$

共有 $m$ 筆詢問。

### ***Output***

$Ans$

對於每筆詢問，請輸出 $Yes$ 或是 $No$。

### ***Sample Input***

```
-1 40805
12
53624
74024
47730
27351
45806
61246
44756
97828
50519
85755
91912
77507
```

### ***Sample Output***

```
NO
NO
NO
NO
NO
NO
NO
NO
YES
YES
NO
YES
```

### ***Note***

$a \in \\{-1,1\\}$

$-10^{18} \leq b,k_i \leq 10^{18}, \forall\ 1 \leq i \leq m$

$1 \leq m \leq 10^5$

### ***Subtask***

 - ***subtask1***: $10\\%$ $|b|,|k_i| \leq 10^5$, $m \leq 100$
 - ***subtask2***: $10\\%$ $|b|,|k_i| \leq 10^5$, $m \leq 10^3$
 - ***subtask3***: $10\\%$ $|b|,|k_i| \leq 10^9$, $m \leq 10^4$
 - ***subtask4***: $10\\%$ $|k_i| \leq 10^{18}$, $b = 0$, $m \leq 10^5$
 - ***subtask5***: $10\\%$ $|b|,|k_i| \leq 10^9$, $m \leq 10^5$
 - ***subtask6***: $50\\%$ ***As statement***

<div style="page-break-after: always"></div>
