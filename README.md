# Pipex

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Build](https://img.shields.io/badge/build-Makefile-brightgreen.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Author](https://img.shields.io/badge/author-bsen-purple.svg)

## Description

Pipex is a project designed to replicate the behavior of shell pipes, specifically handling input/output redirection and executing two commands linked by a pipe. It allows users to chain two commands, passing the standard output of the first command as the standard input to the second command, all while handling file redirection from an input file and to an output file. This project is a foundational exercise in inter-process communication (IPC) and file descriptor manipulation in C, often encountered in the 42 school curriculum.

## ✨ Features

*   **Two-Command Piping:** Executes two user-specified commands, connecting their standard input/output via a pipe.
*   **File Redirection:** Handles input from a specified file (`infile`) for the first command and redirects the final output of the second command to an output file (`outfile`).
*   **Path Resolution:** Searches for command executables within the system's `PATH` environment variable.
*   **Error Handling:** Includes basic error management for file operations, process creation, and command execution failures.
*   **Custom Library (`libft`):** Utilizes a custom C library (`libft`) for various utility functions, showcasing modular development.

## 📚 Tech Stack

*   **Language:** C
*   **Compiler:** `gcc`
*   **Build System:** `Makefile`
*   **Core Libraries:**
    *   `unistd.h` (for `fork`, `pipe`, `execve`, `dup2`, `access`, `close`, `waitpid`)
    *   `fcntl.h` (for `open` flags)
    *   `stdlib.h` (for `exit`, `malloc`, `free`)
    *   `stdio.h` (for `perror`)
*   **Custom Utilities:** `libft` (a comprehensive C utility library)

## 🚀 Installation

To get a local copy up and running, follow these simple steps.

1.  **Clone the repository:**
    ```bash
    git clone git@github.com:bsen0/Pipex.git
    cd Pipex/pip
    ```
2.  **Build the project:**
    ```bash
    make
    ```
    This will compile the `pipex` executable and its dependencies, including the `libft` static library.

## ▶️ Usage

The `pipex` program takes four arguments: an input file, the first command (with its arguments in quotes), the second command (with its arguments in quotes), and an output file.

**Syntax:**

```bash
./pipex <infile> "<cmd1>" "<cmd2>" <outfile>
```

**Example:**

Let's say you have a file `input.txt` with some text. You want to use `grep` to find lines containing "hello" and then use `wc -l` to count those lines, saving the result to `output.txt`.

1.  Create `input.txt`:
    ```bash
    echo "hello world" > input.txt
    echo "goodbye world" >> input.txt
    echo "another hello" >> input.txt
    ```

2.  Run `pipex`:
    ```bash
    ./pipex input.txt "grep hello" "wc -l" output.txt
    ```

After execution, `output.txt` will contain:

```
2
```

This demonstrates that `grep hello` read from `input.txt`, its output was piped to `wc -l`, and `wc -l`'s output was written to `output.txt`.

## 🤝 Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## 📝 License

Distributed under the MIT License.
*(Note: A `LICENSE` file is not explicitly provided in the project files. It is recommended to add one to clarify licensing terms.)*