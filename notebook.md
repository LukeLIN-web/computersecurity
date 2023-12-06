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

彩虹表, 如果未匹配，说明明文不在 `R(k-1)` 位置，继续假设它在 `R(k-2)` 位置，因为使用了`k`个不同的`R`函数运算，所以需要对密文重新进行 `R(k-1)`，`H`，`Rk` 三次运算，将计算结果继续在哈希链结束位置进行查找匹配.

#### 防御彩虹表攻击

我们注意到彩虹表使用了一个相同的`H`函数，如果我们使用不同的`H`函数，这样它的彩虹表将必须使用相同的`H`函数才能有效，这种方法称为加盐。

通过加盐可以轻松地防止彩虹表攻击，该技术是将随机数据与纯文本一起传递到哈希函数中，这样可以确保每个密码都有一个唯一的生成的哈希，因此可以防止彩虹表攻击，该攻击基于一个原则，即多个文本可以具有相同的哈希值。

#### access control, AC list.

- An Access Control List (ACL) for a resource (e.g., a file or folder) is a list of zero or more Access Control Entries (ACEs)

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

CBC 比  ECB 的优点: 更随机,更复杂, 如果一个密文块被破坏，后续所有块的解密也会出错，这有助于检测数据篡改。

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

### 期中考

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

## AES的步骤

1) Take 128-bit input n for AES scrambling
2) Generate a key, say 128-bit, k
3) Define a constant 2048-bit (256-bytes) table S
4) Define a constant 2048-bit table S’

5) S and S’ are expanded into four 8192 bits (1024 bytes) tables: T0, T1, T2, T3. These tables are defined by the figure below:

6) AES uses two 128-bit (16-byte) auxiliary arrays, x and y
7) Array x is initialized to k
8) Array x is chunked into 4 4-byte arrays: x0, x1, x2, x3
9) Compute Array e as = (S[x3[1]]⊕1, S[x3[2]], S[x3[3]], S[x3[0]]
10) Array y = (y0, y1, y2, y3) is then modified as follows:
11)  AES again modifies Array x with ⊕2 this time
12)  On the 10th round, because we have a 128-bit key, Array y is modified with (S[], S[], S[], S[]) because there is no mixing.

#### 网络侧信道攻击

根据来回的时间,  得知加密需要的时间,可以拟合函数, 来推测发送的可能是哪些bit. 

nmap可以扫描端口 

Metasploit 是一个强大且全面的开源渗透测试框架。

distccd 是存在漏洞的 一个软件。 

## week6

Cross-Site Request Forgery csrf

csrf， 通过用户的浏览器来发送请求， 需要让用户点击链接， 或者一张图片， 例如`<img src=…> `

XSS vs. CSRF, Do not confuse the two:

- XSS exploits the trust a client browser has in data sent from the legitimate website , So the attacker tries to control what the website sends to the client browser

• CSRF exploits the trust a legitimate website has in data sent from the client browser,  So the attacker tries to control what the client browser sends to the website 控制发给网站的内容.  比如visa支付

## week8

#### memory protection机制

Memory management unit (MMU) generates exception if something is wrong with virtual address or associated request

• OS maintains mapping tables used by MMU and deals with raised exceptions

单user, 最简单的是 fence.

#### military security model 

通过 Bell–LaPadula，用户只能在自己的安全级别或以上创建内容（即秘密研究人员可以创建秘密或绝密文件，但不得创建公共文件；不得记下）。相反，用户只能查看等于或低于其自己的安全级别的内容（即秘密研究人员可以查看公共或秘密文件，但不能查看绝密文件；无法阅读）。

## week11


SGX（Software Guard Extensions）和TrustZone是两种安全技术.

1. SGX（Software Guard Extensions）：
   - SGX是由英特尔（Intel）开发的硬件安全扩展技术，旨在保护应用程序的代码和数据免受物理攻击和恶意软件的威胁。
   - SGX通过创建受信任的执行环境（被称为Enclaves）来实现隔离。Enclaves是一种受硬件保护的内存区域，其中的代码和数据对操作系统和其他应用程序是不可见的。
2. TrustZone：
   - TrustZone是一种硬件和软件协同工作的安全技术，广泛用于ARM架构的处理器中，包括许多移动设备和嵌入式系统。
   - TrustZone通过将处理器分为两个隔离的世界（安全世界和普通世界）来实现隔离。安全世界是一个受信任的执行环境，可以运行受保护的代码和处理敏感数据。
   - TrustZone可用于安全启动、数字版权管理、安全存储、身份验证等多种用途，以增强设备的安全性和可信度。

总的来说，SGX和TrustZone都是硬件级别的安全技术，用于隔离和保护敏感数据和代码。SGX是由英特尔开发，主要用于x86架构的处理器，而TrustZone主要用于ARM架构的处理器。这些技术有助于提高计算设备的安全性，防止恶意攻击和数据泄漏。

## week13

Summary - PUF

- ▪  A PUF is a digital fingerprint of a hardware device

- ▪  PUF relies on process variations to define its challenge response behavior and it

  cannot be cloned physically

- ▪  PUF can be attacked by mathematical modeling

- ▪  Secure lightweight strong PUF research is still an open problem

- ▪  PUF designs can be based on well known computational hardness assumptions

- ▪  Interfaces need to be considered and designed together with PUFs for various applications

- ▪  ML Attacks, Software Simulators and Hardware Implementations of Arbiter PUF, XOR APUF, IPUF are available at https://github.com/scluconn/DA_PUF_Library

Weak PUFs vs Strong PUFs

- ▪  If the challenge space of a PUF is limited (not exponentially large with the physical size of the PUF), then it is a weak PUF

