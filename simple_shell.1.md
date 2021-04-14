% Manpage for simpleShell.
% Contact 2810@holbertonschool.com or 2830@holbertonschool.com to correct errors or typos.
% "man" (8) 1.0 
% "04 April 2021" 
% "simpleShell man page"

# NAME
simple shell - terminal shell that take imput from user and execute some commands.

# SYNOPSIS
**$.** ./hsh
/bin/[**command**] [**option**]

# DESCRIPTION
In Unix terminology, a tty is a particular type of device file that implements a number of commands provided by our computer hardware. For example, with the input that comes from the keyboard and the output that goes to a screen in text mode or with an input/output that are transmitted through a line.

# RETURN 
    The shell returns a numbers of options for execute and navigate for the functions. This means returns values depending on the function.

# OPTIONS

**$** pwd
- Print the full filename of the current working directory.
**$** ls
- List  information  about  the FILEs (the current directory by default). Sort entries alphabetically if none of -cftuvSUX nor --sort  is  specified.

# EXAMPLE

**$** pwd
/home/eddie/Desktop/proj/simple_shell

**$** ls -l
-rw-r--r-- 1 eddie eddie    271 Apr 13 01:57 builtins.c
-rw-r--r-- 1 eddie eddie    688 Apr 13 01:57 format_error.c

# SEE ALSO
I Nothing else

# BUGS
No know bugs.

# AUTHOR
**Eddie Huaripayta** (eddiejesus1197@gmail.com>)
**Alex Rivera** (alexriveracruz4@gmail.com)
