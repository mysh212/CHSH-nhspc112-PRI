# 彰化高中112學年度資訊學科能力競賽校內複選 題解

## **A. 二維座標** ***<font color = '#AAAAAA'> Walk </font>***

<div style="page-break-after: always"></div>

## **B. 專賣店** ***<font color = '#AAAAAA'>Vendor</font>***

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
