#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "jan";
    char *str1;

    str1 = (char *)malloc(4);
    int i = 0;
    while (str[i])
    {
        str1[i] = str[i];
        i++;
    }
    str1[i] = '\0';
    str1[0] = 'L';
    printf("%s\n", str1);
    return (0);
}