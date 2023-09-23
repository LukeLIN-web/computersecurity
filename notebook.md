



rainbow tables

是一个precompute table for  reversing cryptographic hash functions.

bell lapadula



### 加密的方法

transpotion :  横着写,  密文 竖着列出来. 

Caesar cipher: 很容易破解, 

block ciphers , 分成block , 每块加密. 

AES, DES,非常难暴力破解

RSA, 用了素数分解. RSA 和其他非对称加密都是非常慢的. 

数字签名

signer 用私钥加密, verifier用公钥解密. 

one-way, but not collision- resistant.

单向散列函数（one-way hash function）对于每一个输入，[函数值](https://www.zhihu.com/search?q=函数值&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})都容易计算（[多项式时间](https://www.zhihu.com/search?q=多项式时间&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})），但是给出一个随机输入的函数值，算出原始输入却比较困难（无法在多项式时间内使用确定性[图灵机](https://www.zhihu.com/search?q=图灵机&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})计算）。

在密码学中，抗冲突性是加密散列函数的一个属性：如果很难找到两个散列到同一输出的输入，则散列函数H是抗冲突的*collision resistance*

Collision resistence 并不是指不会有哈希碰撞，而是指没有高效的方法去人为地制造哈希碰撞。只能靠暴力求解，而这个在实际情况下是不可解的。 举个例子，给定一个 x，他的哈希值是 H(x)，找一个 y，让 H(x)=H(y)。没有什么高效地方法去找 y，大部分情况下只能暴力枚举(brute-force) 

另外，有些哈希函数，以前我们认为他是 collision resistance 的，但是后来人们找到了人为制造哈希碰撞的方法，所以他就不是 collision resistance 的了，比如 MD5，



sign mismatch, 数据类型不同, 就可能有问题, 比如int 是signed, 最高到 2^31 -1, 但是strlen(input) 是0到2^32-1

