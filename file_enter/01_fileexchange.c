#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // int N;
    // double str_data[4][N];
    char str[1000];
    char *tor;
    FILE *fp;
    int counter = 1;

    printf("a \n");
    fp = fopen("00_dat.csv","r");
    if(fp==NULL)
    {
        printf("file is not exist\n");
        return 1;
    }

    fscanf(fp,"%s",str);
    printf("%s",str);
    tor = strtok(str, ",");
    while (tor != NULL)
    {
        counter ++;
        printf("%s",tor);
        tor = strtok(NULL, ",");
    }

    // バッファオーバーフロー発生・確認が必要

    printf("%d datas\n",counter);

    fclose(fp);

    return 0;
}

