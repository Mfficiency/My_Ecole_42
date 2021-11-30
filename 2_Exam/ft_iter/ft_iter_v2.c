#include <stdio.h>
#include <unistd.h>

void ft_iter(char *str1, char *str2){
    int used[255];
    int i;

    i = 0;
    while (i < 255)
    {
        used[i++] = 0;
    }
    while (*str2)
    {
        if (!used[(unsigned char)*str2])
        {
            used[(unsigned char)*str2] = 1;
        }
        str2++;
    }
    while (*str1)
    {
        if (used[(unsigned char)*str1] == 1)
        {
            used[(unsigned char)*str1] = 2;
            write(1, str1, 1);
        }
        str1++;
    }
    
    
}