#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoreValue(FILE *fp, int col, int I, int J, double data[I][col]);
void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM);

int main()
{

    int N =10000;
    char str[N];
    FILE *fp;
    int counter = 0;
    int ROW_MAX=0;
    int COL_MAX=0;

    if ((fp = fopen("./file_enter/02_data.csv", "r"))== NULL)
    {
        printf("file is not exist\n");
        return 1;
    }

    MtrxSzCulc(fp, &ROW_MAX, &COL_MAX);

    double str_data[ROW_MAX][COL_MAX];

    printf ("%d %d \n",ROW_MAX,COL_MAX);

    fseek(fp,0L,SEEK_SET);

    // ファイルの先頭に移動

    for (size_t col = 0; col < ROW_MAX - 1; col++)
    {
        StoreValue(fp, col, COL_MAX, ROW_MAX ,str_data);
    }

    printf("%lf %lf %lf %lf %lf  \n", str_data[0][0], str_data[0][1], str_data[0][2], str_data[1][0], str_data[2][0]);

    fclose(fp);
    return 0;
}

void StoreValue(FILE *fp,int col,int I,int J,double data[I][col])
{
    // strtokを用いたデータ格納の簡略化

    char Temp[1000];
    fgets(Temp, sizeof(Temp), fp);
    data[0][col] = atof(strtok(Temp,","));
    for(size_t c = 1; c < J; c++)
    {
        // sscanf(Temp,"%lf,%[^\n]",&data[col][c],Temp);
        data[c][col] = atof(strtok(NULL,","));
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