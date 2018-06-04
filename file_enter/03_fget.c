#include <stdio.h>
#include <string.h>

int main () 
{
    FILE *fp;
    char str[1000];

    if ((fp=fopen("./file_enter/02_data.txt","r"))==NULL) 
    {
        printf("err\n");
        return 1;
    }

    fgets (str,1000,fp);
    printf ("%s \n",str);

    return 0;
}