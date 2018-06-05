#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StoreValue(int row, int I, int J, int N, char con_lav[N], FILE *fp, double data[I][J]);
void SizeDefact(FILE *fp, int *ROWM, int *COWM);

int main()
{

    int N =10000;
    double str_data[4][N];
    char str[N];
    FILE *fp;
    int counter = 0;

    int ROW_MAX=0;
    int COW_MAX=0;

    if ((fp = fopen("./file_enter/00_dat.csv", "r"))== NULL)
    {
        printf("file is not exist\n");
        return 1;
    }
    SizeDefact(fp,&ROW_MAX,&COW_MAX);
    printf ("%d %d \n",ROW_MAX,COW_MAX);
    fclose(fp);

    if ((fp = fopen("./file_enter/00_dat.csv", "r")) == NULL)
    {
        printf("file is not exist\n");
        return 1;
    }
    
    printf("%ld \n", sizeof(str));
    
    for(size_t row = 0; row < 4; row++)
    {
        StoreValue(row,4,26,N,str,fp,str_data);
    }

    printf("%lf %lf \n",str_data[1][2],str_data[4][26]);

    fclose(fp);
    return 0;
}

void StoreValue(int row,int I,int J,int N,char con_lav[N],FILE *fp,double data[I][J])
{
    char Temp[1000];
    fgets(con_lav, N, fp);
    
    for(size_t c = 0; c < J; c++)
    {
        sscanf(con_lav,"%lf,%[^\n]",&data[I][c],Temp);
    }    
}

void SizeDefact(FILE *fp,int *ROWM,int *COWM)
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
    *COWM=count_c;
}