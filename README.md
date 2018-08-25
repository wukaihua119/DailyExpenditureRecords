# DailyAccountProgram
It is a program that can record your daily expense, income and compute your account balance.

## Features
* Record daily expense.
* Record daily income.
* Uncover and record the detail of cash flow.
* Calculate your total balance and expense automatically.

## Building
Download the *.c, *.h and Makefile.

To compile DailyAccountProgram.
<pre><code>$ make Accounts
or
$ gcc -o Accounts Accounts.c IN.c OUT.c
</code></pre>

To execuate DailyAccountProgram.
<pre><code>$ ./Accounts
</code></pre>

## Instructions
Press "1" to input your cash flow and output your total balance and expense.

Press "2" to output your total balance, expense and other information that you inputs.

* The length of any of strings that you input must be within 19 characters, of which the last character is '\0'.



