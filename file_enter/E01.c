#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    int num[3][3];
    char str[1000];

    fgets(str,sizeof(str),stdin);

    for(size_t i = 0; i < 3; i++)
    {
        
        for(size_t j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0) 
                num[i][j] = (int)atof(strtok(str," "));
            else
                num[i][j] = (int)atof(strtok(NULL, " "));
        }
        
    }

    
    for(size_t i = 0; i < 9; i++)
    {
        printf("%2d ",num[i%3][i/3]);
    }

    return 0;
    
}