# computersecurity

pentesting 渗透

### p1

1)The attack was conducted successfully, as shown by the screenshots (20 points)

\2) No step is missing for replicating the attack (15 points)

\3) The demonstration includes comprehensive explanations of each step, appropriate for a target audience similar to the other students taking this course (15 points)

学生必须利用并记录漏洞 CVE-2004-2687。Distcc 是一个用于在网络上的多台机器上分发 C、C++、Objective C 或 Objective C++ 代码构建的程序。distcc 应始终生成与本地构建相同的结果，易于安装和使用，并且通常比本地编译快得多。distcc 2.x（如 XCode 1.5 和其他版本中使用的），当未配置为限制对服务器端口的访问时，允许远程攻击者通过编译作业执行任意命令，这些命令由服务器在未经授权检查的情况下执行。distcc 不执行任何连接身份验证或授权，而是依赖第三方访问控制。该缺陷可能允许任意命令执行，从而导致完整性丧失。对于此问题，学生必须运行 Kali Linux 和 Metasploitable VM，并演示如何运行 distccd 漏洞利用。解释应该采取演示的形式，说明攻击的每一步，就像写报告或博客文章一样。

特别要注意以下几点：

-  演示应包括攻击的每一步，并从登录 Kali 和 Metasploitable 开始（可以省略 VM 安装）。攻击本身必须首先提取易受攻击的虚拟机的 IP（例如，使用 ifconfig）并使用 nmap 工具运行端口扫描。

- 演示应该完整、全面。考虑到目标受众与班上其他学生具有相同的水平，但没有使用 Metasploit 的经验。
-  演示应包括各个步骤的屏幕截图，突出显示重要信息（例如，正在运行哪个命令或输出中需要注意哪些信息）。演示可以采用报告（连续文本）、幻灯片或博客文章的形式。它可以以 PDF（报告/幻灯片）或 html 格式提交。无论哪种方式，演示都必须包括文字描述，

1. **设置环境：**运行 Kali Linux 和 Metasploitable VM。
2. **识别易受攻击的系统：**使用 Kali 等工具`ifconfig`来识别 IP 地址并`nmap`扫描 Metasploitable VM 上的开放端口。
3. **利用漏洞：**一旦识别出存在漏洞的服务（在本例中为 distccd），就可以使用 Metasploit 来利用该漏洞。这可能涉及在 Metasploit 中查找与 CVE-2004-2687 漏洞相关的特定模块，并使用它来获取访问权限或在远程系统上执行命令。
4. **记录过程：**每个步骤的屏幕截图和描述至关重要。这些应该突出显示所使用的命令、收集的信息以及成功的利用（如果这是目标）。





https://blcklstdbb.gitbooks.io/hackmd/content/lesson-2-samba-exploit.html



