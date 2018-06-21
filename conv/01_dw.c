#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    double eps = 8e-6;
    int count = 1;
    double n_pi = 4.0;
    double t_pi = 3.1416;
    FILE *fp;


    if ((fp = fopen("D01_data_lim.csv","w")) == NULL)
    {
        printf("error\n");
        exit(-1);
    }

    fprintf(fp,"%d,%lf\n", 0, n_pi);
    while(fabs(n_pi - t_pi) > eps)
    {
        n_pi += 4.0*pow(-1,(double)count)/(double)(1+2*count);
        // printf("%d %lf\n",count,n_pi); 
        fprintf(fp,"%d,%12.10lf\n",count,n_pi);
        count++ ;

        if(count % 10000 == 0) printf("%d\n",count);
    }

    printf("E N D ?\n");

    return 0;
}