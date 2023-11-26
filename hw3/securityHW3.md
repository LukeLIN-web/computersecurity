#### Problem1

```
echo 1 | sudo tee /proc/sys/kernel/randomize_va_space
```

Conservative randomization. Shared libraries, stack, `mmap()`, VDSO  are randomized. Heap not randomized

#### Problem2

Two additional bufferoverflow countermeasures are the stack guard protection and the nonexecutable stack scheme. Why are these schemes effective against bufferoverflows and how can they be disabled? Explain.

The non-executable stack scheme prevents the execution of code residing in the stack memory. It marks the stack memory as non-executable,
Disable: `execstack -s p1`

```
Fail : execstack -s p1execstack: dso.c:877: reopen_dso: Assertion `dso->shdr[j].sh_size == 0' failed.Aborted (core dumped)
```

Stack guard protection involves placing a random value, known as a "canary," between the local variables and the return address on the stack. The canary value is checked before a function returns. If it has been modified (indicating a buffer overflow), the program terminates to prevent the execution of malicious code.
in GCC, you can disable stack canaries using the `-fno-stack-protector` flag.

`g++ -o p1 problem1.cpp  -fno-stack-protector g++ -o p1 problem1.cpp --z execstack`

I find On Ubuntu 18.04 it cannot work problem. I need ubuntu16, MacM1 is not support Virtualbox. So we need Windows to Virtualbox.

Virtualbox 6.0.18 has bug, cannot run.

someone say : update  6.1.3can solve. And I proves it. 

Launch VM fail. 

Problem1				a) Write a simple program with **two buffers**, one storing data on the **stack** and the other on the **heap**.#include <stdio.h>#include <stdlib.h>int main() {int stack_var = 42; // Stack variableint* heap_var = malloc(4); // Heap variableif (heap_var == NULL) {perror("malloc");return 1;}printf("Stack variable address: %p\n", &stack_var);printf("Heap variable address: %p\n", heap_var);free(heap_var);return 0;}

 b) Print out their addresses to see whether the stack and heap are allocated in different places every time we run the program and discuss your findings. Run the program with:					Both stack and heap randomization are switched offecho 0 | sudo tee /proc/sys/kernel/randomize_va_space
![img](https://lh7-us.googleusercontent.com/iHUyJrn-nMOqxVvjHMZiDdizYmqBRVN5ftUDeLSJTLFTblhcMBThuawaZLHoA3BLVyxlAF7IKNKbl3UQJq3j23W82nbyduGeRXWS6kr42NOypBR3QK7gS-SyNhu7pB5QkuOgC4NwIOiJiYmE493ceY0)
 												 							
Only stack randomization switched onThis command requires ubuntu16， this command cannot work on Ubuntu 22.04. It cannot work in Mac VM, so I use a Windows VM.
echo 1 | sudo tee /proc/sys/kernel/randomize_va_space
![img](https://lh7-us.googleusercontent.com/ssKFqCPr41NjVw4xTMoEBRamZU6iEBQLW94mClMlKxeNUP467MYjCaUn9oVAw9q4JZOy1qhi4BM6UHoYmQHRzFksEF9RI2EL1gQRu5YhlVnQ5hZGNV7j-rdvzvFNO9vlh1YAfiKgma3NFKsJSwkJ28Y)
								 							
Both stack and heap randomization switched on 
 						echo 2 | sudo tee /proc/sys/kernel/randomize_va_space		![img](https://lh7-us.googleusercontent.com/Yk3HTzhvPVZ7ubPyEqiSw9ucwkpMup-aJG3hDA6c-NbVsHU_6xLMx4zcxm2KWYqGIO0ZH916PuNNof2lX1qWpRn0iwl3WIyk0uxvpZ8bYFAeFGYS3-HS8RRzOkdhJg733jbi4qScam5LEDPhf_KaYB4)										Problem2				More Countermeasures: The stack guard protection and the non-executable stack scheme are additional buffer-overflow countermeasures. Why are these schemes effective against buffer overflows, and how can they be disabled? Explain.The non-executable stack scheme prevents the execution of code residing in the stack memory. It marks the stack memory as non-executableDisable: *-z execstack*Turn off the NX protection to make the stack executable Stack guard protection involves placing a random value, known as a "canary," between the local variables and the return address on the stack. The canary value is checked before a function returns. If it has been modified (indicating a buffer overflow), the program terminates to prevent the execution of malicious code. in GCC, you can disable stack canaries using the -fno-stack-protector flag.gcc -o p1 probelm1.c -fno-stack-protector -z execstack**Note:** All the previously mentioned countermeasures must be **disabled** when performing our buffer overflow attacks. Problem3	a) Compile and run the following code and see whether a shell is invoked. (Provide screenshots) ![img](https://lh7-us.googleusercontent.com/zZHnrms2EH0NRK6MujnaXhPvZ9mW-xURtvnytQ1-Kw-p11rmoYjHvexzIikf0bmXsI8Yq0qell_JKbyLyeQHHoDxlsN4p3WfFNfRXeBwIIIEkILIA7qw1kmCNVQMJEgt8xsSsrO1TAgVAzyV7AgAOTQ)	b) What happens if you disable the executable stack option? (Provide screenshots) 	 MAC VM ubuntu 22.04 can not work, I tried on Windows VM Ubuntu 16.04gcc -o sc1 shellcode.c -fno-stack-protector -z execstack 
![img](https://lh7-us.googleusercontent.com/2Uai8UbYkvnOfwptBUtdvzdrhCYsdptZKWLGU3XU41R7r2uaCDIkdCllNEGZcECOmyqnZHS-1l7JbUgQvUGttGDkYR-QjaQEhuzSnCJsj01J6QzNhbX8boMAvechobi9ifYTwfhgH92xjJ6G4OpX1UU)And successfully open a terminal.
		Problem 4 a)	strcpy(buffer, str); This line is the buffer-overflow vulnerability exists.b) After the compilation, we need to make the program a root-owned Set-UID program. **Why?** **The permission mode '4755' sets the Set-UID bit on the file. The '4' at the beginning indicates a Set-UID permission. When you execute a Set-UID program, it runs with the privileges of the file's owner (in this case, 'root'). The '7' indicates that the owner can read, write, and execute the file. This step is important because it allows a non-privileged user to execute the program with root privileges.**Problem 5Compile your vulnerable program with the appropriate debugging flags switched on. gcc -g bof.c -o bof -z execstack -fno-stack-protector		 							
b) In your debug session, identify when the foo function is called and print the value (address) of the frame pointer stored in the **ebp** register and the start address of your **buffer**. (Provide screenshots)![img](https://lh7-us.googleusercontent.com/VIJnHyfZC1ySPHAX8F9LCFBW5raoz2wgN4mdfbwFbHep0N5HRHsnSp1kXNystIeG_xbml4YhII3kxd0I_5N4djr_DAkKYRg9NMjKPVdj02LOpp07Hw5pyR8XNFBoBUdC_PEKUoGu4GEZTpViQWLXN8o)Ebp address =  0xbfffebe8print &buffer can print the start address of your **buffer**![img](https://lh7-us.googleusercontent.com/5FcTsHWeX8LPx3JNwkadk4vLp3usu_QJ4r57Ov3YIHiVNSKrN6eRpQcWxdP8Pzvw_3gQ2j8PYfcsqqqoBHlKJMqYBvFbqf2NN6oluD_5UaIZ9Pd3TnnRXvkzJZOXEWzhJg8EEVjh6nuTH99clNW5d5M)c) What is the **distance** between **ebp** and the **buffer's starting address**? Distance = ebp - buffer_address = 0xe8 - 0x7c = 232 - 124 = 108 = 0x6c

Problem 6
Our content length = 300# Put the address at the "calculated" offset# Place the return address in the NOP range ret = 0xbfffec38 # content[112:116] = (ret).to_bytes(4, byteorder='little')

If we directly jump to the buffer start addressIt will lead to segment fault because the function is not returned. What’s more, gdb will change the address of ret. Therefore, we need to override the return address of foo function, let foo return successfully, and jump to our shellcode. We need to modify eip, jump to the NOP range, it cannot be very close to ret 0xbfffebe8, which is found in gdb,, otherwise, we will meet an illegal instruction error. 
 the **distance** between **ebp** and the **buffer's starting address =108****So ebp +4 = 112 = ret address, we can rewrite it in** content[112:116]

c)![img](https://lh7-us.googleusercontent.com/kdY9CM4jVb__iNU40PgOj4r0oQioUfDCuif7RpPpuLRG6DkfadoTHzmER3xrG7Nx_EEoMCqdBPQN_eh3zMcfhRwye89SpUqTWdk1mdAyS0GD_S3bP9gQUDKOFNPzKeEeVwd5gLh-3pG6h8nhupJKtis)
