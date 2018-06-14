#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoreValue(FILE *fp, int col, int I, int J, char data_label[][col], double data[I][col]);
void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM);

int main()
{

    int N =10000;
    char str[N];
    FILE *fp;
    int counter = 0;
    int ROW_MAX=0;
    int COL_MAX=0;

    if ((fp = fopen("./file_enter/02_data.txt", "r"))== NULL)
    {
        printf("file is not exist\n");
        return 1;
    }

    MtrxSzCulc(fp, &ROW_MAX, &COL_MAX);

    double str_data[ROW_MAX][COL_MAX];
    char str_data_label[10][COL_MAX];

    printf ("%d %d \n",ROW_MAX,COL_MAX);

    fseek(fp,0L,SEEK_SET);

    // ファイルの先頭に移動

    for (size_t col = 0; col < ROW_MAX - 1; col++)
    {
        StoreValue(fp, col, COL_MAX, ROW_MAX , str_data_label, str_data);
        printf("str_data_label[%ld] = %s \n",col, str_data_label[col]);
    }

    printf("test : %lf %s \n", str_data[0][2],str_data_label[0]);

    
    // for(size_t i = 0; i < ROW_MAX-1; i++)
    // {
        
    //     for(size_t j = 0; j < COL_MAX - 2; i++)
    //     {
    //         printf("%lf ",str_data[i][j]);
    //     }printf("\n");
        
    // }
    
    // printf("a : %lf \n",str_data[0][1]);

    fclose(fp);
    return 0;
}

void StoreValue(FILE *fp,int col,int I,int J,char data_label[][col],double data[I][col])
{
    // strtokを用いたデータ格納の簡略化

    char Temp[1000];
    fgets(Temp, sizeof(Temp), fp);
    // printf("%s\n",Temp);
    
    // for(size_t i = 0; i < 5; i++)
    // {
    //     printf("%c \n",Temp[i]);
    // }
    

    strcpy(data_label[col], strtok(Temp,","));
    // printf("data_label[%d] = %s \n", col, strtok(Temp, ",")); /* カンマは外せれていた… */

    for(size_t c = 0; c < J-1; c++)
    {
        // sscanf(Temp,"%lf,%[^\n]",&data[col][c],Temp);
        char *str2 = strtok(NULL, ",");
        printf("%s %lf \n",str2, atof(str2));
        // Caracter Pointer　が返されないといけない　メモリーの使い方の違い
        // 最後の改行
    }
    // for (size_t c = 0; c < J - 1; c++)
    // {
    //     // sscanf(Temp,"%lf,%[^\n]",&data[col][c],Temp);
    //     printf("%lf ",data[c][col]);
    // }printf("\n");
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