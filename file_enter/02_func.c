#include "00_main_csv.h"

void StoreValue(FILE *fp, int col, int I, int J, char data_label[][I], double data[J][I])
{
    char Temp[1000];
    double num;
    fgets(Temp, sizeof(Temp), fp);

    strcpy(data_label[col], strtok(Temp, ","));

    for (size_t c = 0; c < J - 1; c++)
    {
        char *str2 = strtok(NULL, ",\n");
        num = atof(str2);
        data[c][col] = num;
    }
}

void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM)
{
    int count, count_c;
    char *tor;
    char str[1000];

    count_c = 0;

    while (fgets(str, 1000, fp) != NULL)
    {
        count = 0;
        tor = strtok(str, ",");

        while (tor != NULL)
        {
            count++;
            tor = strtok(NULL, ",");
        }
        if (count > *ROWM)
        {
            *ROWM = count;
        }
        count_c++;
    }
    *COLM = count_c;
}

void DipoleMometum(int P, int N, double data[N][P])
{
    FILE *fps;
    if ((fps = fopen("./file_enter/data/D10_culc.csv", "w")) == NULL)
    {
        printf("file is not exist\n");
        exit(-1);
    }

    double M;
    double theta_0, lammda_0;

    for (size_t L = 0; L < N - 1; L++)
    {
        printf("%lf %lf %lf \n", data[L][1], data[L][2], data[L][3]);
        M = sqrt(data[L][1] * data[L][1] + data[L][2] * data[L][2] + data[L][3] * data[L][3]);
        theta_0 = 360 * atan(sqrt(data[L][3] * data[L][3] + data[L][2] * data[L][2]) / data[L][1]) / M_PI;
        lammda_0 = 360 * atan(data[L][3] / data[L][2]) / M_PI;

        fprintf(fps, "%4d, %12.6lf, %9.6lf, %9.6lf \n", (int)data[L][0], M, theta_0, lammda_0);
    }

    fclose(fps);
}