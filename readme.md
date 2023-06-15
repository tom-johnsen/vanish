# Vanishing C Program

This is a simple C program that removes itself when executed. Upon running the program, it opens its own binary, truncates it, and then deletes the file from the system. This leads to the program "vanishing" after execution.

## Usage

1. Ensure you have a C compiler installed on your system (e.g., GCC).
2. Clone or download the repository containing this program.
3. Compile the program using the following command:

    ```shell
    gcc vanish.c -o vanish
    ```

4. Execute the compiled program:

    ```shell
    ./vanish
    ```

## Explanation

The program uses the `fopen` function to open its own binary in write mode. If the file is successfully opened, it is immediately closed using `fclose`. Then, the program attempts to remove the file using the `remove` function.

If the removal operation succeeds, the program prints the message "I'm gone!!" to the console, indicating that the file has been deleted. Otherwise, if the removal fails, it prints "Something prevented me from vanishing!".

This program serves as an illustrative example and does not have any practical use. It is primarily meant for educational or entertainment purposes.

## License

This program is released under the [MIT License](LICENSE).
