#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoreValue(int row, int I, int J, int N,  FILE *fp, double data[I][J]);
void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM);

int main()
{

    int N =10000;
    double str_data[4][N];
    char str[N];
    FILE *fp;
    int counter = 0;
    int ROW_MAX=0;
    int COL_MAX=0;

    if ((fp = fopen("./file_enter/00_dat.csv", "r"))== NULL)
    {
        printf("file is not exist\n");
        return 1;
    }

    MtrxSzCulc(fp, &ROW_MAX, &COL_MAX);

    printf ("%d %d \n",ROW_MAX,COL_MAX);

    fseek(fp,0L,SEEK_SET);
    // ファイルの先頭に移動

    for (size_t row = 0; row < 4; row++)
    {
        StoreValue(row,4,26,N,fp,str_data);
    }

    printf("%lf %lf \n", str_data[1][2], str_data[4][26]);

    fclose(fp);
    return 0;
}

void StoreValue(int row,int I,int J,int N,FILE *fp,double data[I][J])
{
    // どのようにしてデータ格納しようか…
    char Temp[1000];
    fgets(Temp, N, fp);
    
    for(size_t c = 0; c < J; c++)
    {
        sscanf(Temp,"%lf,%[^\n]",&data[I][c],Temp);
    }    
}

void MtrxSzCulc(FILE *fp,int *ROWM,int *COLM)
{
    int count,count_c;
    char *tor;
    char str[1000];

    count_c=0;

    while(fgets(str, 1000, fp)!=NULL){
        count=0;
        tor = strtok(str, ",");
        
        while (tor != NULL)
        {
            count++;
            tor = strtok(NULL, ",");
        }
        if(count>*ROWM)
        {
            *ROWM=count;
        }
        count_c++;
    }
    *COLM=count_c;
}