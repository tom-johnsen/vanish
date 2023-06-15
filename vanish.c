#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[] = __FILE__;
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Error opening self!\n");
        return 1;
    }

    fclose(file);
    int result = remove(filename);

    if (result == 0)
    {
        printf("I'm gone!!\n");
    }
    else
    {
        printf("Something prevented me from vanishing!\n");
    }

    return 0;
}
