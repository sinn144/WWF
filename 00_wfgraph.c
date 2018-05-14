#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void DataWrite();
double WaveFun(double);

int main () {
    

    return 0;
}

void FileOpen(double a, int n, char str[n])
{
    char fn[n];
    FILE *fp;
    sprintf(fn, "%s.txt", str);
    fp = fopen(fn, "w");

    if (fp== NULL)
    {
        printf("Cannot open %s \n", fn);
        exit(1);
    }
}

void DataWrite (FILE *fp,int DataNum,double Value[DataNum])
{
    for(size_t i = 0; i < DatanNum; i++)
    {
        fprintf(fp,"%d ",Value[i]);
    }   fprintf(fp,"\n");
}

void StoreValue(FILE *fp,fpint sec,double DivTimes,double &label[2][Divtime])
{
    // defined dif size
    double delx = 1.0/DivTimes;

    for(size_t t = 0; t < (size_t)DivTimes; t++)
    {
        label[0][t] = delx*t;
        label[1][t] = WaveFun(sec,1.0,label[0]);
        DataWrite(fp,1,label[][t]);
    }
    
}

double WaveFun (double n,double t,double x)
{
    double Length = 1.0;
    double TCon[1] = {1.0,1.0};
    double CVel=1.0;
    double Alam = CVel*M_PI/Length;
    double Atau = M_PI/Length;

    return (TCon[0]*cos(n*Alam*t)+TCon[1]*sin(n*Alam*t))*sin(n*Atau*x);
}