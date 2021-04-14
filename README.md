<p align="center">
<img src="terminal.gif" alt="My logo of Holberton"/>
</p>

# C - Simple Shell
_A shell is a user interface for access to an operating system’s services. Most often the user interacts with the shell using a command-line interface.

## Files
AUTHORS: Contains information about authors

README.md: Contains information about this project

shell.h: Header file, contains all prototypes for funcitons used

builtins.c: File of function to exit the shell where it is currently running

format_error.c: File of manage the rror and print a format error

get_env.c: File of gets the environ variable

get_line.c: File of function that get lines

main.c: Main file

new_strtok.c: File of function that extract tokens from strings

new_realloc.c: File of reallocate the memory space

signal.c: File of function of detected ctrl + c or ANSI C signal handling

split_line.c: File of tokenizes a line with a delimiter

string_funcs.c: Function file for working with shell files

string_funcs2.c: Function file for working with shell files

## Installation
Use the git clone to install this super simple shell.

```bash
git clone https://github.com/01Eddie/simple_shell.git
```
## Compilation
Your code will be compiled this way:
```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
The build will create a file with hsh, then continue to run the following commands.
```bash
$ ./hsh
$
```

## Example
```bash
$ /bin/ls -l
-rwxr-xr-x 1 eddie eddie  18824 Apr 13 02:01 a.out
-rw-r--r-- 1 eddie eddie    238 Apr 13 01:57 AUTHORS
-rw-r--r-- 1 eddie eddie    271 Apr 13 01:57 builtins.c
-rw-r--r-- 1 eddie eddie    688 Apr 13 01:57 format_error.c
-rw-r--r-- 1 eddie eddie    557 Apr 13 01:57 get_env.c
-rw-r--r-- 1 eddie eddie    934 Apr 13 01:57 get_line.c
-rw-r--r-- 1 eddie eddie    581 Apr 13 01:57 main.c
-rw-r--r-- 1 eddie eddie    724 Apr 13 01:57 man_simple_shell
-rw-r--r-- 1 eddie eddie    523 Apr 13 01:57 new-realloc.c
-rw-r--r-- 1 eddie eddie   1226 Apr 13 01:57 new_strtok.c
-rw-r--r-- 1 eddie eddie    510 Apr 13 01:57 no_interactive.c
-rw-r--r-- 1 eddie eddie    666 Apr 13 01:57 print_funcs.c
-rw-r--r-- 1 eddie eddie   1884 Apr 13 01:57 program_exec.c
-rw-r--r-- 1 eddie eddie    300 Apr 13 01:57 read_line.c
-rw-r--r-- 1 eddie eddie    450 Apr 13 01:57 README.md
-rw-r--r-- 1 eddie eddie 459020 Apr 13 01:57 shell.gif
-rw-r--r-- 1 eddie eddie   1333 Apr 13 01:57 shell.h
-rw-r--r-- 1 eddie eddie    268 Apr 13 01:57 signal.c
-rw-r--r-- 1 eddie eddie    732 Apr 13 01:57 split_line.c
-rw-r--r-- 1 eddie eddie    725 Apr 13 01:57 string_funcs2.c
-rw-r--r-- 1 eddie eddie   1814 Apr 13 01:57 string_funcs.c
```
```bash
$ ls
a.out		main.c		  program_exec.c  split_line.c
AUTHORS		man_simple_shell  read_line.c	  string_funcs2.c
builtins.c	new-realloc.c	  README.md	  string_funcs.c
format_error.c	new_strtok.c	  shell.gif
get_env.c	no_interactive.c  shell.h
get_line.c	print_funcs.c	  signal.c
```
```bash
$ pwd
/home/eddie/Desktop/proj/simple_shell
```
```bash
$ hh
./a.out: 7: hh: not found
```
```bash
$ exit
```
# Authors
Eddie Huaripayta Gonzales <eddiejesus1197@gmail.com>

Alex Rivera Cruz <alexriveracruz4@gmail.com>