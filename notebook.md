https://sites.google.com/view/ececs230kaust/lectures?authuser=0

密码: ECECS230-Fall2023-XK-KAUST

## Week1

Principles of design

1. Principle of least privilege
2. Principle of fail-safe defaults 默认设置应该是安全的
3. Principle of economy of mechanism 尽量简单
4. Principle of complete mediation
5. Principle of open design 不依赖某种具体实现
6. Principle of separation of privilege 不要把鸡蛋放在一个篮子里
7. Principle of least common mechanism
8. Principle of psychological acceptability 人容易access. 

threat model

## Week2

password cracking的不同方式

1. Brute force
2. **dictionary ** rainbow table, 计算一些简单密码的hash之后. 

### rainbow table

rainbow tables

是一个precompute table for  reversing cryptographic hash functions.

H运算, 根据明文计算出其哈希值

R运算, 比如截取`H`[函数值](https://www.zhihu.com/search?q=函数值&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"article"%2C"sourceId"%3A"105578739"})的前**8**个字符.

优点:  

缺点: tradeoff  time vs. space 

#### 破解方法

hash 值, 我们第一次使用`R`函数对其进行运算，得到了`Y=R(X)`； 

对比成功, 由于不可逆，所以我们就开始从这条链的开始位置开始重复**H**，**R**运算，

对比失败, 需要将第一次R运算的结果**`Y=R(X)`**进行一次**H**运算，再将运算的结果再进行一次**R**运算，得到了**`Y2`**，再将**`Y2`**与**所有哈希链**的结尾位置进行比对，又会出现比对成功和比对失败；

彩虹表, 如果未匹配，说明明文不在 `R(k-1)` 位置，继续假设它在 `R(k-2)` 位置，因为使用了`k`个不同的`R`函数运算，所以需要对密文重新进行 `R(k-1)`，`H`，`Rk` 三次运算，然后将计算结果继续在哈希链结束位置进行查找匹配.

#### 防御彩虹表攻击

我们注意到彩虹表使用了一个相同的`H`函数，如果我们使用不同的`H`函数，这样它的彩虹表将必须使用相同的`H`函数才能有效，这种方法称为加盐。

通过加盐可以轻松地防止彩虹表攻击，该技术是将随机数据与纯文本一起传递到哈希函数中，这样可以确保每个密码都有一个唯一的生成的哈希，因此可以防止彩虹表攻击，该攻击基于一个原则，即多个文本可以具有相同的哈希值。

#### access control, AC list.

- An Access Control List (ACL) for a resource (e.g., a file or folder) is a list of zero or more Access Control Entries (ACEs)
- 

## Week3

Understand the difference between symmetric and asymmetric cryptography 

• Understand and use one-way hash functions
 • Cryptographically suitable pseudorandom number generation



### 加密的方法

transpotion :  横着写,  密文 竖着列出来.

Caesar cipher: 很容易破解,  

#### 当代对称加密

block ciphers , 分成block , 每块加密. 

AES, Advanced Encryption Standard , DES,非常难暴力破解

CBC 比  ECB 的优点

#### 非对称加密

RSA, 用了素数分解. RSA 和其他非对称加密都是非常慢的. 

### 哈希函数性质 

- Infeasible to get x, given h(x). **One-way property**
- Given x, infeasible to find y such that h(x) = h(y). **Weak-collision resistance property**
- Infeasible to find any pair x and y such that h(x) = h(y). **Strong- collision resistance property**

单向散列函数（one-way hash function）对于每一个输入，[函数值](https://www.zhihu.com/search?q=函数值&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})都容易计算（[多项式时间](https://www.zhihu.com/search?q=多项式时间&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})），但是给出一个随机输入的函数值，算出原始输入却比较困难（无法在多项式时间内使用确定性[图灵机](https://www.zhihu.com/search?q=图灵机&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A"367241856"})计算）。

抗冲突性是加密散列函数的一个属性：如果很难找到两个散列到同一输出的输入，则散列函数H是抗冲突的*collision resistance*

Collision resistence 并不是指不会有哈希碰撞，而是指没有高效的方法去人为地制造哈希碰撞。只能靠暴力求解，而这个在实际情况下是不可解的。 举个例子，给定一个 x，他的哈希值是 H(x)，找一个 y，让 H(x)=H(y)。没有什么高效地方法去找 y，大部分情况下只能暴力枚举(brute-force) 

另外，有些哈希函数，以前我们认为他是 collision resistance 的，但是后来人们找到了人为制造哈希碰撞的方法，所以他就不是 collision resistance 的了，比如 MD5，

### HMAC

**Hash Message Authentication Code** 主要应用在服务器对访问者进行身份认证流程中。MAC有不同算法, 其中一种是hash.

1 客户端发送请求 2 服务器返回一个随机值，并在会话中记录这个随机值 3. 客户端将该随机值作为共享的密钥，用户密码进行hmac运算，然后提交给服务器. 4. 服务器把用户密码和步骤2中发送的随机值做与客户端一样的hmac运算，然后与用户发送的结果比较，如果结果一致则验证用户合法。

### 数字签名

非对称加密算法 .  signer 用私钥加密, verifier用公钥解密.  

## Week4

sign mismatch, 数据类型不同, 就可能有问题, 比如int 是signed, 最高到 2^31 -1, 但是strlen(input) 是0到2^32-1

Types of unintentional flaws

• Errors
 • Integer overflows
 • Buffer overflows
 • Format string vulnerabilities • Incomplete mediation
 • TOCTTOU errors



### program  security

10月3日考试, slide, 作业, 笔记可以打印, 不能带ipad和电脑.

范围: 

password cracking的不同方式

10个 design pricinciple

buffer overflow.

Hash function的三个性质

RSA, 密码学.

private key, AES, access control, AC list.

rainbow table. 

authentic. HMAC 和数字签名



## Week5

### stackoverflow

如果在调用函数时，不小心将 `返回地址` 覆盖了，那么调用完函数后，将不会跳转到原来的函数继续执行，而是跳转到覆盖后的地址执行。如下图所示

在函数stack, 你自己输入内存地址, 程序就会crash.

PPT的图,是上面内存地址大, 下面内存地址小, 所以返回地址是在 buffer 后面. 

怎么知道return address在哪里?

  repeat the address that we want the function to return to LOTS of times.  



#### 本地shellcode

shellcode是一段用于利用软件漏洞而执行的代码，以其经常让攻击者获得shell而得名。shellcode常常使用机器语言编写。

shellcode可以按照攻击者执行的位置分为本地shellcode和远程shellcode.

本地运行的shellcode经常用于利用软件漏洞提升权限。比如在Linux下由普通权限提升至root权限。

EGG = NOPS+ SHELLCODE+ ADDRESS 

NOPS = EGG- SHELLCODE-ADDRESS  = 108-20-4 = 84

#### solution

导致 `栈溢出攻击` 的原因就是：调用 `memcpy()`、`strcpy()` 等函数复制数据时，没有对数据的长度进行验证，从而 `返回地址` 被复制的数据覆盖了。 

1. canary , 放一个chosen number 放在buffer和重要返回地址之间. 如果这个值被修改了就有问题. 
1. 换成java 可以内置 all bounds checking
1. Memory: Non-executable stack
1. OS: Stack (and sometimes code, heap, libraries) at random virtual addresses for each process

找返回地址,  2bytes, 有一个00000000, 地址在这个的后面.  
