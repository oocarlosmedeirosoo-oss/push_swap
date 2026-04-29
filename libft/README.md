*This project has been created as part of the 42 curriculum by cbarbosa.*

---

#  Libft - Mine & Your Very First Own Library

##  Description

**Libft** is the first major project of the 42 curriculum. The goal is to reimplement the same exact beahavior of a set of standard C library functions from scratch, building a personal library called  `libft.a`  that can be reused in all future 42 projects.

The project is divided into four parts, however 3 of them are the main subject:

- **Part 1 - Libc functions:** Reimplementations of standard C functions (Character classification, Character conversion, String and memory manipulation, Memory copying and safety, String and memory searching, String-to-integer conversion, Dynamic memory allocation, Pointer arithmetic and generic typing.).

  > *Yes, it's long - but so is the man page for `memcpy`, and you read that too.*
  > Each concept listed is an intentional keyword, a starting point for anyone who wants to understand what's really happening under the hood before touching the code.

- **Part 2 - Additional functions:** Utility functions not present in libc or that exist in a different form, such as `ft_split`, `ft_itoa`, `ft_substr`, and the `_fd` output family.
- **Part 3 - Linked list functions:** A full set of functions to create and manipulate singly linked lists using the `t_list` structure.

- **Part 4 - README (This document):** His creation represents a new concept called Markdown.  
Markdown is a markup language that allows you to format text using simple keyboard symbols (such as # for headings or * for bold). Its purpose is to be easy to read and write in plain text, and it is widely used in documentation, READMEs, and forums.

All functions follow **La Norme** (42's coding standard) and are compiled with `-Wall -Wextra -Werror`.

---

## Instructions

### Compilation

Clone the repository and run:

```bash
Get the repository in my GitHub
Open terminal
Write and Paste the url:
git clone <repository_url>
Before pressing Enter, press Space and give it a name (example: git clone <repository_url> project_folder)
Then write and press Enter:
cd <project_folder>
Last step: run the program (Write it and press Enter):
make
```

This will compile all source files and generate the static library `libft.a` at the root of the repository.

### Available Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the library (`libft.a`) |
| `make clean` | Removes object files (`.o`) |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` |
| `make bonus` | Compiles bonus (linked list) functions |

### Usage in your project

Copy `libft.a` and `libft.h` into your project, then compile with:

```bash
cc your_file.c -L. -lft -o your_program
```

---

## Library Description

### Part 1 - Libc Functions

| Function | Description |
|----------|-------------|
| `ft_isalpha` | Returns 1 if char is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if char is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if char is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if char is in the ASCII table, 0 otherwise |
| `ft_isprint` | Returns 1 if char is printable, 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills n bytes of memory with a given value |
| `ft_bzero` | Sets n bytes of memory to zero |
| `ft_memcpy` | Copies n bytes from src to dst (no overlap) |
| `ft_memmove` | Copies n bytes safely, handles overlapping memory |
| `ft_strlcpy` | Copies a string into a sized buffer, returns src length |
| `ft_strlcat` | Appends a string to a sized buffer, returns total length |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strchr` | Returns pointer to first occurrence of char in string |
| `ft_strrchr` | Returns pointer to last occurrence of char in string |
| `ft_strncmp` | Compares up to n characters of two strings |
| `ft_memchr` | Searches for a byte value in a memory area |
| `ft_memcmp` | Compares two memory areas byte by byte |
| `ft_strnstr` | Finds the first occurrence of a substring within n bytes |
| `ft_atoi` | Converts a string to an integer |
| `ft_calloc` | Allocates memory for an array and zeroes it |
| `ft_strdup` | Allocates and returns a duplicate of a string |

### Part 2 — Additional Functions

| Function | Description |
|----------|-------------|
| `ft_substr` | Extracts a substring from a string |
| `ft_strjoin` | Concatenates two strings into a new one |
| `ft_strtrim` | Removes characters from a set at both ends of a string |
| `ft_split` | Splits a string by a delimiter into an array of strings |
| `ft_itoa` | Converts an integer to its string representation |
| `ft_strmapi` | Applies a function to each char, returns new string |
| `ft_striteri` | Applies a function to each char in-place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by `\n` to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Part 3 — Linked List Functions

Uses the following structure defined in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Description |
|----------|-------------|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Adds a node at the beginning of the list |
| `ft_lstsize` | Returns the number of nodes in the list |
| `ft_lstlast` | Returns the last node of the list |
| `ft_lstadd_back` | Adds a node at the end of the list |
| `ft_lstdelone` | Frees a single node using a delete function |
| `ft_lstclear` | Frees all nodes and sets the list pointer to NULL |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

---

## Resources

### Documentation & References
- Livro: C Completo e Total.
- Bro Code YouTube Channel: https://www.youtube.com/watch?v=xND0t1pr3KY&t=22365s
- CS50 YouTube Channel: https://www.youtube.com/watch?v=UuIEbpQms8o&t=2533s
- [Linux man pages](https://man7.org/linux/man-pages/)
- `man` pages for each reimplemented function (e.g., `man 3 memcpy`)
- [Practicing - LeetCode](https://leetcode.com/)

### AI Usage

AI (Claude, ChatGPT and Leo AI) was used in this project **exclusively as a learning and understanding tool**, not to generate code to be submitted directly.

Specifically, AI was used for:
- **Conceptual explanations:** Understanding how functions like `ft_memmove`, `ft_split`, and `ft_bzero` work internally before implementing them.
- **Reviewing concepts:** Clarifying edge cases (e.g., `INT_MIN` in `ft_itoa`, `\0` handling in `ft_strchr`, overflow checks in `ft_calloc`).

NO AI CODE GENERATED WAS DIRECTLY SUBMITTED.  
All implementation were written and understood by me, cabrbosa.