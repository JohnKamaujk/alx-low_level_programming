# Debugging project

Debugging is the process of finding and fixing errors in software that prevents it from running correctly. As you become a more advanced programmer and an industry engineer, you will learn how to use debugging tools such as `gdb` or built-in tools that IDEs have. However, it’s important to understand the concepts and processes of debugging manually.

# Learning Objectives

* What is debugging
* What are some methods of debugging manually
* How to read the error messages

# Tasks

## Multiple mains

In most projects, we often give you only one main file to test with. For example, this main file is a test for a `positive_or_negative()` function similar to the one you worked with in [an earlier C task](https://github.com/JohnKamaujk/alx-low_level_programming/blob/main/0x01-variables_if_else_while/0-positive_or_negative.c):

```
$ programmer@ubuntu:/debugging$ cat main.c
#include "holberton.h"

/**
* main - tests function that prints if integer is positive or negative
* Return: 0
*/

int main(void)
{
        int i;

        i = 98;
        positive_or_negative(i);

        return (0);
}
$ programmer@ubuntu:/debugging$
```

```
$ programmer@ubuntu:/debugging$ cat holberton.h
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

void positive_or_negative(int i);

#endif /* MAIN_H */
$ programmer@ubuntu:/debugging$ 
```

```
$ programmer@ubuntu:/debugging$ gcc -Wall -pedantic -Werror -Wextra positive_or_negative.c main.c
$ programmer@ubuntu:/debugging$ ./a.out
98 is positive
$ programmer@ubuntu:/debugging$
```

Based on the `main.c` file above, create a file named `0-main.c`. This file must test that the function `positive_or_negative()` gives the correct output when given a case of `0`.

