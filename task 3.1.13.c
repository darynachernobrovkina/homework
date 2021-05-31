#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{

    char str[100];
    int len;
    bool unsymmetrical=false;
    printf("Enter string to check: ");
    gets(str);
    len = strlen(str);
    for(int i=0; i < len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            unsymmetrical = true;
            break;
        }
    }

    if(unsymmetrical)
        {
            printf("String is unsymmetrical");
        }
        else
        {
            printf("String is symmetrical");
        }

    return 0;
}
