#include "00_main_csv.h"

int main()
{
    int N =2000;
    int ROW_MAX=0;
    int COL_MAX=0;
    char str[N];
    FILE *fp;

    if ((fp = fopen("./file_enter/data/D00_dat.csv", "r"))== NULL)
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

    for (size_t col = 0; col < COL_MAX; col++)
    {
        StoreValue(fp, col, COL_MAX, ROW_MAX , str_data_label, str_data);
    }

    printf("test : %lf %s \n", str_data[20][0],str_data_label[2]);    
    fclose(fp);

    DipoleMometum(COL_MAX,ROW_MAX,str_data);

    return 0;
}