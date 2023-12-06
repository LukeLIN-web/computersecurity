HW2

**Problem 1** (15 Points): Hash functions: In class we discussed several desirable properties for hash functions, in particular one-wayness and collision-resistance. In this exercise, we’ll show that neither property implies the other. We can do this by counter-example:

1. a)  First, define a function that is one-way, but not collision- resistant.

   **Hint:** The answer will be a trivial function that you would never use as a cryptographic hash function.

1. b)  Second, define a function that is collision-resistant, but not one-way.

   **Hint:** Assume you have a collision-resistant hash-function H. Use that to build a hash function H’ which is still collision- resistant, but not one-way.

**Problem 2** (15 Points): Consider the following C code. What is the problem? Explain.

```c
int a, b;
int sum=a+b;
cout<<"Enter two numbers to add: ";
cin>>a;
cin>>b;
cout<<"The sum is: "<<sum;
```

A: The problem is sign mismatch, two `int` type number addition may out of the range the `int` . It can cause overflow. For example, INT_MAX + 1 = INT_MIN

**Problem 3** (30 Points): Simple Reverse Engineering Course.
 There’s a **Linux** binary file called **doorkeeper**, which has two password checks. Try to crack the two passwords. Show your cracking progress by screenshot step by step. To simplify the process, the debug information is reserved, and the optimization is disabled.

### problem4

位加密, 第一个是0, 那么一定是 A, 第一个是1, 那么一定是D. 然后猜第二个. 

#### b)  

Second, **decompile** the provided binary and **identify the functions** (e.g., names, input-output parameters, etc.) used for the encrypted password generation. (25 points)
 **Hint:** For function symbols, you shall look 

```c
char *__cdecl blowfish_encryption(int a1)
{
  int i; // [esp+10h] [ebp-28h]
  int v3; // [esp+14h] [ebp-24h]
  char v4[9]; // [esp+23h] [ebp-15h] BYREF
  unsigned int v5; // [esp+2Ch] [ebp-Ch]

  v5 = __readgsdword(0x14u);
  v3 = 0;
  for ( i = 0; i <= 7; ++i )
  {
    v3 = block_func(*(char *)(i + a1) - 48, v3);
    v4[i] = v3 + 48;
  }
  return v4;
}
```

names:  blowfish_encryption

input-output parameters 

input: int

output: char* 

####  Third

 identify the steps of the password generation algorithm. Provide clear explanations on how the input is transformed to the output in a step-by-step fashion. (40 points)
 **Hint:** A chain, everything is 

```c
int main(int argc, const char **argv, const char **envp)
{
  if ( argc == 2 )
  {
    strcpy(&password, argv[1]);
    pass_len = strlen(&password);
    if ( pass_len > 8 )
    {
      puts("Password too long! Provide **numeric** passwords up to 8-digits.");
      return 1;
    } 
    for ( i = pass_len; i <= 7; ++i )
      *(&password + i) = 32;    #if <=8,  append space to 8 length.
    enc_output = (int)blowfish_encryption((int)&password);
    convert_to_char((_BYTE *)enc_output);
  }
  else if ( argc <= 2 )
  {
    puts("Feed me passwords...");
  }
  else
  {
    puts("Too many inputs...try again");
  }
  return 0;
}
```



