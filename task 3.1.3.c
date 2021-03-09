#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void func(char * str)
{
    char buff[255];
    int j=0, ind_start;
    bool found=false;
    for(int i=0; i<strlen(str); i++)
    {
        if(str[i]== '(' && !found)
        {
            found = true;
        }
        if(str[i] == ')' && found)
        {
            found = false;
            i++;
        }
        if(!found)
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
