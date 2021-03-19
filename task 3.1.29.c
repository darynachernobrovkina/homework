#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{

    char str[100], without[100];
    int len, start_index;
    bool unsymmetrical=false;
    printf("Enter string to check: ");
    gets(str);
    len = strlen(str);
    for(int i=0; i < len/2; i++)
    {
        if(str[i] != str[len-i-1])
        {
            unsymmetrical = true;
            start_index = i;
            break;
        }
    }
    int j=0;
    for(int i=start_index; i < len - start_index; i++)
    {
        without[j] = str[i];
        j++;
    }

    printf("Without symmetry: %s", without);
    return 0;
}
