#include "00_header.h"

double WaveFun (double n,double t,double x)
{
    double length = 1.0;
    double tcon[2] = {1.0,1.0};
    double cvel=1.0;
    double alam = cvel*M_PI/length;
    double atau = M_PI/length;

    return (tcon[0]*cos(n*alam*t)+tcon[1]*sin(n*alam*t))*sin(n*atau*x);
}

void StoreValue(FILE *fp,double div_times,double sec)
{
    // defined dif size
    double label[2];
    double delx = 1.0 / div_times;

    for(size_t t = 0; t < (size_t)div_times; t++)
    {
        label[0] = delx*t;
        label[1] = WaveFun(sec,1.0,label[0]);
        DataWrite(fp,2,label);
    }  
}

void DataWrite (FILE *fp,int data_num,double array[data_num])
{
    for(size_t i = 0; i < data_num; i++)
    {
        fprintf(fp,"%f ",array[i]);
    }   fprintf(fp,"\n");
}

void FileOpera(FILE *fp,double ddiv, int sec, int n,const char str[n])
{
    char fn[n];
    sprintf(fn, "%s.txt", str);
    fp = fopen(fn, "w");

    if (fp== NULL)
    {
        printf("Cannot open %s \n", fn);
        exit(1);
    }

    StoreValue(fp,ddiv,(double)sec);

    fclose(fp);
}