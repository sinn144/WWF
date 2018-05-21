#include "00_header.h"

double WaveFun (double n,double m,double t,double x,double y)
{
    double length = 1.0;
    double tcon[2] = {1.0,1.0}; /* 各三角関数の係数 */
    double cvel=1.0;
    double alam = cvel*M_PI*(n*n+m*m)/length;
    double atau = M_PI/length;

    return (tcon[0]*cos(alam*t)+tcon[1]*sin(alam*t))*sin(n*atau*x)*sin(m*atau*y);
}

void StoreValue(FILE *fp,double div_times,double secx,double secy)
{
    // defined dif size
    double label[3];
    double del = 1.0 / div_times;

    for(size_t x = 0; x < (size_t)div_times; x++)
    {
        for(size_t y = 0; y < (size_t)div_times; y++)
        {
            label[0] = del*x;
            label[1] = del*y;
            label[2] = WaveFun(secx,secy,1.0,label[0],label[1]);
            DataWrite(fp,3,label);
        }
    }  
}

void DataWrite (FILE *fp,int data_num,double array[data_num])
{
    for(size_t i = 0; i < data_num; i++)
    {
        fprintf(fp,"%f ",array[i]);
    }   fprintf(fp,"\n");
}

void FileOpera(FILE *fp,double ddiv, int secx, int secy, int n,const char str[n])
{
    char fn[n];
    sprintf(fn, "%s.txt", str);
    fp = fopen(fn, "w");

    if (fp== NULL)
    {
        printf("Cannot open %s \n", fn);
        exit(1);
    }

    StoreValue(fp,ddiv,(double)secx,(double)secy);

    fclose(fp);
}