- ▪  Otherwise, it is a strong PUF

- ▪  Why does this matter?

   The CRPs of a weak PUFs can be exhaustively read out by an attacker, then the PUF has no secret anymore.

   Weak PUF alone is not appropriate for authentication. We have to use a strong PUF

- ▪  Weak PUFs: SRAM PUF (power-up states), DRAM PUF (data retention time), Ring

  Oscillator PUF (circuit delay, oscillating frequency)

- ▪  Strong PUFs: arbiter PUF (circuit delay), XOR arbiter PUF, interpose PUF

- ▪  Convert a weak PUF to a strong PUF: AESWeakPUF(C)

## 期末考

slide, 作业, 笔记可以打印, 不能带ipad和电脑.

1 为什么加密结果不同?  

 加密的时候有randomness, 

 plain text有padding.

Softame/Eurpleventat.is issues

2 bob 可以怎么 问alice,  证明她是alice? 

 先 steup. Charile 给A和B   秘钥k. 

bob 发了一个随机challenge 给alice. 

a  对challenge 加密, R = K xor H(C) ,把R 发给B

V = R xor H(C) , 所以 V =k

主要就是用或非门. 

3

can Robert 找到另一个M3 和M4 使得 SHA256 (M3) = SHA256 (M4)?

不行. 因为

- Infeasible to get x, given h(x). **One-way property**
- Given x, infeasible to find y such that h(x) = h(y). **Weak-collision resistance property**
- Infeasible to find any pair x and y such that h(x) = h(y). **Strong- collision resistance property**

找到了一个碰撞, 不代表容易找到另一个. 

4 

n= 3*11, e = 3 , find d 

解:  n = p *q 

e * d = 1 mod (p-1)(q-1)  =1  mod 20 

易得 d = 7

5

同上, 这次n = p *q = 41 *59 , e=7

解

d * 7  =  1 mod 2320  如果不好计算,  写把数字带进去的式子就好

d = 7 ^-1 mod 2320

加密: 

c = p ^e  mod n =  6^7 mod 41 *59 , 这样写就可以了. 

6

p = 3, q = 11 

n = 33 

(p-1)(q-1) = 20 

找到e, 就是 7 , d = 3 . 

7

加密, DES加密, 可以用 AES解密吗? 

非对称加密, 所以不可能. 

DES是一种较旧的加密算法，使用固定的56位密钥，而AES是一种更新、更安全的加密标准，提供了128位、192.

8

说出  public key  比密码scheme的好处

1. **增强的安全性**：公钥加密使用一对密钥——一个公钥和一个私钥。公钥用于加密数据，而私钥用于解密。由于私钥不在网络上传输，因此降低了密钥泄露的风险。
2. **密钥分发简化**：在传统的对称加密中，密钥的安全分发是一个主要问题。公钥加密解决了这个问题，因为公钥可以公开分享，而私钥保持秘密。
3. **数字签名**：公钥体系还允许数字签名的使用。发送者可以用私钥对消息进行签名，接收者则可以用公钥来验证签名的真实性。这在确认消息来源和完整性方面非常重要。
4. **提高非否认性**：数字签名还提供了非否认性，即发送者不能否认他们发送了经过签名的消息。

然而，值得注意的是，公钥加密通常比对称密钥加密（如密码方案）在计算上更加昂贵。因此，它们常用于小数据量的加密或用于安全地交换对称密钥，后者再用于加密大量数据。

9 

CBC,  EBC

第九题, cec  ebc 期中考一样的

10

画出function stck frame for c函数

```c
int bof(char *str){
char buffer[24];
strcpy(buffer,str);
return 1 ;
}
```

```
|  return address|
|  str parameter|
|  24 bytes| . 高地址是buffer[23] ,低地址是buffer[0]
|  unused stack space|
|heap |
```

11

ASLR 怎么防止buffer overflow

1. Randomizationof address,  RET位置不可预测,
2. attack 不能确定injected payload的位置.
3. unpredictable memory layout. 

12

- 指出哪里会发生buffer overflow.

memcpy 

- attack 发生的地方

Scanf . overwriting. The stack beyond the allocated spce for buf 

- 怎么避免?

If  > sizeof(buffer)  printf ( error)

13

问题, 就是会修改foo.

14

ACL 就是列出,  file F,  alice能干嘛, reem能干嘛. 

capability list . 列出 ali. 可以对 file F read,

15

military security model,在 week8 -b os  106页.

a 是可以同等级读. 

b 不行, 不能向上读. 

16 

怎么防护 csrf ?

- 生成 unique token, 包含在request中,  server 检查 verify token.  reject invaded request.

17 CSRF 

18

为什么ecb不安全? 

20 

strong vs. weak puf 不可复制函数. physical unclonable function. 

有两种tee.    sgx,  trustzone

Weak PUFs vs Strong PUFs

- 弱PUF的挑战空间有限，挑战的可能性数量相对较小，与PUF的物理大小不呈指数关系。换句话说，挑战空间的大小受到限制。

- ▪  Why does this matter?

  弱PUF的挑战响应对容易受到穷举攻击，攻击者可以尝试所有可能的挑战并获取相应的响应。这意味着弱PUF的挑战响应可以被攻击者彻底读取，从而失去了秘密性。

   Weak PUF alone is not appropriate for authentication. We have to use a strong PUF

- ▪  Weak PUFs: SRAM PUF (power-up states), DRAM PUF (data retention time), Ring

  Oscillator PUF (circuit delay, oscillating frequency)

- ▪  Strong PUFs: arbiter PUF (circuit delay), XOR arbiter PUF, interpose PUF

- ▪  Convert a weak PUF to a strong PUF: AESWeakPUF(C)

21

memory protection 机制
