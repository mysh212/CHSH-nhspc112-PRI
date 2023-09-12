# 彰化高中112學年度資訊學科能力競賽校內複選 題解

簡報:\
`mysh212`: [slido](https://slides.com/ysh-1/deck/fullscreen)\
`Gamic1234`: [PDF](https://github.com/mysh212/CHSH-nhspc112-PRI/blob/master/Editorial/112_Gamic_.pdf)\
`Derek0`: [PDF](https://github.com/mysh212/CHSH-nhspc112-PRI/blob/master/Editorial/CHSH_nhspc112_PRI_editorial.pdf)

## **A. 二維座標** ***<font color = '#AAAAAA'> Walk </font>***

<div style="page-break-after: always"></div>

## **B. 專賣店** ***<font color = '#AAAAAA'>Vendor</font>***

### 問題

給你 $n$ 個點

$(x_i,y_i),\ 1 \leq i \leq n$

請求出 $\displaystyle \min \big[\sum_{k=1}^n \sqrt{(x - x_i)^2+(y - y_i)^2}\big]$

### ***subtask1***: $1\\%$ $n \leq 1,\ -10^2 \leq x_i,y_i \leq 10^2$

直接輸出該座標即可

### ***subtask2***: $2\\%$ $n \leq 2,\ -10^2 \leq x_i,y_i \leq 10^2$

輸出任一組座標

### ***subtask3***: $3\\%$ $n \leq 3,\ -10^2 \leq x_i,y_i \leq 10^2$

算出外心座標,輸出附近整數點中總距離最小的

### ***subtask4***: $4\\%$ $n \leq 10,\ -10^2 \leq x_i,y_i \leq 10^2$

唬爛用, $O(4 \times 10^{12} \times n)\ O(2 \times 10^6 \times n)$ 都會過

### ***subtask5***: $20\\%$ $n \leq 10^3,\ -10^3 \leq x_i,y_i \leq 10^3$

過渡測資

### ***subtask6***: $10\\%$ $(x_i \in \\{r|r = x_1\\}, 1 \leq i \leq n) \vee (y_i \in \\{r|r = y_1\\}, 1 \leq i \leq n)$

所有點連成一直線,輸出最中間的座標即可

### ***subtask7***: $30\\%$ $n \leq 2 \times 10^4$

可以發現固定 $x$ 或 $y$ 座標時, 總距離與另一座標所成的函數為凹函數

$pf:$

$$
[\sqrt{(x - x_i)^2+(y - y_i)^2}]'\\
 = \frac{1}{2}[(x - x_i)^2+(y - y_i)^2] ^ {-\frac{1}{2}} \times 2(x - x_i)\\
 = [(x - x_i)^2+(y - y_i)^2] ^ {-\frac{1}{2}}(x - x_i)\\
 = \frac{(x - x_i)}{\sqrt{(x - x_i)^2+(y - y_i)^2}}
$$

$$
\displaystyle
\text{let } \frac{(x - x_i)}{\sqrt{(x - x_i)^2+(y - y_i)^2}} = f'(x)\\
\frac{(x - x_i)}{\sqrt{(x - x_i)^2+(y - y_i)^2}} = 0\\
\lim_{x \rightarrow x_i-} f'(x) < 0 \text{ and } \lim_{x \rightarrow x_i+} f'(x) > 0\\
\text{When } x = x_i,\ f(x) \text{ has minimum value } f(x_i)
$$

既然為凹函數,我們只要針對目前函數的切線斜率做二分搜即可

因此我們對 $x$ 做二分搜,每次對 $y$ 再做一次二分搜,找出 **固定** $x$ **座標時,所能產生的最小總距離** 並且對 $x - 1$ 或 $x + 1$ 再搜尋一次,用以比較斜率方向, 最後往凹口搜去即可

時間複雜度 $O(n\ (log_2^n)^2)$

### ***subtask8***: $30\\%$ ***As statement***

但是我們可以發現其實不需要每次都完整地對 $y$ 做二分搜

所以可以導出更有效率的算法 -- **倍增**

由 $2$ **的次冪之和可以為任意正整數**

我們每次對 $+x, -x, +y, -y$ 四種方向做測試

每次測試嘗試 **跨出** $2^n$ **步** 如果跨出去的總距離比目前的小,則將目前的點改為該點

四種方向測試完成後讓 $n$ 遞減

但由於有 $x, y$ 兩種軸, 因此為了確保總距離最小, 需對此四個方向再測試一次

時間複雜度 $O(n\ log_2^n)$

<div style="page-break-after: always"></div>

## **C. E班的復仇** ***<font color = '#AAAAAA'> The revenge of class E</font>***

可以分成合併後兩個數字和沒有合併三個數字兩種情況討論
遍歷所有abc, acb, bac...的排列
##### 兩個數字:
在中間位置劃刀分成兩個數字，分別算 $+ - *$
##### 三個數字:
不用劃刀了，在三個數字中間枚舉 $(+, +), (+, -)...$ 九種情況
注意重複的答案不能重複算到
這部分可以用 $STL$ 中的 $set$ 處理

<div style="page-break-after: always"></div>

## **D. 守護城牆** ***<font color = '#AAAAAA'> Protection </font>***

### ***Subtask***

### ***subtask1***: $21\\%$ $1 \leq N \leq 10, \space h_i=1$
把 $d_i$ 和 $h_i$ 用 $pair$ 合併起來，對 $d_i$ 由小到大排序
如果對於所有 $d_i \leq i$ 那就是 $Yes$ ( $i$ 是從 $1$ 開始)

時間複雜度 $O(NlogN)$

### ***subtask2***: $79\\%$ ***As statement***
用一個變數紀錄到目前為止花了多少時間，若有某個時刻花的時間大於 $d_i$ 就輸出 $No$

時間複雜度 $O(NlogN)$

<div style="page-break-after: always"></div>


## **E. 文字獄** ***<font color = '#AAAAAA'> Literary prison</font>***

### ***subtask1***: $4\\%$ $1 \leq N \leq 50$
寫一個函式判斷輸入的數字有沒有包含7
然後對於每筆詢問直接回圈判斷
詳細可以看程式碼的地方

### ***subtask2***: $17\\%$ $1 \leq N \leq 10^5$
一樣寫一個函式判斷輸入的數字有沒有包含7
但先預處理紀錄答案
後續詢問直接查表

### ***subtask3***: $79\\%$ ***As statement***
因此把$N$轉換為九進制的表達法
如果某個位數大於等於7的話把那個位數 $+1$
時間複雜度 $O(T\space log_9 N)$

<div style="page-break-after: always"></div>

## **F. 練習時間** <font color = 'gray'>***Practice***</font>

<div style="page-break-after: always"></div>

## **G. 橘子** ***<font color = '#AAAAAA'> Oranges </font>***

<div style="page-break-after: always"></div>

## **H. 最淺樹** ***<font color = '#AAAAAA'> Minimum Height Trees </font>***

<div style="page-break-after: always"></div>

## **I. 環** ***<font color = '#AAAAAA'> Cycles </font>***

<div style="page-break-after: always"></div>

## **J. 氣球** ***<font color = '#AAAAAA'> Balloon </font>***

<div style="page-break-after: always"></div>
