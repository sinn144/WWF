#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoreValue(FILE *fp, int col, int I, int J, char data_label[10][I], double data[J][I]);
void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM);

int main()
{

    int N =10000;
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

    double str_data[ROW_MAX][COL_MAX];
    char str_data_label[10][COL_MAX];

    printf ("%d %d \n",ROW_MAX,COL_MAX);

    fseek(fp,0L,SEEK_SET);
    // ファイルの先頭に移動

    for (size_t col = 0; col < 4; col++)
    {
        StoreValue(fp, col, 26, 4, str_data_label, str_data);
        printf("%s \n", str_data_label[col]);
    }

    printf("%lf %s \n", str_data[0][2],str_data_label[0]);

    fclose(fp);
    return 0;
}

void StoreValue(FILE *fp,int col,int I,int J,char data_label[10][col],double data[J][col])
{
    // strtokを用いたデータ格納の簡略化
    char Temp[1000];
    fgets(Temp, sizeof(Temp), fp);
    
    strcpy(data_label[col], strtok(Temp,","));
    for(size_t c = 0; c < J; c++)
    {
        // sscanf(Temp,"%lf,%[^\n]",&data[col][c],Temp);
        data[col][c] = atof(strtok(NULL,","));
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