#### Problem1

We can use `pie` to switch one on and one off





#### Problem2

Two additional bufferoverflow countermeasures are the stack guard protection and the nonexecutable stack scheme. Why are these schemes effective against bufferoverflows and how can they be disabled? Explain.

The non-executable stack scheme prevents the execution of code residing in the stack memory. It marks the stack memory as non-executable,
Disable:execstack -s p1
Fail : execstack -s p1execstack: dso.c:877: reopen_dso: Assertion `dso->shdr[j].sh_size == 0' failed.Aborted (core dumped)

Stack guard protection involves placing a random value, known as a "canary," between the local variables and the return address on the stack. The canary value is checked before a function returns. If it has been modified (indicating a buffer overflow), the program terminates to prevent the execution of malicious code.
in GCC, you can disable stack canaries using the -fno-stack-protector flag.g++ -o p1 problem1.cpp  -fno-stack-protectorg++ -o p1 problem1.cpp --z execstack

I find On Ubuntu 18.04 no problem. I need ubuntu16, MacM1 is not support Virtualbox. So we need Virtualbox.

Virtualbox 6.0.18 has bug, cannot run.

someone say : update  6.1.3can solve.

