# Holberton School - Simple Shell Project

## Description

This project is a custom implementation of a simple UNIX command line interpreter (shell), similar to the basic functionality of `sh`. It was developed as a project for Holberton School. The shell can run in both interactive and non-interactive modes.

## Learning Objectives

* Understand the fundamentals of how a shell works.
* Learn process creation and management (`fork`, `execve`, `wait`).
* Handle command line arguments.
* Manage environment variables and the `PATH`.
* Implement built-in shell commands (`exit`, `env`).
* Handle errors and the "end of file" condition.
* Utilize standard library functions like `getline`.

## Features (Incremental)

* **0.1:** Basic command execution (single word commands), prompt display, error handling for command not found, handles End-Of-File (Ctrl+D).
* **0.2:** Handles commands with arguments.
* **0.3:** Implements `PATH` handling to find executables. Avoids `fork` if the command doesn't exist in `PATH`.
* **0.4:** Implements the `exit` built-in command.
* **1.0:** Implements the `env` built-in command to print environment variables.

## Requirements

* Allowed editors: `vi`, `vim`, `emacs`
* All files compiled on Ubuntu 20.04 LTS using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* All files should end with a new line.
* A `README.md` file at the root of the folder is mandatory.
* Code must follow the Betty style guide.
* No memory leaks.
* Maximum of 5 functions per file.
* All header files should be include guarded.
* Use system calls only when needed.
* Write a `man` page for the shell (`man_1_simple_shell`).
* An `AUTHORS` file listing contributors is required.

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
Usage
Interactive Mode:

Bash

./simple_shell
(<span class="math-inline">\) /bin/ls
simple\_shell main\.c \.\.\.
\(</span>) ls
simple_shell main.c ...
($) exit
Non-Interactive Mode:

Bash

echo "/bin/ls -l" | ./simple_shell
Man Page
A man page is available. Use the following command to view it (after placing it in the appropriate man directory or using the -l flag):

Bash

man ./man_1_simple_shell
or

Bash

man simple_shell
(if installed correctly)

AUTHORS
See the AUTHORS file for the list of contributors.
