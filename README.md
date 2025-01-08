# Get Next Line

## About the Project

**Get Next Line** is a project from 42 that challenges students to create a function capable of reading a line from a file descriptor, one line at a time, until the end of the file. The function should be efficient and handle edge cases such as very long lines or multiple file descriptors being read simultaneously.

---

## Mandatory Features

- Implement the function `char *get_next_line(int fd)`.
- The function should:
  - Return the next line read from the file descriptor `fd`.
  - Work for both standard input and regular files.
  - Manage memory efficiently to avoid leaks.
  - Handle multiple file descriptors at the same time without mixing their data.
- Lines are terminated by a newline character (`\n`) or by the end of the file.
- The function must return `NULL` when there are no more lines to read or in case of an error.

---

## Allowed Functions

- `read`
- `malloc`
- `free`
- `write`

---

## Technical Requirements

- The code must follow the 42 Norm.
- No usage of static or global variables is allowed.
- The function must work with a customizable buffer size defined at compile time (`BUFFER_SIZE`).
- Memory must be properly allocated and freed to avoid leaks.

---

## Testing the Project

You can test the functionality of `get_next_line` by compiling it with a simple main function or using external testers available online, such as:

- [42FileChecker](https://github.com/jgigault/42FileChecker)
- [gnl-war-machine](https://github.com/42Tester/gnl-war-machine)
- [gnl-lover](https://github.com/charMstr/GNL_lover)

---

## Compilation

To compile the project, use the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Replace `BUFFER_SIZE` with the desired value to test different scenarios.

---
