#include <stdio.h>
#include <stdlib.h>

int main (){
    FILE *fp ;
    if ((fp = fopen("./file_enter/02_data.txt", "r")) == NULL)
    {
        printf("file is not exist\n");
        return 1;
    }
    int i = 0;
    int N = 3;
    int M = 3;
    int ret;
    double data[N][M];

    while((ret=fscanf(fp,"%lf,%lf,%lf",&data[i][0],&data[i][1],&data[i][2])) != EOF){
        ++i;
        printf("a\n");
        if (i == 10) break;
    }

    printf("%lf\n",data[0][0]);

    fclose(fp);

    return 0;
}