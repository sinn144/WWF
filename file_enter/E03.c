#include <stdio.h>
#include <math.h>

void DualMometum(int N,double data[4])
{
    // 引数 : data[4],*fp
    // 返値 : M,theta_0,lammda_0
    FILE *fps;
    if ((fps = fopen("./file_enter/10_culc.csv", "w")) == NULL)
    {
        printf("file is not exist\n");
        return 1;
    }
    double data[4] = {
        1900.0,
        -31543,
        -2298,
        5922};

    double M;
    double theta_0,lammda_0;

    M        = sqrt(data[1] * data[1] + data[2] * data[2] + data[3] * data[3]);
    theta_0  = 360 * atan(sqrt(data[3] * data[3] + data[2] * data[2]) / data[1]) / M_PI;
    lammda_0 = 360 * atan(data[3] / data[2]) / M_PI;

    fprintf(fps,"%d,%13.6lf,%11.6lf,%11.6lf \n",(int)data[0],M,theta_0,lammda_0);
    fclose(fps);
}