#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char * str)
{
    char buff[255];
    int j=0;
    for(int i=0; i<strlen(str); i++)
    {
        if(isdigit(str[i]))
        {
            // nothing
        }
        else if(str[i] == '+' || str[i] == '-')
        {
            buff[j] = str[i];
            j++;
            buff[j] = str[i];
            j++;
        }
        else if(str[i] == 'p' && str[i+1] == 'h')
        {
           buff[j] = 'f';
           j++;
           i++;
        }
        else
        {
            buff[j] = str[i];
            j++;
        }
    }
    printf("%s", buff);
}

int main()
{
    char lol[100];
    //fgets(lol, 255, stdin);
    gets(lol);

    func(lol);

    return 0;
}
