# Vanishing C Program

This is a C program designed for CTF (Capture The Flag) competitions. It provides a way to display a flag by running a program with a specific argument. If the argument provided is correct, it displays the flag. The program then removes itself and the flag regardless if an argument was provided or correct, giving the player only one chance.

This should **only** be used for bonus flags as it effectively removes any other means of acquiring the flag (unless the box is rooted and the `flag.txt` is read **before** running the binary).

## Setup

1. Ensure you have a C compiler installed on your system (e.g., GCC).

2. Clone or download the repository containing this program.

    ```shell
    git clone https://github.com/tom-johnsen/vanish.git
    cd vanish
    ```

    ```shell
    wget "https://github.com/tom-johnsen/vanish/archive/refs/heads/master.zip"
    unzip master.zip
    cd vanish
    ```

3. Change the `flag_arg` inside vanish.c, remember to leave a hint for the player elsewhere on the box.

    ```c
    const char *flag_arg = "Sup3R_S3cR3T_aRgUm3Nt";
    ```

    The argument *may* contain spaces, but the player **must** use `./vanish "multiple arguments"` syntax and not `./vanish multiple arguments` then. It is recommended to not use spaces to avoid misunderstandings.

4. Compile the program:

    ```shell
    gcc vanish.c -o vanish
    ```

    If you are compiling the binary outside of the box move it into the box now.

5. Create the `flag.txt` file in the same directory as the binary and populate it with the flag (max 256 chars).

6. Set the ownership and permissions for the `flag.txt` and `vanish` binary:

    ```shell
    sudo chown root:root flag.txt vanish
    sudo chmod 400 flag.txt && sudo chmod 4701 vanish
    ```

7. You are now staged and ready for players to run the box.

## During gameplay

1. When the player executes the compiled program, one of two things happens:

    ```shell
    ./vanish wrong_or_no_argument   # The flag is NOT displayed.
    ./vanish correct_argument       # The flag IS displayed.
    ```

2. The binary and flag.txt is now gone, regardless if the flag was displayed or not.

## License

This program is released under the [MIT License](LICENSE).
