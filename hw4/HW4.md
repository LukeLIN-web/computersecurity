

### Problem1



- 128 位密钥 10 轮。

\7) Array x is initialized to k

7.5    :  y ,  The second array is initialized to n ⊕ k.

9 Compute Array e as = (S[x3[1]]⊕1, S[x3[2]], S[x3[3]], S[x3[0]])

9.5  Replace (x0,x1,x2,x3) with (e ⊕ x0,e ⊕ x0 ⊕ x1,e ⊕ x0 ⊕ x1 ⊕ x2,e ⊕ x0 ⊕ x1 ⊕ x2 ⊕ x3).

10  AES then modifies y as follows. 

11  AES again modifies Array x with ⊕2 this time

 11.5   modifies y again; modifies x again, using ⊕4; modifies y again; and so on for a total of ten rounds. The constants for the x modifications are 1, 2, 4, 8, 16, 32, 64, 128, 27, 54.

12 the 10th round, because we have a 128-bit key, Array y is  modified with (S[], S[], S[], S[]) because there is no mixing.

The final value of y is the output AESk(n).



使用 correlate.c 提取结果，并在答案中粘贴最后三行（5 分）。



 找出哪些字节的每个 k[i] 低于 256（5 分）



```
生成的攻击文件的第一列显示每个 k[i] 的可能性范围（第二列）。其余列显示相应的值。



```

10 5 c6 cc c3 c8 ce c4 cd c9 c2 c0



用自己的话解释在分析过程中，如何选择某一 k[i] 的可能值少于 256。这必须是一个高层次的解释，反映出您对攻击的理解以及如何解释相关数据（仅仅复制相关代码行将不得分）（10 分）



attacker sent random 400-byte packets to the victim’s server. 

attacker correlated the resulting timings with the known timings collected 

The correlate program prints, in hexadecimal, the n[b] offsets producing large correlations.







针对一个少于 256 种可能性的特定 k[i] 索引（如果有多个选项，请选择一个），绘制 2 个图形：
a. n[i] 如何影响目标服务器内 k = i 的 OpenSSL AES 时序（10 分） how n[i] affects OpenSSL AES timings for k = i inside the targeted server (10 points)
b. 在目标服务器内随机选择 k 时，n[i] 如何影响 OpenSSL AES 时序（10 分）How n[i] affects OpenSSL AES timings for random selection of k inside the targeted server



- Daniel J. Bernstein, “Cache-timing attacks on AES”, 2005



Attack 就是 每个k的可能性







AES scrambles a 16-byte input n using a 16-byte key k

n 是数组, 

k 是啥, k是key

study.400的解读

13 是下标 400 8 是数值 4196901 发送的数量 3087.895 cycle数量 129.512 方差 3.108 比平均值的距离 0.063 这个距离的方差

This line conveys the following information: The server was sent 4196901 400- byte packets having n[13] = 8. It handled those packets in 3087.895 cycles on average, with a deviation of 129.512 cycles. Compared to the average over all choices of n[13], the average for n[13] = 8 was 3.108 cycles higher. The number 0.063 is an estimate of the deviation in this difference: if the distribution of timings is close to normal, with a deviation around 129.512 cycles, then an average of 4196901 such timings has a deviation around 129.512/ √ 4196901 ≈ 0.063 cycles. (The deviation in the average over all choices of n[13] is, presumably, 1/16th as large, and is ignored.) Other lines show similar inform

