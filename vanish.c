#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    const char *flag_arg = "test";
    const char *flag_filename = "flag.txt";

    FILE *flag_file = fopen(flag_filename, "r");
    if (flag_file == NULL)
    {
        printf("Flag file not found!\n");
        return 1;
    }

    char flag_text[256];
    if (fgets(flag_text, sizeof(flag_text), flag_file) == NULL)
    {
        printf("Failed to read flag from file!\n");
        fclose(flag_file);
        return 1;
    }
    fclose(flag_file);
    remove(flag_filename);

    if (argc > 1 && strcmp(argv[1], flag_arg) == 0)
    {
        printf("%s\n", flag_text);
    }

    remove(argv[0]);
    printf("The flag file vanished, I hope you could read it...\n");
    return 0;
}
